import string
# import sys
# read = sys.stdin.readline
# write = sys.stdout.write

def isNumber(s: string) -> bool:
  for x in s:
    if not 48 <= ord(x) <= 57:
      return False 
  return True
    
def valid(s: string) -> int:
  s = ''.join(list(s)[3:])
  if not s or s[0] != '(' or s[-1] != ')':
    return 0
  s = s[1:-1]
  if ',' not in s:
    return 0
  s = ''.join(s).split(',')
  if len(s) != 2:
    return 0 
  n1, n2 = s
  if not isNumber(n1) or not isNumber(n2):
    return 0
  if len(n1) > 3 or len(n2) > 3:
    return 0
  n1, n2 = int(n1), int(n2)
  return n1 * n2
  

# a = list(input())
with open('./input') as f:
  a = ''.join(f.readlines())
  total = 0
  for i in range(len(a[:-8])):
    # print(a[i:i+3])
    if ''.join(a[i:i+3]) == 'mul':
      ans = ''
      j = 0
      while i + j < len(a) and valid(ans) == 0:
        ans += a[i + j]
        j += 1
      total += valid(ans)
      # print(ans)
  print(total)