for _ in range(int(input())):
    n = int(input())
    start = -1
    end = 0
    s = input()
    for i in range(n):
        if s[i] == 'W': continue
        if start == -1:
            start = i
        end = i
    print(end - start +1)