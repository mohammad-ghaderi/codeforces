for _ in range(int(input())):
    n = int(input())
    s = list(map(int, input().split()))

    if n > 2:
        print("NO")
    else:
        sm = sum(s)
        x = sm//2
        if x != s[0]:
            print("YES")
        else :
            print("NO")