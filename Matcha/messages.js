import { ObjectID } from 'mongodb';
import _ from 'lodash';
import { log } from 'console';

import mongoConnectAsync from './mongo';
// import { getAge, getToday } from './lib';

const postMessage = (req, res) => {
  const { username, userID, firstname } = req.session;
  const { toID, message } = req.body;

  mongoConnectAsync(res, async (Users) => {
    const my = await Users.findOne({ 'account.username': username });
    const these = await Users.findOne({ _id: ObjectID(toID) });

    if (my && these) {
      const myMessages = _.get(my, 'messages', {});
      // const myNotifs = _.get(my, 'notifications', []);
      const theseMessages = _.get(these, 'messages', {});
      const theseNotifs = _.get(these, 'notifications', []);

      myMessages[these.account.username].discussion.push({
        type: 'sent',
        date: Date.now(),
        message,
      });

      theseMessages[username].discussion.push({
        type: 'received',
        date: Date.now(),
        message,
      });

      theseNotifs.splice(5);
      theseNotifs.unshift({
        type: 'message',
        date: Date.now(),
        userID,
        firstname,
      });

      Users.updateOne({ 'account.username': username }, { $set: { messages: myMessages } });
      Users.updateOne({ _id: these._id }, { $set: { messages: theseMessages, notifications: theseNotifs } });

      res.send({ done: 'success' });
    } else res.end();
  });
};

const getMessages = (req, res) => {
  const { username } = req.session;

  mongoConnectAsync(res, async (Users) => {
    const user = await Users.findOne({ 'account.username': username });

    if (user) {
      res.send({
        done: 'success',
        messages: _.get(user, 'messages', []),
        photo: _.get(user, 'photos.profile', 'http://fakeimg.pl/300x300/'),
      });
    } else res.send({ done: 'User has not messages yet' });
  });
};

const renderPage = (req, res) => {
  const { username } = req.session;

  mongoConnectAsync(res, async (Users) => {
    const user = await Users.findOne({ 'account.username': username });

    if (user) {
      res.render('messages', {
        isNotHome: true,
        title: 'Matcha - Messages',
        bodyPage: 'messages-body',
        user,
        id: user._id,
        login: _.capitalize(_.get(req.session, 'firstname', 'profile')),
      });
    } else {
      log('Error: User not found, redirect to login page.');
      res.redirect('/');
    }
  });
};

export {
  postMessage,
  getMessages,
  renderPage,
};
