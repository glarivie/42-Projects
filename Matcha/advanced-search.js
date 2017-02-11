import { log } from 'console';
import _ from 'lodash';

import mongoConnectAsync from './mongo';
import { getAge, sortUsersByDistance, getDistance } from './lib';

const listAllInterests = (allUsers, me) => {
  const list = me.interests ? me.interests : [];

  for (let i = 0; i < allUsers.length; i++) {
    allUsers[i].interests = allUsers[i].interests ? allUsers[i].interests : [];

    for (let j = 0; j < allUsers[i].interests.length; j++)
      list.push(allUsers[i].interests[j]);
  }
  return (_.uniq(list).sort());
};

const sortUsersByAge = (allUsers) => {
  const ret = allUsers.slice(0);
  for (let i = 0; i < allUsers.length; i++) {
    for (let j = i + 1; j < allUsers.length; j++) {
      if (parseInt(ret[i].age, 10) > parseInt(ret[j].age, 10)) {
        const tmp = ret[i];
        ret[i] = ret[j];
        ret[j] = tmp;
      }
    }
  }
  return (ret);
};

const sortUsersByPopularity = (allUsers) => {
  const ret = allUsers.slice(0);
  for (let i = 0; i < allUsers.length; i++) {
    for (let j = i + 1; j < allUsers.length; j++) {
      if (parseInt(ret[i].popularity, 10) < parseInt(ret[j].popularity, 10)) {
        const tmp = ret[i];
        ret[i] = ret[j];
        ret[j] = tmp;
      }
    }
  }
  return (ret);
};

const renderPage = (req, res) => {
  const { username } = req.session;

  mongoConnectAsync(res, async (Users) => {
    const user = await Users.findOne({ 'account.username': username });

    if (!user) {
      log('Error: User not found, redirect to login page.');
      res.redirect('/');
    } else {
      const allUsers = [];
      const me = user;
      const reports = user.reports ? user.reports : [];
      const myLongitude = user.location && user.location.longitude ? user.location.longitude : 0;
      const myLatitude = user.location && user.location.latitude ? user.location.latitude : 0;

      Users.find({}).each((err, user) => {
        if (user !== null) {
          if (user.account.username !== req.session.username && reports.indexOf(user.account.username) === -1) {
            user.age = getAge(user.infos.birthdate);
            user.distance = user.location ? getDistance(myLatitude, myLongitude, user.location.latitude, user.location.longitude) : 999;
            user.infos.sex = user.infos.sex ? user.infos.sex : 'Other';
            user.location = user.location ? user.location : {};
            user.location.city = user.location && user.location.city ? user.location.city : 'Not defined';
            user.infos.orientation = user.infos.orientation ? user.infos.orientation : 'Bisexual';
            user.photo = user.photos && user.photos.profile ? user.photos.profile : 'http://fakeimg.pl/200x200/';
            user.popularity = user.popularity ? user.popularity : 50;
            allUsers.push(user);
          }
        } else {
          res.render('search', {
            isNotHome: true,
            navSearch: true,
            title: 'Matcha - Advanced Search',
            bodyPage: 'profile-around',
            login: _.capitalize(_.get(req.session, 'firstname', 'profile')),
            byDistance: sortUsersByDistance(allUsers),
            byAge: sortUsersByAge(allUsers),
            byPopularity: sortUsersByPopularity(allUsers),
            interests: listAllInterests(allUsers, me),
          });
        }
      });
    }
  });
};


export { renderPage };
