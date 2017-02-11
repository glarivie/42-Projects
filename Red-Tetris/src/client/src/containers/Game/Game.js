import React, { PropTypes } from 'react';
import { connect } from 'react-redux';
import _ from 'lodash';

import './Game.css';
import actions from '../../actions';

const Game = ({ dispatch, params, position, speed }) => {
  let timeout;

  if (position.top < 19) {
    timeout = setTimeout(async () => {
      await dispatch(actions.coord.update({
        ...position,
        top: position.top + 1,
      }));
    }, speed);
  }

  const handleKeyUp = ({ key }) => {
    if (key.includes('ArrowDown')) {
      dispatch(actions.coord.setSpeed(500));
    }
  };

  const handleKeyDown = async ({ key }) => {
    const { left } = position;

    switch (key) {
      case 'ArrowRight':
        await dispatch(actions.coord.update({
          ...position,
          left: _.isEqual(left, 9) ? left : left + 1,
        }));
        clearTimeout(timeout);
        break;
      case 'ArrowLeft':
        await dispatch(actions.coord.update({
          ...position,
          left: _.isEqual(left, 0) ? left : left - 1,
        }));
        clearTimeout(timeout);
        break;
      case 'ArrowDown':
        await dispatch(actions.coord.setSpeed(100));
        break;
      default:
        return false;
    }
  };

  console.log(position);

  return (
    <div
      tabIndex="0"
      className="game"
      onKeyDown={handleKeyDown}
      onKeyUp={handleKeyUp}
    >
      <span
        className="shape"
        style={{
          top: `calc(${position.top} * 2em)`,
          left: `calc(${position.left} * 2em)`,
        }}
      />
    </div>
  );
};

Game.propTypes = {
  children: PropTypes.node,
  params: PropTypes.object.isRequired,
  position: PropTypes.objectOf(PropTypes.number.isRequired).isRequired,
  speed: PropTypes.number.isRequired,
};

const mapStateToProps = ({ coord }) => ({
  position: _.get(coord, 'position', {
    top: 0,
    left: 0,
  }),
  speed: _.get(coord, 'speed', 500),
});

export default connect(mapStateToProps)(Game);
