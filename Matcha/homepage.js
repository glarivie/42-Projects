import hash from 'mhash';
import _ from 'lodash';
import { ObjectID } from 'mongodb';

import mongoConnectAsync from './mongo';
import { resLog, sendEmail } from './lib';
import fixtures from './fixtures';

const addFixtures = res => {
  mongoConnectAsync(res, async (Users) => {
    const count = await Users.find({}).count();

    if (_.isEqual(count, 1)) {
      fixtures.forEach(async (user) => {
        Users.insertOne(user);
      });
    }
  });
};

const renderHome = (req, res) => {
  addFixtures(res);

  res.render('home', {
    isNotHome: false,
    title: 'Matcha - Home',
    bodyPage: 'home-body',
  });
};

const logout = (req, res) => {
  req.session.destroy((err) => {
    if (!err) res.redirect('/');
  });
};

const setNewPassword = (req, res) => {
  const { id, password } = req.params;

  mongoConnectAsync(res, async (Users) => {
    const user = await Users.findOne({ _id: ObjectID(id) });

    if (!user) res.end();

    Users.updateOne({ _id: ObjectID(id) }, {
      $set: { 'account.password': hash('whirlpool', password) },
    }, (err) => {
      if (!err) resLog(res, `${user.account.username} has update his password`, { done: 'success' });
    });
  });
};

const resetPassword = (req, res) => {
  const { username, password } = req.params;

  mongoConnectAsync(res, async (Users) => {
    const user = await Users.findOne({ 'account.username': username });

    if (user && user.account.password === password) {
      res.render('reset', {
        isNotHome: false,
        title: 'Matcha - Reset Password',
        bodyPage: 'reset-body',
        id: user._id,
      });
    } else res.send('404: Page not found');
  });
};

const sendResetEmail = (req, res) => {
  const { email } = req.params;

  mongoConnectAsync(res, async (Users) => {
    const user = await Users.findOne({ 'account.mail': email });

    if (!user) { // Error handler
      resLog(res, 'Mail provided don\'t match with existing user');
    } else {
      const { username, password } = user.account;
      const magicLink = `http://localhost:3333/reset-password/${username}/${password}`;
      const text = `<p>Follow <a href="${magicLink}" target="_blank">this link</a> to reset your password</p>`;
      const subject = '✔ Let\'s reset your password';

      sendEmail(email, text, subject);
      resLog(res, 'Message sent', { done: 'success' });
    }
  });
};

const addNewUser = (req, res) => {
  const { username, mail, password, firstname, lastname, birthdate } = req.body;

  mongoConnectAsync(res, async (Users) => {
    const usernameCount = await Users.find({ 'account.username': username }).count();
    const mailCount = await Users.find({ 'account.mail': mail }).count();

    if (usernameCount > 0) { // Error handler
      resLog(res, 'User already exist', { error: 'login' });
    } else if (mailCount > 0) {
      resLog(res, 'Mail already exist', { error: 'mail' });
    } else {
      const { ops, insertedCount } = await Users.insertOne({
        account: { username, password: hash('whirlpool', password), mail },
        infos: { firstname, lastname, birthdate },
      });

      if (insertedCount > 0 && ops[0]) {
        req.session.username = ops[0].account.username;
        req.session.firstname = ops[0].infos.firstname;
        req.session.userID = ops[0]._id;
        resLog(res, 'Success: User added', { redirect: '/profile' });
      } else {
        resLog(res, 'Error: User not added');
      }
    }
  });
};

const connectUser = (req, res) => {
  const { username, password } = req.body;

  mongoConnectAsync(res, async (Users) => {
    const user = await Users.findOne({ 'account.username': username });

    if (!user) { // Error handler
      resLog(res, 'Login error, user not found.', { error: 'login' });
    } else if (user.account.password !== hash('whirlpool', password)) {
      resLog(res, 'Login error, bad password.', { error: 'password' });
    } else {
      req.session.username = _.get(user, 'account.username', '');
      req.session.firstname = _.get(user, 'infos.firstname', '');
      req.session.userID = user._id;
      resLog(res, `User ${username} found. Access granted !`, { redirect: '/profile' });
    }
  });
};

export {
  renderHome,
  setNewPassword,
  resetPassword,
  sendResetEmail,
  addNewUser,
  connectUser,
  logout,
};
