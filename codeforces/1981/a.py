import sys
from math import log2
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

def solve():
    a,b = inlt()
    print(int(log2(b)))
    


if __name__ == "__main__":
    t = inp()
    while t:
        t -= 1
        solve()