"use strict";
// Quick sort
function quickSort(l, r) {
    var _a;
    if (l >= r)
        return;
    var i = l;
    var j = r;
    var x = a[Math.floor((l + r) / 2)];
    while (i <= j) {
        while (a[i] < x)
            i++;
        while (a[j] > x)
            j--;
        if (i <= j) {
            _a = [a[j], a[i]], a[i] = _a[0], a[j] = _a[1];
            i++;
            j--;
        }
    }
    quickSort(i, r);
    quickSort(l, j);
}
var a = [23, 2, 32, 42];
quickSort(0, a.length - 1);
console.log(a);
