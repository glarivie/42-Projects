import nodemailer from 'nodemailer';
import { log } from 'console';
import _ from 'lodash';

const deg2rad = deg => deg * (Math.PI / 180);

const getDistance = (lat1, lon1, lat2, lon2) => {
  const R = 6371; // Radius of the earth in km
  const dLat = deg2rad(lat2 - lat1);  // deg2rad below
  const dLon = deg2rad(lon2 - lon1);
  const a = Math.sin(dLat / 2) * Math.sin(dLat / 2) + Math.cos(deg2rad(lat1)) * Math.cos(deg2rad(lat2)) * Math.sin(dLon / 2) * Math.sin(dLon / 2);
  const c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1 - a));
  const d = R * c; // Distance in km

  return Math.round(d); // Distance in km between the two points
};

const getAge = (dateString) => {
  const tmp = dateString.split('/');
  const today = new Date();
  const birthDate = new Date(`${tmp[1]}/${tmp[0]}/${tmp[2]}`);
  const age = today.getFullYear() - birthDate.getFullYear();
  const m = today.getMonth() - birthDate.getMonth();
  return ((m < 0 || (m === 0 && today.getDate() < birthDate.getDate())) ? age - 1 : age);
};

const getToday = () => {
  const today = new Date();
  const day = today.getDate();
  const month = today.getMonth() + 1; // Months are zero based
  const year = today.getFullYear();

  return (`${day}/${month}/${year}`);
};

const validateEmail = (email) => {
  const regex = /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
  return regex.test(email);
};

const validateUser = (name) => {
  const regex = /^([a-zA-Z\-0-9èêéàôîïùñ]{2,17})$/;
  return regex.test(name);
};

const validateInterest = (interest) => {
  const regex = /^([a-zA-Z\-]{1,17})$/;
  return regex.test(interest);
};

const resLog = (res, msg = '', ret) => {
  if (_.isUndefined(ret)) {
    ret = msg;
  }

  log(msg);
  res.send(ret);
};

const sendEmail = (to, html, subject) => {
  const stmp = 'smtps://apimatcha@gmail.com:apiMatcha1212@smtp.gmail.com';
  const transport = nodemailer.createTransport(stmp);
  const mailOptions = {
    from: 'apimatcha@gmail.com',
    to,
    subject,
    html,
  };

  transport.sendMail(mailOptions, (err, info) => {
    log(err || info);
  });
};

const sortUsersByDistance = (allUsers) => {
  for (let i = 0; i < allUsers.length; i++) {
    for (let j = i + 1; j < allUsers.length; j++) {
      if (parseInt(allUsers[i].distance, 10) > parseInt(allUsers[j].distance, 10)) {
        const tmp = allUsers[i];
        allUsers[i] = allUsers[j];
        allUsers[j] = tmp;
      }
    }
  }
  return (allUsers);
};

export {
  getDistance,
  getAge,
  getToday,
  validateEmail,
  validateUser,
  validateInterest,
  resLog,
  sendEmail,
  sortUsersByDistance,
};
