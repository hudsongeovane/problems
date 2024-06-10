import sys
input = sys.stdin.readline

############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))

def solve():
    # code here
    a,b,c,d = inlt()
    aa = max(a,b)
    bb = min(a,b)
    cc = max(c,d)
    dd = min(c,d)
    high = {l for l in range(1,13) if l > aa or l < bb}

    if cc in high and dd in high:
        print("NO")
    elif cc not in high and dd not in high:
        print("NO")
    else:
        print("YES")


if __name__ == "__main__":
    t = inp()
    while t:
        t -= 1
        solve()