import sys
from math import gcd, lcm
from collections import Counter
input = sys.stdin.readline

############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(s[:len(s) - 1])
def invr():
    return(map(int,input().split()))

def res(c: Counter, d: int):
    cnt = 0
    lc = 0
    for el in c.keys():
        if d%el == 0:
            cnt += c[el]
            lc = lcm(lc, el) if lc != 0 else el
    if lc == d:
        return cnt
    return 0


def solve():
    n = inp()
    v = inlt()
    mmax = max(v)
    lc = 1
    for el in v:
        lc = lcm(el, lc)

    i = 1
    if lc > mmax:
        print(n)
        return
    
    ress = 0
    c = Counter(v)

    while i*i <= mmax:
        if mmax%i == 0:
            if i not in c:
                ress = max(ress, res(c, i))
            if mmax//i not in c:
                ress = max(ress, res(c, mmax//i))
        i += 1

    print(ress)


if __name__ == "__main__":
    t = inp()
    while t:
        t -= 1
        solve()