
def func():
    n, k = map(int, input().split())
    m = n
    cnt = 0
    if k == 0: return 0

    k -= m
    cnt+=1
    m -= 1

    if k<=0: return cnt

    while k>0 and m >0:
        k -= m
        cnt+=1
        if k>0:
            k-= m
            cnt+=1
        m-=1
    
    return cnt



for _ in range(int(input())):
    print(func())