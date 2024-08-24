for _ in range(int(input())):
    n = int(input())
    sm = 0
    sm += (n %10)
    sm += (n//10)
    print(sm)