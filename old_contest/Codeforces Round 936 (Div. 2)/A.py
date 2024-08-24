import math
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    x = math.ceil(n/2)-1
    ans = 0
    j = x+1
    r = 0
    while j<n:
        if a[j] == a[x]:
            j+=1
            r+=1
        else: break
    j = x-1
    while True:
        a[x]+=1
        ans += 1
        if r>0:
            r-=1
        else: break
    print(ans)