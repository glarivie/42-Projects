import { combineReducers } from 'redux';
import { routerReducer as routing } from 'react-router-redux';

import coord from './coord';

const rootReducer = combineReducers({
  routing,
  coord,
});

export default rootReducer;
