import _ from 'lodash';
import { log } from 'console';

import { error, debug } from './error';
import regexp from './constants';

const sqrt = nbr => nbr ** 0.5;

const toNumber = str => {
  if (str.includes('++')) {
    return _.toNumber(str.replace('++', ''));
  } else if (str.includes('--')) {
    return _.toNumber(str.replace('--', '-'));
  } else if (str.includes('-+')) {
    return _.toNumber(str.replace('-+', '-'));
  } else if (str.includes('+-')) {
    return _.toNumber(str.replace('+-', '-'));
  }
  return _.toNumber(str);
};

const extract = line => {
  const cleaned = line
    .trim() // Clean spaces at begining and end of the string
    .replace(/ /g, '') // Remove all whitespaces
    .replace(',', '.') // All floats should be in english internationnal format
    .toUpperCase(); // All letters in uppercase

  const processed = {
    left: {}, // [power]: number
    right: {}, // [power]: number
  };

  cleaned
    .split('=')
    .forEach((side, index) => side
      .match(regexp)
      .forEach(part => {
        const number = toNumber(part.split('*')[0]);
        const power = _.isUndefined(part.split('^')[1]) ? 1 : toNumber(part.split('^')[1]);
        const key = index > 0 ? 'right' : 'left';
        const existing = [_.get(processed, `[${key}][${power}]`, 0)];

        _.set(processed, `[${key}][${power}]`, _.sum(existing.concat(number)));
      })
    );

  return processed;
};

const calc = ({ left, right }) => {
  _.forEach(right, (rightNumber, power) => {
    const leftNumber = [_.get(left, `['${power}']`, 0)];

    _.set(left, `['${power}']`, _.sum(leftNumber.concat(-rightNumber)));
  });

  return {
    left,
    right: 0,
  };
};

const split = (left) => {
  const a = _.get(left, '[2]');
  const b = _.get(left, '[1]');
  const c = _.get(left, '[0]');

  if (_.isUndefined(a) || _.isEqual(_.toNumber(a), 0)) {
    log('Polynominal degree: 1');
    return { a: b, b: c, degree: 1 };
  }
  log('Polynominal degree: 2');
  return { a, b, c, degree: 2 };
};

const displayResult = ({ a = 0, b = 0, c = 0 }, degree) => {
  if (_.isEqual(degree, 1)) {
    if (!_.isEqual(a, 0)) {
      if (!_.isEqual(b, 0)) {
        log(`Reduced form: ${a} * X^1 ${b < 0 ? `- ${-b}` : `+ ${b}`} = 0`);
      } else {
        log(`Reduced form: ${a} * X^1 = 0`);
      }
      return log(`The solution is ${-b / a}`);
    } else if (_.isEqual(a, 0) && !_.isEqual(b, 0)) {
      return log('No solution');
    } else if (_.isEqual(a, 0) && _.isEqual(b, 0)) {
      return log('Infinite solutions');
    }
  } else if (_.isEqual(degree, 2)) {
    let reduced = 'Reduced form: ';
    const Δ = (b ** 2) - (4 * a * c);

    if (!_.isUndefined(a) && !_.isEqual(_.toNumber(a), 0)) {
      reduced += `${a} * X^2 `;
    }

    if (!_.isUndefined(b) && !_.isEqual(_.toNumber(b), 0)) {
      reduced += `${b < 0 ? `- ${-b}` : `+ ${b}`} * X^1 `;
    }

    if (!_.isUndefined(c) && !_.isEqual(_.toNumber(c), 0)) {
      reduced += `${c < 0 ? `- ${-c}` : `+ ${c}`} `;
    }

    log(`${reduced}= 0`);

    if (Δ > 0) {
      const x1 = (-b + sqrt(Δ)) / (2 * a);
      const x2 = (-b - sqrt(Δ)) / (2 * a);

      log('Discriminant is strictly positive, the two solutions are:');
      log('x1 =', x1);
      log('x2 =', x2);

      debug(['DEBUG', 'Δ', Δ, 'sqrt', sqrt(Δ), 'x1', x1, 'x2', x2]);
      return true;
    } else if (Δ === 0) {
      const x = -(b / (2 * a));

      log('Discriminant is equal to zéro, the only solution is:');
      log('x =', x);

      debug(['DEBUG', 'Δ', Δ, 'sqrt', sqrt(Δ), 'x', x]);
      return true;
    }

    log('Discriminant is strictly negative, the two complex solutions are:');
    log(`z1 = ${-b / (2 * a)} - i${-Δ / (2 * a)}`);
    log(`z1 = ${-b / (2 * a)} + i${-Δ / (2 * a)}`);
    return false;
  }

  return error('Error: Polynominal degree > 2');
};

export {
  sqrt,
  extract,
  calc,
  split,
  toNumber,
  displayResult,
};
