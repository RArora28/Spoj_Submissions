#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

#define mod 1000000007
#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define pi(x) printf("%d\n", x)
#define pll(x) printf("%lld\n", x)
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int> >
#define adjList vector<vector<int> >
#define ll long long int
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, z, q) for(i = z; i < q; i++)
#define rev(i, z, q) for(i = z; i > q; i--)

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll power(ll a,ll b) {
  ll ans = 1;  
  while(b > 0){
    if(b & 1)
      ans = ((ans % mod) *(a % mod)) % mod;
    a=((a % mod)*(a % mod)) % mod;
    b >>= 1;
  }
  return ans;
}

ll a[202][202][2], b;

ll dp(ll n, ll k, ll next) {

  if(k < 0 || n == 0 && k != 0)
    return 0;
  
  else if(n == 0 && k == 0)
    return 1;

  else if(n == b)
    return dp(n-1, k, 1) + dp(n-1, k, 0);
  
  else if(a[n][k][next] != -1)
    return a[n][k][next];

  else {
    if(next == 1) 
      return a[n][k][next] = dp(n-1, k-1, 1) + dp(n-1, k, 0);
    else
      return a[n][k][next] = dp(n-1, k, 1) + dp(n-1, k, 0);
  }
}

int main() {

  ll p, k;
  
  memset(a, -1, sizeof(a));
  
  cin>>p;
  
  ll ind = 1;
  
  while (p--) {
    cin>>ind>>b>>k;
    if(b <= 1)
      cout<<ind<<" 0"<<endl;
    else 
      cout<<ind<<" "<<dp(b, k, 1)<<endl;
  }
  
  return 0;
}

