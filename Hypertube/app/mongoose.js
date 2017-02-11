var mongoose = require('mongoose');
mongoose.connect('mongodb://52.30.199.218:27017/hypertube');

var db = mongoose.connection;

db.on('error', function (err) {
	console.log('DB Connection error : ', err);
});

db.once('open', function() {
	console.log('DB Connection successed on mongodb://52.30.199.218:27017/hypertube');
});

module.exports = mongoose;
