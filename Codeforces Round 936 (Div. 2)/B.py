from math import factorial
for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int ,input().split()))
    mx = 0

    p = [0] * (n+1)
    for i in range(n): p[i+1] = p[i] + a[i]
    sm = sum(a)
    mn = 0
    an = 0
    i = 0
    j = 0
    while j<n:
        if j<n:
            an += a[j]
            j+=1
        mx = max(mx, an)
        while an<0 and i<n:
            an -= a[i]
            i+=1
        mx = max(mx, an)
    while i<n:
        an -= a[i]
        i+=1
        mx = max(mx, an)
           
    pt = 2**k-1
    ans = (mx*pt)%1000000007
    print((ans+sm)%1000000007)
