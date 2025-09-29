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
