'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputList = [];
let outputList = [];
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputList.push(inputStdin);
});

process.stdin.on('end', _ => {
    inputList = inputList
      .join('')
      .trim()
      .split('\n')
      .map(string => {
        return string.trim();
      });

    main();
});

function readline() {
    return inputList[currentLine++];
}

function writeline(data) {
  outputList.push(data);
}

// let mult = false;
let mult = true;
function solve(testCase) {
  let x = parseInt(readline());
  if (x % 3 == 0)
    writeline("Second");
  else
    writeline("First");
}

function main() {
  let testCases = 1;
  if (mult)
    testCases = parseInt(readline());

  for (let t = 1; t <= testCases; ++t) {
    solve(t);
  }

  if (outputList.length > 0)
    process.stdout.write(outputList.join('\n'));
}

// import * as fs from "fs";

// function getCode(x: string) {
//   return x.charCodeAt(0) - 'a'.charCodeAt(0);
// }

// function solve(lines: string[]) {
//   const n: number = parseInt(lines[0]);
//   let lRemain: number = n >> 1;

//   const w: string = lines[1];
//   const s: string = lines[2];
//   const len: number = s?.length ?? 0;

//   const stack: string[] = [];
//   const ans: string[] = [];
//   for (const char of s.split('')) {
//     if (['(', '['].includes(char)) {
//       stack.push(char);
//       --lRemain;
//     } else {
//       stack.pop();
//     }
//   }

//   // console.log(lRemain, ans.join(''));

//   for (let i = 0; i < n - len; ++i) {
//     for (let j = 0; j < w.length; ++j) {
//       let opening: boolean = ['(', '['].includes(w[j]);
//       if (!opening && stack.length > 0 && ['()', '[]'].includes(stack.at(-1) + w[j])) {
//         stack.pop();
//         ans.push(w[j]);
//         break;
//       } else if (opening && lRemain > 0) {
//         stack.push(w[j]);
//         ans.push(w[j]);
//         --lRemain;
//         break;
//       }
//     }
//   }

//   console.log(s + ans.join(''));
// }

// function main() {
//   const input = fs.readFileSync(0, "utf-8");
//   let lines = input.split('\n');
//   solve(lines);
// }

// main();
