// Quick sort
function quickSort(l: number, r: number): void {
  if (l >= r) return;
  let i: number = l;
  let j: number = r;
  const x: number = a[Math.floor((l + r) / 2)];

  while (i <= j) {
    while (a[i] < x) i++;
    while (a[j] > x) j--;
    if (i <= j) {
      [a[i], a[j]] = [a[j], a[i]];
      i++;
      j--;
    }
  }

  quickSort(i, r);
  quickSort(l, j);
}
const a: number[] = [23, 2, 32, 42];
quickSort(0, a.length - 1);
console.log(a);
