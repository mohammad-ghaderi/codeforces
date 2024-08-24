import math

z = int(input())
for _ in range(z):

    a=[int(c) for c in input().split()]
    b=[int(c) for c in input().split()]

    c=[]
    d=[]

    e=0

    for i in range(a[0],a[1]+1):
        c.append(i)

    for j in range(b[0],b[1]+1):
        d.append(j)

    for i in range(0,len(c)):
        for j in range(0,len(d)):
            if(c[i]==d[j]):
                e=e+1
                break


    if(e==0):
        an=1
    elif(len(c)==len(d) and e==len(c)):
        an=len(c)-1
    else:
        if((a[0]!=b[0] and a[1]!=b[1] and a[1]!=b[0] and a[0]!=b[1]) and (e==min(len(c),len(d)))):
            an=e+1
        elif((a[0]!=b[0] and a[1]!=b[1] and a[1]!=b[0] and a[0]!=b[1]) and (e!=min(len(c),len(d)))):
            an=e+1
        elif(a[0]==b[0] or a[1]==b[1]):
            an=e
        else:
            an=e+1
    print(an)
            
