#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

int mod = 1e9 + 7;
int M = mod;

int bip(int a, int b)
{
   a %= M;
   int res = 1;
   while (b > 0)
   {
      if (b & 1)
         res = res * a % M;
      a = a * a % M;
      b >>= 1;
   }
   return res % M;
}

signed main()
{
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
   int t;
   cin >> t;
   while (t-- > 0)
   {
      int n, m;
      cin >> n >> m;
      int a[n];
      rep(i, n)
      {
         cin >> a[i];
      }
      sort(a, a + n, greater<int>());
      int sum = 0;
      int b = 0;
      int ex = 0;
      for (int i = 0; i < n; i += 2)
      {
         sum += a[i];
         if (i + 1 < n)
         {
            b += a[i + 1];
            ex += -1*(a[i + 1] - a[i]);
         }
      }
      int ans = (sum - b);
      // cout<<ans<<endl;
      // cout<<m<<" "<<ex<<endl;
      ans -= min(ex, m);
      cout << ans << endl;
   }
}