for _ in range(int(input())):
    s = input()
    f = False
    x = s[0]

    start = 0
    for i in range(len(s)):
        if s[i] != x:
            start = i
            f = True
            break
    
    if f:
        print("YES")
        print(s[start],end='')
        print(s[:start]+s[start+1:])
        
    else:
        print("NO")