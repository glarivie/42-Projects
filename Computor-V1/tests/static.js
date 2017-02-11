const tests = [{
  expression: '',
  error: false,
}, {
  expression: '1 * X^0 + 2 * X^1 = - 1 * X^0 + 4 * X^1',
  error: true,
  left: { 0: 1, 1: 2 },
  right: { 0: -1, 1: 4 },
  refactor: { 0: 2, 1: -2, 2: 0 },
}, {
  expression: '-1 * X^0 - 2 * X^1 = 1 * X^0 + 2 * X^1',
  error: true,
  left: { 0: -1, 1: -2 },
  right: { 0: 1, 1: 2 },
}, {
  expression: '1 * X^0 + 2 * X^1 + 3 * X^2 = - 1 * X^0 + 4 * X^1 + 3 * X^2',
  error: true,
  left: { 0: 1, 1: 2, 2: 3 },
  right: { 0: -1, 1: 4, 2: 3 },
}, {
  expression: '1 * X^0 + 2 * X^1 + 4 * X^2 = 0 * X^0 + 4 * X^1 + 3 * X^2',
  error: true,
  left: { 0: 1, 1: 2, 2: 4 },
  right: { 0: 0, 1: 4, 2: 3 },
}, {
  expression: '1 * X^0 + 2 * X^1 + 4 * X^2 = 0 * X^0 + 4 * X^1 + 3 * X^2 + 0 * X^3 + 0 * X^4 + 0 * X^5',
  error: false,
}, {
  expression: '1 * X^0 + 2.5 * X^1 = - 1.561151 * X^0 + 4.000 * X^1',
  error: true,
  left: { 0: 1, 1: 2.5 },
  right: { 0: -1.561151, 1: 4 },
}, {
  expression: '1.8526 * X^0 + 2.989 * X^1 + 2.16 * X^2 = - 1.122241 * X^0 + 4.999 * X^1 + 3.25 * X^2',
  error: true,
  left: { 0: 1.8526, 1: 2.989, 2: 2.16 },
  right: { 0: -1.122241, 1: 4.999, 2: 3.25 },
}, {
  expression: '1 * X^0 = 2 * X^0',
  error: true,
  left: { 0: 1 },
  right: { 0: 2 },
}, {
  expression: '1 * X^0 = 1 * X^0',
  error: true,
  left: { 0: 1 },
  right: { 0: 1 },
}, {
  expression: '1 * X^0 + 2 * X^1 + 4 * X^2 = 0 * X^0 + 4 * X^1 + 3 * X^2 + 0 * X^3 + 0 * X^4 + 2 * X^5',
  error: false,
}, {
  expression: '1 * X^0 - 2 * X^1 + 1 * X^2 + 0 * X^3 + 0 * X^4 - 2 * X^5 = 0',
  error: false,
}, {
  expression: '0 = 1 * X^0',
  error: false,
}, {
  expression: '1 * X^0 = 0',
  error: false,
}, {
  expression: '0 = 0',
  error: false,
}];

export default tests;
