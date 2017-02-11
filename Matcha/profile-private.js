import { satelize } from 'satelize';
import { ObjectID } from 'mongodb';
import _ from 'lodash';
import { log } from 'console';

import mongoConnectAsync from './mongo';
import { getAge, /* getToday, */ validateEmail, validateUser, validateInterest } from './lib';

const getIP = require('external-ip')();
const geocoder = require('node-geocoder')('google');

const deletePhoto = (req, res) => {
  const { username } = req.session;

  mongoConnectAsync(res, async (Users) => {
    const user = await Users.findOne({ 'account.username': username });
    const index = parseInt(_.get(req.params, 'index', -1), 10);

    if (user) {
      if (!_.isUndefined(_.get(user, `photos.photo${index}`, undefined))) {
        const myObject = {};
        _.set(myObject, `photos.photo${index}`, 'http://fakeimg.pl/300x300/');
        _.set(myObject, 'account.hasProfilePicture', false);

        Users.updateOne({ 'account.username': username }, {
          $set: myObject,
        }, (err) => {
          if (!err) res.send({ done: 'success' });
          else res.send({ fail: `no photo to delete in index ${index}` });
        });
      } else res.send({ fail: `no photo to delete in index ${index}` });
    }
  });
};

const getPhoto = (req, res) => {
  const { id } = req.params;
  const index = parseInt(_.get(req.params, 'index', -1), 10);

  mongoConnectAsync(res, async (Users) => {
    const user = await Users.findOne({ _id: ObjectID(id) });
    const key = _.isEqual(index, 'profile') ? 'profile' : `photo${index}`;

    if (user) {
      res.send({
        done: 'success',
        request: index,
        photo: _.get(user, `user.photos.${key}`),
      });
    } else res.send({ fail: `no photo set in index ${index}` });
  });
};

const setProfile = (req, res) => {
  const { username } = req.session;
  const index = parseInt(_.get(req.params, 'index', -1), 10);

  mongoConnectAsync(res, async (Users) => {
    const user = await Users.findOne({ 'account.username': username });
    const key = `photo${index}`;

    if (user) {
      Users.updateOne({ 'account.username': username }, {
        $set: {
          'photos.profile': user.photos[key],
          'account.hasProfilePicture': true,
        },
      }, (err) => {
        if (!err) res.send({ done: 'success', photo: user.photos[key] });
        else res.send({ fail: `no photo set in index ${index}` });
      });
    } else res.send({ fail: `no photo set in index ${index}` });
  });
};

const uploadPhoto = (req, res) => {
  const { username } = req.session;
  const { photo, index } = req.body;
  const myObject = {};
  _.set(myObject, `photos.photo${index}`, photo);

  mongoConnectAsync(res, async (Users) => {
    const user = await Users.findOne({ 'account.username': username });

    if (user) {
      Users.updateOne({ 'account.username': username }, {
        $set: myObject,
      }, (err) => {
        if (!err) res.send({ done: 'success' });
        else res.send({ done: 'fail' });
      });
    } else res.send({ done: 'fail' });
  });
};

const setLast = (req, res) => {
  const { username } = req.session;
  const date = Date.now();

  mongoConnectAsync(res, async (Users) => {
    Users.updateOne({ 'account.username': username }, {
      $set: { last: date },
    }, (err) => {
      if (!err) res.send({ done: 'success', date });
      else res.send({ done: 'fail' });
    });
  });
};

const getCover = (req, res) => {
  const { id } = req.params;

  mongoConnectAsync(res, async (Users) => {
    const user = await Users.findOne({ _id: ObjectID(id) });

    if (user) {
      if (!_.isUndefined(_.get(user, 'photos.cover', undefined))) {
        res.send({ done: 'success', cover: _.get(user, 'photos.cover', 'http://fakeimg.pl/890x310/') });
      } else res.send({ done: 'success', cover: 'http://fakeimg.pl/890x310/' });
    } else res.send({ fail: 'no cover set' });
  });
};

