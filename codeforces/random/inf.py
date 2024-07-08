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
    [a,b,c] = inlt()
    if c == 0:
        print("YES" if a == b else "NO")
    elif c > 0:
        if b >= a and (b-a)%c == 0:
            print("YES")
        else:
            print("NO")
    else:
        if b <= a and (b-a)%c == 0:
            print("YES")
        else:
            print("NO")



if __name__ == "__main__":
    t = 1
    while t:
        t -= 1
        solve()