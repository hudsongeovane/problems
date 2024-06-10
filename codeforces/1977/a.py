import sys
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
    a, b = inlt()
    if a < b:
        print("No")
    elif (a-b)%2 == 0:
        print("Yes")
    else:
        print("No")


if __name__ == "__main__":
    t = inp()
    while t:
        t -= 1
        solve()