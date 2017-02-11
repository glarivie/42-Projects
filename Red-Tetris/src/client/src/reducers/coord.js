import _ from 'lodash';

const dataReducer = (state = {}, action) => {
  switch (action.type) {
    case 'UPDATE_COORD':
      return {
        ...state,
        position: action.data,
      }
    case 'UPDATE_SPEED':
      return {
        ...state,
        speed: action.data,
      }
    default:
      return state;
  }
};

export default dataReducer;