const uploadCover = (req, res) => {
  const { username } = req.session;
  const { cover } = req.body;

  mongoConnectAsync(res, async (Users) => {
    const user = await Users.findOne({ 'account.username': username });

    if (user) {
      Users.updateOne({ 'account.username': username }, {
        $set: { 'photos.cover': cover },
      }, (err) => {
        if (!err) res.send({ done: 'success' });
        else res.send({ done: 'fail' });
      });
    }
  });
};

const listInterets = (req, res) => {
  mongoConnectAsync(res, async (Users) => {
    const request = await Users.find({}, { interests: 1 });
    const list = [];

    request.each((err, user) => {
      if (user !== null) {
        const tab = _.get(user, 'interests', []);
        for (let index = 0; index < tab.length; index++) {
          list.push(tab[index]);
        }
      } else res.send({ list: _.uniq(list) });
    });
  });
};

const addInterest = (req, res) => {
  const { username } = req.session;
  const { newInterest } = req.body;

  if (!validateInterest(newInterest)) res.send({ done: 'fail' });
  else {
    mongoConnectAsync(res, async (Users) => {
      const user = await Users.findOne({ 'account.username': username });

      if (!user) res.send({ done: 'fail' });
      else {
        const interests = _.get(user, 'interests', []);

        if (interests.indexOf(newInterest.toLowerCase()) < 0) {
          interests.push(newInterest.toLowerCase());

          Users.updateOne({ 'account.username': username }, {
            $set: { interests },
          }, (err) => {
            if (!err) res.send({ done: 'success', interests });
            else res.send({ done: 'fail' });
          });
        } else res.send({ done: 'fail' });
      }
    });
  }
};

const deleteInterest = (req, res) => {
  const { username } = req.session;
  const toDelete = req.body.delete;

  mongoConnectAsync(res, async (Users) => {
    const user = await Users.findOne({ 'account.username': username });

    if (user && user.interests) {
      const indexToDelete = user.interests.indexOf(toDelete);

      if (indexToDelete > -1) user.interests.splice(indexToDelete, 1);

      Users.updateOne({ 'account.username': username }, {
        $set: { interests: user.interests },
      }, (err) => {
        if (!err) res.send({ done: 'success' });
        else res.send({ done: 'fail' });
      });
    } else res.end();
  });
};

const editOrientation = (req, res) => {
  const { username } = req.session;
  const { orientation } = req.body;

  mongoConnectAsync(res, async (Users) => {
    if (orientation === 'Straight' || orientation === 'Gay' || orientation === 'Bisexual') {
      Users.updateOne({ 'account.username': username }, {
        $set: { 'infos.sex': orientation },
      }, (err) => {
        if (!err) res.send({ done: 'success' });
        else res.send({ done: 'fail' });
      });
    } else res.send({ done: 'fail' });
  });
};

const editSex = (req, res) => {
  const { username } = req.session;
  const { sex } = req.body;

  mongoConnectAsync(res, async (Users) => {
    if (sex === 'Male' || sex === 'Female' || sex === 'Other') {
      Users.updateOne({ 'account.username': username }, {
        $set: { 'infos.sex': sex },
      }, (err) => {
        if (!err) res.send({ done: 'success' });
        else res.send({ done: 'fail' });
      });
    } else res.send({ done: 'fail' });
  });
};

const editMail = (req, res) => {
  const { username } = req.session;
  const { mail } = req.body;

  mongoConnectAsync(res, async (Users) => {
    if (validateEmail(mail)) {
      Users.updateOne({ 'account.username': username }, {
        $set: { 'account.mail': mail },
      }, (err) => {
        if (!err) res.send({ done: 'success' });
        else res.send({ done: 'fail' });
      });
    } else res.send({ done: 'fail' });
  });
};

