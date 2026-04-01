"use strict";
var DSU = /** @class */ (function () {
    function DSU(n) {
        this.parent = Array.from({ length: n }, function (_, i) { return i; });
        this.size = Array(n).fill(1);
    }
    DSU.prototype.find_set = function (x) {
        if (x === this.parent[x]) {
            return x;
        }
        return (this.parent[x] = this.find_set(this.parent[x]));
    };
    DSU.prototype.union_sets = function (x, y) {
        var _a;
        var rootX = this.find_set(x);
        var rootY = this.find_set(y);
        if (rootX === rootY)
            return;
        if (this.size[rootX] < this.size[rootY]) {
            _a = [rootY, rootX], rootX = _a[0], rootY = _a[1];
        }
        this.parent[rootY] = rootX;
        this.size[rootX] += this.size[rootY];
    };
    return DSU;
}());
