"""
    @idea_author: Vladimir Nazarov
    @code_author: Vladimir Nazarov
    @pcms: Accepted
    @date: 08.10.2022
"""

a = int(input())

s = 0
while 1:
    r = len(str(a))
    c = int('1' * r)

    # можем ли взять 1 * len(a)
    if a >= c:
        # да, берем
        a_new = a - c
        # получилось столько же знаков?
        if len(str(a_new)) < len(str(a)) or a <= 1:
            break
        a = a_new
        s += 1

    else:
        # нет, пробуем взять -1
        a_new = a - int('1' * (r-1))
        if a_new <= 1:
            break
        a = a_new
        s += 1

    # print(a)

print(s + 1)