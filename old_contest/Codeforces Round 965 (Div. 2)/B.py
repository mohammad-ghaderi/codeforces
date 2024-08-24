for _ in range(int(input())):
    n = int(input())
    p = list(map(int, input().split()))
    for x in p[1:]:
        print(x, end=' ')
    print(p[0])