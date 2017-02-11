import { MongoClient } from 'mongodb';

const mongoConnectAsync = (res, callback) => {
  const { connect } = MongoClient;
  // const url = 'mongodb://admin:matcha42@ds049466.mlab.com:49466/matcha';
  const url = 'mongodb://198.211.123.106/matcha_glarivie';
  connect(url, (err, db) => {
    if (err) res.status(500).send('Error - Fail to connect to database');
    else {
      const Users = db.collection('users');
      callback(Users);
    }
  });
  return (true);
};

export default mongoConnectAsync;
