import { createStore, applyMiddleware, compose } from 'redux';
import thunkMiddleware from 'redux-thunk';
import createSocketIoMiddleware from 'redux-socket.io';
import io from 'socket.io-client';

import rootReducer from './reducers';

const socket = io('http://localhost:6789');
const socketIoMiddleware = createSocketIoMiddleware(socket, 'server/');

const configureStore = initialState => {
  const store = createStore(
    rootReducer,
    initialState,
    compose(
      applyMiddleware(
        thunkMiddleware,
        socketIoMiddleware,
      ),
      window.devToolsExtension && process.env.NODE_ENV === 'development' ? window.devToolsExtension() : f => f
    ),
  );

  // store.subscribe(() => {
  //   console.log('new client state', store.getState());
  // });
  //
  // store.dispatch({ type:'server/auth', data: {
  //   username: 'glarivie',
  //   room: 42,
  // } });

  if (module.hot) {
    // Enable Webpack hot module replacement for reducers
    module.hot.accept('./reducers', () => {
      const nextRootReducer = require('./reducers').default;
      store.replaceReducer(nextRootReducer);
    });
  }

  return store;
};

export default configureStore;
