for _ in range(int(input())):
    n = int(input())
    ans = n//4
    n = n%4
    ans += n//2
    print(ans)