def myprintLine(x,b):
    for i in range(x):
        if b: print("##",end='')
        else: print("..",end='')
        b = not b
    print()



for _ in range(int(input())):
    n = int(input())
    f = True
    for j in range(n):
        myprintLine(n, f)
        myprintLine(n, f)
        f = not f