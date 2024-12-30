var MOD = 1000000007;
var N = 1e5 + 1;
var fact = [];
var invFact = []; // Array to store inverse factorials
// Pre-calculate factorials and their modular inverses
function preCalc() {
    fact[0] = 1;
    for (var i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    // Calculate inverse factorials using Fermat's Little Theorem
    invFact[N - 1] = binpow(fact[N - 1], MOD - 2);
    for (var i = N - 2; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}
// Fast exponentiation to calculate base^exp % MOD
function binpow(a, n) {
    if (a === 0)
        return 0;
    if (n === 0)
        return 1;
    var res = 1;
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
function combs(x, y) {
    if (x < 0 || y < 0 || x + y >= N)
        return 0; // Prevent invalid inputs
    return (fact[x + y] * invFact[x] % MOD) * invFact[y] % MOD;
}
// Extended Euclidean Algorithm
function extendGCD(a, b, x, y) {
    if (a === 0) {
        x[0] = 0;
        y[0] = 1;
        return b;
    }
    var x1 = [0], y1 = [0];
    var d = extendGCD(b % a, a, x1, y1);
    x[0] = y1[0] - Math.floor(b / a) * x1[0];
    y[0] = x1[0];
    return d;
}
// Finding a solution to the equation a * x + b * y = c
function findAnySolution(a, b, c, x, y, g) {
    g[0] = extendGCD(a, b, x, y);
    if (c % g[0] !== 0) {
        return false;
    }
    x[0] *= Math.floor(c / g[0]);
    y[0] *= Math.floor(c / g[0]);
    if (a < 0)
        x[0] *= -1;
    if (b < 0)
        y[0] *= -1;
    return true;
}
// Find all solutions to the equation
function findAllSolutions(a, b, g, x, y) {
    var _a, _b;
    if (x[0] > y[0]) {
        _a = [y[0], x[0]], x[0] = _a[0], y[0] = _a[1];
        _b = [b, a], a = _b[0], b = _b[1];
    }
    var lst = [];
    var stepA = b / g;
    var stepB = a / g;
    var xx = x[0], yy = y[0];
    while (yy >= 0) {
        lst.push([xx, yy]);
        xx += stepA;
        yy -= stepB;
    }
    return lst.filter(function (_a) {
        var x = _a[0], y = _a[1];
        return x >= 0 && y >= 0;
    });
}
function main() {
    preCalc();
    var low = 3, high = 3, zero = 1, one = 1;
    var total = 0;
    for (var c = low; c <= high; c++) {
        var a = zero, b = one;
        var x = [0], y = [0], g = [0];
        if (!findAnySolution(a, b, c, x, y, g)) {
            continue;
        }
        var lst = findAllSolutions(a, b, g[0], x, y);
        console.log(lst, c);
        for (var _i = 0, lst_1 = lst; _i < lst_1.length; _i++) {
            var _a = lst_1[_i], xx = _a[0], yy = _a[1];
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
