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
    # code here
    s = insr()
    ans = 1
    for i in range(1,len(s)):
        if s[i] != s[i-1]:
            ans += 1
    
    if "01" in s:
        ans -= 1
    
    print(ans)




if __name__ == "__main__":
    t = inp()
    while t:
        t -= 1
        solve()