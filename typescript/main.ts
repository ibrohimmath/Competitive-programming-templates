import * as fs from "fs";

function getCode(x: string) {
  return x.charCodeAt(0) - 'a'.charCodeAt(0);
}

function solve(lines: string[]) {
  const a: string = lines[0];
  const b: string = lines[1];
  // const n: number = Math.min(a.length, b.length);
  // console.log(a.slice(0, n) == b.slice(0, n));
  console.log(a.length, b.length);
}

function main() {
  const input = fs.readFileSync(0, "utf-8").trim();
  let lines = input.split('\n');
  solve(lines);
  // solve([]);
}

main();
