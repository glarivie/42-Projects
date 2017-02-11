import express from 'express';
import parseurl from 'parseurl';
import bodyParser from 'body-parser';
import session from 'express-session';
// import path from 'path';
import hbs from 'express-handlebars';
import { log } from 'console';
import _ from 'lodash';

const app = express();

app.set('view engine', 'handlebars'); // Set template engine
app.engine('handlebars', hbs({
  defaultLayout: 'main',
  helpers: {
    mod4: (key, options) => ((parseInt(key, 10) + 1) % 4) === 0 ? options.fn(this) : options.inverse(this),
  },
}));

process.env.NODE_ENV = 'production';

app.enable('view cache');
app.use(express.static('public'));
app.use(express.static('bower_components'));
app.use(bodyParser.json({ limit: '5mb' }));
app.use(bodyParser.urlencoded({
  extended: true,
  limit: '5mb',
}));

app.use(session({
  secret: 'matcha',
  resave: false,
  saveUninitialized: true,
}));

app.use((req, res, next) => {
  let { views } = req.session;

  if (!views) {
    views = _.get(req.session, 'views', {});
  }
  // get the url pathname
  const pathname = parseurl(req).pathname;
  // count the views
  views[pathname] = (views[pathname] || 0) + 1;
  next();
});

app.listen(3333, () => log('Listening on port 3333'));

export default app;
