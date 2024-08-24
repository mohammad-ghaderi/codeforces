for _ in range(int(input())):
    n, k = map(int, input().split())
    sc = [None] * n

    for i in range(k): sc[i] = list(map(int, input().split()))

    ans = sc[0][1:]

    stat = True

    if k>1:
        for i in range(1, n):
            if sc[0][i] == sc[1][i]: continue
            if sc[1][i] == sc[0][0]:
                if (sc[0][i] == sc[1][0]):
                    