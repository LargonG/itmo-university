"""
        @idea_author: Anton Panov, Vladislav Tselikov
        @code_author: Anton Panov
        @code_rewriter: Vladislav Tselikov
        @pcms: Accepted
        @date: 08.10.2022
"""

import sys

s = sys.stdin.readline().split()
n = int(s[0])
fmoney = float(s[1].replace(",", "."))
money = int(100 * fmoney)

d = {}

for i in range(n):
        s = sys.stdin.readline().split()
        name = s[0]
        fmoney = float(s[1].replace(",", "."))
        d[int(fmoney * 100)] = name

ans = -1
for i in d:

        cost = i
        name = d[i]
        if (cost % 100 <= money % 100) and (cost // 100 <= money // 100):
                ans = max(cost, ans)

if ans == -1:
        sys.stdout.write("-1")
else:
        sys.stdout.write(d[ans])