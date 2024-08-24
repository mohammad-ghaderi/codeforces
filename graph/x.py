n, m = map(int, input().split())

a=[list(map(int,input().split())) for i in range (n)]
if (n+m)%2==0:
    print("NO")
    quit()
mn=[[0 for j in range (m)]for i in range (n)]
mx=[[0 for j in range (m)]for i in range (n)]
for i in range (n):
    for j in range (m):
        mx1=-10**9
        mn1=10**9
        if i==0 and j==0:
            mn[0][0]=a[i][j]
            mx[0][0]=a[i][j]
        elif i:
            mx1=max(mx1,mx[i-1][j])+a[i][j]
            mn1=min(mn1,mn[i-1][j])+a[i][j]
        elif j:
            
            mx1=max(mx1,mx[i][j-1])+a[i][j]
            mn1=min(mn1,mn[i][j-1])+a[i][j]
        else:
            mn[i][j]=min(mn[i-1][j], mn[i][j-1])+a[i][j]
            mx[i][j]=max(mx[i-1][j], mx[i][j-1])+a[i][j]
print("hell")
if mn[-1][-1]<=0 and mx[-1][-1]>=0:
    print("YES")
else:
    print("NO")

print("mn")
print(mn)
print("mx")
print(mx)