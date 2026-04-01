"use strict";
function code(c) {
    return c.charCodeAt(0) - 'a'.charCodeAt(0);
}
var TrieNode = /** @class */ (function () {
    function TrieNode(ends) {
        if (ends === void 0) { ends = false; }
        this.ends = ends;
        this.children = Array.from({ length: 26 }, function () { return null; });
        this.len = 0;
    }
    return TrieNode;
}());
var Trie = /** @class */ (function () {
    function Trie() {
        this.root = new TrieNode();
    }
    Trie.prototype.insertChar = function (c, curr, ends) {
        if (ends === void 0) { ends = false; }
        curr.children[code(c)] = new TrieNode(ends);
    };
    Trie.prototype.insertString = function (x) {
        var curr = this.root;
        for (var i = 0; i < x.length; i++) {
            var c = x[i];
            this.insertChar(c, curr, i === x.length - 1);
            curr = curr.children[code(c)];
        }
    };
    Trie.prototype.calcPrefLen = function (curr) {
        if (curr === void 0) { curr = this.root; }
        if (!curr) {
            return 0;
        }
        curr.len += +curr.ends;
        for (var i = 0; i < 26; i++) {
            curr.len += this.calcPrefLen(curr.children[i]);
        }
        return curr.len;
    };
    return Trie;
}());
var trie = new Trie();
trie.insertString("abcd");
trie.insertString("a");
console.log(trie.calcPrefLen());
