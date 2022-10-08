"""
    @idea_author: Anton Panov, Vladislav Tselikov, Vladimir Nazarov
    @code_author: Anton Panov
    @code_rewriter: Vladislav Tselikov
    @pcms: Accepted
    @date: 08.10.2022
"""

import sys

def gcd(a, b):
    return b if a == 0 else gcd(b % a, a)


def getCount(n, s, p, k):
    res = 0
    for i in range(n):
        res += abs(s[i] - p[i] * k)
    return res


n = int(sys.stdin.readline())

s = [int(i) for i in sys.stdin.readline().split()]
p = [int(i) for i in sys.stdin.readline().split()]

h = 0
for i in range(n):
    h = gcd(h, p[i])
for i in range(n):
    p[i] //= h

l = 1
r = 10 ** 9 + 9
while r - l > 2:
    m1 = l + (r - l) // 3
    m2 = r - (r - l) // 3
    if getCount(n, s, p, m1) > getCount(n, s, p, m2):
        l = m1
    else:
        r = m2
result = min(getCount(n, s, p, l + 1), getCount(n, s, p, l), getCount(n, s, p, r))

sys.stdout.write(str(result))