

for _ in range(int(input())):
    s = input()

    x = s[0]
    cnt = 1
    for c in s:
        if c != x:
            cnt+=1
            x = c
    
    f = False

    if "01" in s: f = True
    
    ans = cnt
    if f:
        ans-=1

    print(ans)


    