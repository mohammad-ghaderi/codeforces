n = m = X = None
rc = None
d = None
s = None
d = None
d = [[False for i in range(1001)] for j in range(1001)]


def check(i, x):
    if x == 0: x = n
    if i == m: 
        s.add(x)
        return
    if d[i][x-1]: return
    
    if rc[i][1] != '1': 
        check(i+1, (x+rc[i][0])%n)
    if rc[i][1] != '0':
        check(i+1, (x-rc[i][0])%n)
    d[i][x-1] = True

for _ in range(int(input())):
    n, m, X = map(int,input().split())
    rc = [None]*m
    d = [[False for i in range(n)] for j in range(m)]
    s = set()
    for i in range(m):  
        rc[i] = list(input().split())
        rc[i][0] = int(rc[i][0])
    check(0, X%n)
    an = sorted(s)
    print(len(s))
    for x in an:
        print(x, end=' ')
    print()