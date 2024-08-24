for _ in range(int(input())):
    a, b, c, d = map(int, input().split())

    if b < a: t = a;a = b;b = t
    if d < c: t = c;c = d;d = t

    if (c < a and d < a) or (c > b and d > b) or (c < a and d > b) or (c > a and d < b):
        print("NO")
    else:
        print("YES")