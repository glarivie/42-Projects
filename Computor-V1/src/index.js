import 'dotenv/config';
import readline from 'readline';
import { log } from 'console';
// import _ from 'lodash';

import { extract, split, calc, displayResult } from './lib';
import { check, debug, isValidPolynominal } from './error';

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
  prompt: '➜  ',
});

// -5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0

rl.prompt();

rl.on('line', line => {
  if (check(line)) {
    const processed = extract(line);
    const { left, right } = calc(processed);

    debug(['DEBUG', 'left', left, 'right', right]);

    if (isValidPolynominal(left)) {
      const { a, b, c, degree } = split(left);

      debug(['DEBUG', 'a', a, 'b', b, 'c', c, 'degree', degree]);
      displayResult({ a, b, c }, degree);
    }
  }

  rl.prompt();
  return;
}).on('close', () => {
  log('Have a great day!');
  process.exit(0);
});
