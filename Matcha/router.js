import app from './express';
import * as home from './homepage';
import * as profile from './profile-private';
import * as user from './profile-public';
import * as around from './around-me';
import * as messages from './messages';
import * as search from './advanced-search';

app.get('/', home.renderHome);
app.post('/user/add', home.addNewUser);
app.post('/user/login', home.connectUser);
app.get('/send-reset-email/:email', home.sendResetEmail);
app.get('/reset-password/:username/:password', home.resetPassword);
app.get('/reset-my-password/:id/:password', home.setNewPassword);

app.get('/profile', profile.renderProfile);
app.post('/location', profile.getAddress);
app.get('/location', profile.getCity);
app.post('/biography/update', profile.editBiography);
app.post('/name/update', profile.editName);
app.post('/mail/update', profile.editMail);
app.post('/sex/update', profile.editSex);
app.post('/orientation/update', profile.editOrientation);
app.post('/interest/delete', profile.deleteInterest);
app.post('/interest/add', profile.addInterest);
app.get('/interests/list', profile.listInterets);
app.post('/cover/upload', profile.uploadCover);
app.post('/photo/upload', profile.uploadPhoto);
app.get('/photo/set/:index', profile.setProfile);

app.get('/cover/get/:id', profile.getCover);
app.get('/photo/get/:index/:id', profile.getPhoto);

app.get('/photo/delete/:index', profile.deletePhoto);
app.get('/user/:id', user.renderPublic);
app.post('/like/plusone', user.likeUser);
app.post('/report/plusone', user.reportUser);
app.get('/user/new/visit/:id', user.addVisitor);
app.get('/user/get/visits/:id', user.getVisitors);
app.get('/user/get/likes/:id', user.getLikes);
app.get('/notifications', user.getNotifications);
app.get('/popularity/:id', user.popScore);

app.get('/set/connexion', profile.setLast);

app.get('/logout', home.logout);

app.get('/around-me', around.renderPage);
app.get('/advanced-search', search.renderPage);
app.get('/messages', messages.renderPage);
app.get('/messages/get', messages.getMessages);
app.post('/message/post', messages.postMessage);
