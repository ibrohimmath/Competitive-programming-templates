"use strict";
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
