

for _ in range(int(input())):
    l = list(map(int, input().split()))
    a = l[:2]
    b = l[2:]

    ans = 0
    cnt = 0
    if a[0] > b[0]:
        cnt+=1
    elif a[0] < b[0]:
        cnt-=1
    
    if a[1] > b[1]:
        cnt+=1
    elif a[1] < b[1]:
        cnt-=1

    if cnt > 0: ans+=2

    cnt = 0
    if a[0] > b[1]:
        cnt+=1
    elif a[0] < b[1]:
        cnt-=1
    
    if a[1] > b[0]:
        cnt+=1
    elif a[1] < b[0]:
        cnt-=1

    if cnt > 0: ans+=2

    print(ans)