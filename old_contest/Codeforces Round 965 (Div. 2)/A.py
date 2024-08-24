for _ in range(int(input())):
    x, y, k = map(int, input().split())
    z = 1

    i = k
    while i > 1:
        print(x-z, y)
        print(x+z, y)
        i-=2
        z+=1
    
    if i == 1:
        print(x, y)
