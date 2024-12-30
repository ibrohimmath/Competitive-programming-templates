const MOD: number = 1000000007;
const N: number = 1e5 + 1;
let fact: number[] = [];
let invFact: number[] = [];  // Array to store inverse factorials

// Pre-calculate factorials and their modular inverses
function preCalc() {
  fact[0] = 1;
  for (let i = 1; i < N; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
  // Calculate inverse factorials using Fermat's Little Theorem
  invFact[N - 1] = binpow(fact[N - 1], MOD - 2);
  for (let i = N - 2; i >= 0; i--) {
    invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
  }

}

// Fast exponentiation to calculate base^exp % MOD
function binpow(a: number, n: number) {
  if (a === 0) return 0;
  if (n === 0) return 1;
  let res = 1;
  while (n > 0) {
    if (n % 2 === 1) {
      res = (res * a) % MOD;
    }
    a = (a * a) % MOD;
    n = Math.floor(n / 2);
  }
  return res;
}

// Combination function C(x, y) = (x + y)! / (x! * y!)
function combs(x: number, y: number) {
  if (x < 0 || y < 0 || x + y >= N) return 0; // Prevent invalid inputs
  return (fact[x + y] * invFact[x] % MOD) * invFact[y] % MOD;
}

// Extended Euclidean Algorithm
function extendGCD(a: number, b: number, x: [number], y: [number]): number {
  if (a === 0) {
    x[0] = 0;
    y[0] = 1;
    return b;
  }
  let x1: [number] = [0], y1: [number] = [0];
  const d: number = extendGCD(b % a, a, x1, y1);
  x[0] = y1[0] - Math.floor(b / a) * x1[0];
  y[0] = x1[0];
  return d;
}

// Finding a solution to the equation a * x + b * y = c
function findAnySolution(a: number, b: number, c: number, x: [number], y: [number], g: [number]): boolean {
  g[0] = extendGCD(a, b, x, y);
  if (c % g[0] !== 0) {
    return false;
  }
  x[0] *= Math.floor(c / g[0]);
  y[0] *= Math.floor(c / g[0]);
  if (a < 0) x[0] *= -1;
  if (b < 0) y[0] *= -1;
  return true;
}

// Find all solutions to the equation
function findAllSolutions(a: number, b: number, g: number, x: [number], y: [number]): [number, number][] {
  if (x[0] > y[0]) {
    [x[0], y[0]] = [y[0], x[0]];
    [a, b] = [b, a];
  }

  const lst: [number, number][] = [];
  const stepA = b / g;
  const stepB = a / g;

  let xx = x[0], yy = y[0];
  while (yy >= 0) {
    lst.push([xx, yy]);
    xx += stepA;
    yy -= stepB;
  }

  return lst.filter(([x, y]) => x >= 0 && y >= 0);
}

function main() {
  preCalc();

  let low: number = 3,
    high: number = 3,
    zero: number = 1,
    one: number = 1;

  let total: number = 0;

  for (let c = low; c <= high; c++) {
    const a: number = zero, b: number = one;
    const x: [number] = [0], y: [number] = [0], g: [number] = [0];
    if (!findAnySolution(a, b, c, x, y, g)) {
      continue;
    }
    const lst = findAllSolutions(a, b, g[0], x, y);
    console.log(lst, c);
    for (const [xx, yy] of lst) {
      console.log(xx, yy, combs(xx, yy), '#######');
      total = (total + combs(xx, yy)) % MOD;
    }
  }

  console.log("Total:", total);
}

main();

// const a: number = 1, b: number = 2, c: number = 3;
// const x: [number] = [0], y: [number] = [0], g: [number] = [0]; // Properly initialize arrays
// if (findAnySolution(a, b, c, x, y, g)) {
//   console.log(`Solution found: x = ${x[0]}, y = ${y[0]}, gcd = ${g[0]}`);
//   console.log("All solutions", findAllSolutions(a, b, g[0], x, y));
// } else {
//   console.log('No solution exists.');
// }
