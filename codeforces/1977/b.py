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

def tobin(ll):
    bina = []
    while ll >= 1:
        if ll%2:
            if len(bina) > 0 and bina[-1]:
                bina[-1] *= -1
                ll = ll + 1
                continue
            else:
                bina.append(ll%2)
                ll //= 2 
        else:
            bina.append(ll%2)
            ll //= 2

    return bina

def solve():
    ll = inp()
    res = tobin(ll)
    print(len(res))
    for i in res:
        print(i, end=" ")
    print("")




if __name__ == "__main__":
    t = inp()
    while t:
        t -= 1
        solve()
