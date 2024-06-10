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
    a, b = inlt()
    print(f"{min(a,b)} {max(a,b)}")


if __name__ == "__main__":
    t = inp()
    while t:
        t -= 1
        solve()