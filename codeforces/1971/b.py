import sys
input = sys.stdin.readline
from collections import Counter
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
    # code here
    s = insr()
    c = Counter(s)
    if len(c.keys()) == 1:
        print("NO")
        return
    print("YES")
    print(s[1:] + s[0])
    



if __name__ == "__main__":
    t = inp()
    while t:
        t -= 1
        solve()