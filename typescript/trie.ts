function code(c: string) {
  return c.charCodeAt(0) - 'a'.charCodeAt(0);
}

class TrieNode {
  children: (TrieNode | null | undefined)[];
  ends: boolean;
  len: number;

  constructor(ends: boolean = false) {
    this.ends = ends;
    this.children = Array.from({ length: 26 }, () => null);
    this.len = 0;
  }
}

class Trie {
  root: TrieNode;

  constructor() {
    this.root = new TrieNode();
  }

  insertChar(c: string, curr: TrieNode, ends: boolean = false) {
    curr.children[code(c)] = new TrieNode(ends);
  }

  insertString(x: string) {
    let curr: TrieNode = this.root;
    for (let i = 0; i < x.length; i++) {
      const c: string = x[i];
      this.insertChar(c, curr, i === x.length - 1);
      curr = curr.children[code(c)]!;
    }
  }

  calcPrefLen(curr: TrieNode | null | undefined = this.root): number {
    if (!curr) {
      return 0;
    }
    curr.len += +curr.ends;
    for (let i = 0; i < 26; i++) {
      curr.len += this.calcPrefLen(curr.children[i]);
    }
    return curr.len;
  }
}

const trie = new Trie();
trie.insertString("abcd");
trie.insertString("a");
console.log(trie.calcPrefLen());

