#include <bits/stdc++.h>

using namespace std;

void solve() {
  
    int l,r;
    cin>>l>>r;
    
    int L,R;
    cin>>L>>R;
    
    long long int ans=0;
    
    map<int,int> m;
    
    for(int i=l;i<=r;i++)
    {
      
      for(int j=L;j<=R;j++)
      {
        
        if(i==j)
        {
          continue;
        }
        
        else
        {
          
          int a=i;
          int b=j;
          
          if(abs(a-b)==1)
          {
            int gate=min(a,b);
            if(m.count(gate)==0)
            {
              ans++;m[gate]=1;
            }
          }
          
          else
          {
            
            int gate=min(a,b);
            int limit=max(a,b);
            int flag=0;
            
            for(int k=gate;k<limit;k++)
            {
                if(m.count(k))
                {
                  flag=1;break;
                }
            }
            
            if(flag==0)
            {
              ans++;m[limit-1]=1;
            }
            
          }
          
        }
        
      }
      
    }
    
    cout<<ans<<endl;
    
}

int main() {
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}