const editName = (req, res) => {
  const { username } = req.session;
  const { lastname, firstname } = req.body;

  mongoConnectAsync(res, async (Users) => {
    if (validateUser(firstname) && validateUser(lastname)) {
      Users.updateOne({ 'account.username': username }, {
        $set: {
          'infos.firstname': firstname,
          'infos.lastname': lastname,
        },
      }, (err) => {
        if (!err) res.send({ done: 'success' });
        else res.send({ done: 'fail' });
      });
    } else res.send({ done: 'fail' });
  });
};

const editBiography = (req, res) => {
  const { username } = req.session;
  const { biography } = req.body;

  mongoConnectAsync(res, async (Users) => {
    Users.updateOne({ 'account.username': username }, {
      $set: { 'infos.biography': biography } }, (err) => {
        if (!err) res.send({ done: 'success' });
      });
  });
};

const getAddress = (req, res) => {
  const { username } = req.session;

  geocoder.reverse({
    lat: req.body.latitude,
    lon: req.body.longitude,
  }, (err, loc) => {
    res.send({ address: loc[0].formattedAddress });

    mongoConnectAsync(res, async (Users) => {
      Users.updateOne({ 'account.username': username }, {
        $set: {
          location: {
            country: loc[0].country,
            city: loc[0].city,
            address: loc[0].formattedAddress,
            latitude: req.body.latitude,
            longitude: req.body.longitude,
          },
        },
      }, (err) => {
        if (!err) log('Location updated');
      });
    });
  });
};

const getCity = (req, res) => {
  const { username } = req.session;
  const latParis = 48.866667;
  const lngParis = 2.333333;

  getIP((err, ip) => {
    satelize({ ip }, (err, payload) => {
      if (err) return res.end();

      geocoder.reverse({
        lat: _.get(payload, 'latitude', latParis),
        lon: _.get(payload, 'longitude', lngParis),
      }, (err, loc) => {
        if (err) return res.end();

        res.send({
          city: loc[0].city || 'Paris',
          country: loc[0].country || 'France',
          latitude: _.get(payload, 'latitude', latParis),
          longitude: _.get(payload, 'longitude', lngParis),
        });

        mongoConnectAsync(res, async (Users) => {
          Users.updateOne({ 'account.username': username }, {
            $set: {
              location: {
                country: loc[0].country,
                city: loc[0].city,
                latitude: _.get(payload, 'latitude', latParis),
                longitude: _.get(payload, 'longitude', lngParis),
              },
            },
          }, (err) => {
            if (!err) log('Location updated');
          });
        });
        return true;
      });
      return true;
    });
  });
};

const renderProfile = (req, res) => {
  const { username } = req.session;
  const indexes = ['photo0', 'photo1', 'photo2', 'photo3', 'photo4'];

  mongoConnectAsync(res, async (Users) => {
    const user = await Users.findOne({ 'account.username': username });

    if (!user) {
      log('User not found, redirect to login page.');
      res.redirect('/');
    } else {
      const gallery = indexes.map(el => {
        _.set(user, `photos.${el}`, _.get(user, `photos.${el}`, 'http://fakeimg.pl/300x300/'));
        return _.get(user, `photos.${el}`, 'http://fakeimg.pl/300x300/');
      });

      _.set(user, 'photos.cover', _.get(user, 'photos.cover', 'http://fakeimg.pl/890x310/'));
      _.set(user, 'photos.profile', _.get(user, 'photos.profile', 'http://fakeimg.pl/300x300/'));

      res.render('profile', {
        isNotHome: true,
        navProfile: true,
        title: 'Matcha - Profile',
        bodyPage: 'profile-body',
        user,
        login: _.capitalize(_.get(req.session, 'firstname', 'profile')),
        age: getAge(user.infos.birthdate),
        likes: _.get(user, 'likes', []).length,
        reports: _.get(user, 'reports', []).length,
        gallery,
      });
    }
  });
};

export {
  deletePhoto,
  getPhoto,
  setProfile,
  uploadPhoto,
  setLast,
  getCover,
  uploadCover,
  listInterets,
  addInterest,
  deleteInterest,
  editOrientation,
  editSex,
  editMail,
  editName,
  editBiography,
  getAddress,
  getCity,
  renderProfile,
};
