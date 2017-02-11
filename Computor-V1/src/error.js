import { log } from 'console';
import _ from 'lodash';

import regexp from './constants';

// -5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0
const allowed = ['-', '+', 'X', '^', '=', '.', '*', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'];
const DEBUG = Boolean(parseInt(process.env.DEBUG, 10));
const TESTS = Boolean(parseInt(process.env.TESTS, 10));

const debug = data => {
  if (DEBUG) log(...data);
};

const error = message => {
  if (!TESTS) log(message);
  return false;
};

const isValidPolynominal = left => {
  for (const power of Object.keys(left)) {
    if (_.toNumber(power) > 2 && left[power] !== 0) {
      return error('Error: Polynominal degree > 2');
    }
  }

  return true;
};

const check = line => {
  const cleaned = line.trim().replace(/ /g, '').replace(',', '.').toUpperCase();
  const characters = cleaned.split('');

  if (_.isEmpty(line) || _.isNil(line) || _.isEqual(cleaned.length, 0)) {
    return error('Error: Empty line');
  }

  if (!line.includes('=')) {
    return error('Error: Character = is missing');
  }

  if (!_.isEqual(line.match(/=/g).length, 1)) {
    return error('Error: Multiple equal sign');
  }

  const test = line.split('=');

  if (!_.isEqual(test.length, 2) || _.isEmpty(test[0]) || _.isEmpty(test[1])) {
    return error('Error: Wrong expression format');
  }

  for (let index = 0; index < characters.length; index++) {
    if (!_.includes(allowed, characters[index])) {
      return error(`Error: Character "${characters[index]}" at index ${index} is not allowed in expression`);
    }
  }

  const processed = cleaned.match(regexp);
  // debug(['DEBUG', 'processed', processed]);

  if (_.isEmpty(processed)
    || _.isNil(processed)
    || !_.isEqual(processed.join('').length + 1, cleaned.length)
    || _.isEmpty(cleaned.split('=')[1])) {
    return error('Error: Follow the pattern NUMBER * X^POWER');
  }

  return true;
};

export {
  check,
  debug,
  error,
  isValidPolynominal,
};
