const update = position => async dispatch =>
  dispatch({
    type: 'UPDATE_COORD',
    data: position,
  });

const setSpeed = speed => async dispatch =>
  dispatch({
    type: 'UPDATE_SPEED',
    data: speed,
  });

export default {
  update,
  setSpeed,
};
