def solve():
    n = int(input())
    a = list(map(int, input().split()))
    for i in range(n-2):
        if a[i]*2 > a[i+1] or a[i] > a[i+2]: return False
        a[i+1] -= a[i]*2
        a[i+2] -= a[i]
        a[i] = 0
    if a[-1]>0 or a[-2]>0: return False
    return True



for _ in range(int(input())):
    if solve(): print("YES")
    else :print("NO")