for _ in range(int(input())):
    n = int(input())
    a = list(input())
    ans = 0
    ans += min(n, a.count('A'))
    ans += min(n, a.count('B'))
    ans += min(n, a.count('C'))
    ans += min(n, a.count('D'))

    print(ans)