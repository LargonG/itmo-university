"""
    @idea_author: Vladimir Nazarov
    @code_author: Vladimir Nazarov
    @pcms: Accepted
    @date: 08.10.2022
"""

gl = ['a', 'e', 'i', 'o', 'u', 'y']


n = int(input())
words = input().split()

er = 0


for i in words:
    er1 = 0
    for j in i:
        if j not in gl:
            er1 += 1

    # first gl
    er2 = 0
    t = 0
    for j in i:
        if t == 0:
            if j not in gl:
                er2 += 1
            t = 1
        else:
            if j in gl:
                er2 += 1
            t = 0

    # first not gl
    er3 = 0
    t = 0
    for j in i:
        if t == 0:
            if j in gl:
                er3 += 1
            t = 1
        else:
            if j not in gl:
                er3 += 1
            t = 0
    er += min(er1, er2, er3)
print(er)