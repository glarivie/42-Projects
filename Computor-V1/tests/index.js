import 'dotenv/config';
import _ from 'lodash';
import expect from 'expect';

import { sqrt, extract, split, calc } from '../src/lib';
import { check, debug } from '../src/error';

import tests from './static';

tests.forEach(({ expression, error, left, right, refactor }) => {
  describe(`${expression}`, () => {
    it(`Error checking should return ${error}`, () => {
      expect(check(expression)).toBe(error);
    });

    if (error) {
      const processed = extract(expression);
      const factored = calc(processed);

      it(`${JSON.stringify(processed.left)} should be equal to ${JSON.stringify(left)}`, () => {
        expect(_.isEqual(processed.left, left)).toBe(true);
      });

      it(`${JSON.stringify(processed.right)} should be equal to ${JSON.stringify(right)}`, () => {
        expect(_.isEqual(processed.right, right)).toBe(true);
      });

      it(`${JSON.stringify(factored.left)} should be equal to ${JSON.stringify(refactor)}`, () => {
        expect(_.isEqual(factored.left, refactor)).toBe(true);
      });
    }
  });
});
