class DSU {
  parent: number[];
  size: number[];

  constructor(n: number) {
    this.parent = Array.from({ length: n }, (_, i) => i);
    this.size = Array(n).fill(1);
  }

  find_set(x: number): number {
    if (x === this.parent[x]) {
      return x;
    }
    return (this.parent[x] = this.find_set(this.parent[x]));
  }

  union_sets(x: number, y: number): void {
    let rootX: number = this.find_set(x);
    let rootY: number = this.find_set(y);
    if (rootX === rootY) return;
    if (this.size[rootX] < this.size[rootY]) {
      [rootX, rootY] = [rootY, rootX];
    }
    this.parent[rootY] = rootX;
    this.size[rootX] += this.size[rootY];
  }
}
