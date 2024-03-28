


for _ in range(int(input())):
    a,b = map(str, input().split(":"))
    x = int(a)
    am = True
    
    if x>12:
        x -= 12
        am = False
    elif x == 12:
        am = False
    elif x == 0:
        x = 12
    
    if x <10:
        print("0",end='')
    print(x,end=':')
    print(b,end=' ')
    if am: print("AM")
    else : print("PM")

