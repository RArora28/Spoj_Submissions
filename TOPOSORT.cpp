/* Rishabh Arora
   IIIT-Hyderabad */

#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

typedef pair<int,int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef long long int LL;
typedef unsigned long long int ULL;
typedef vector<VI> adjList;

#define mod 1000000007
#define rep(i, a, b) for(i = a; i < b; i++)
#define rev(i, a, b) for(i = b; i > a; i--)
#define REP(i, n) for(i = 1; i <= n; i++)
#define pr0(arr, n) rep(i, 0, n) cout<<arr[i]<<" "; cout<<endl;
#define pr1(arr, n) rep(i, 1, n+1) cout<<arr[i]<<" "; cout<<endl;
#define INF INT_MAX
#define gc getchar_unlocked
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SET(a,b) memset(a, b, sizeof(a))
#define gu getchar
#define pu putchar
#define SI(n) scanf("%d",&n)
#define PI(n) printf("%d\n",n)
#define SLL(n) scanf("%lld",&n)
#define PLL(n) printf("%lld\n",n)

#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif

//fast io using cin/cout
//ios::sync_with_stdio(false);	cin.tie(NULL);

int taken[10010], in[10010];
adjList adj;
bool ok = false;
set<int>s;
VI ans;

void dfs(int v) { 
  
  taken[v] = 1;

  for(auto it : adj[v]) { 
    if(taken[it] == 0) 
      dfs(it);
    else if(taken[it] == 1)
      ok = true;
    if(ok)
      return;
  }

  taken[v] = 2;
  return;
}

void bfs() {
  
  while(!s.empty()) { 
    
    int cur = *s.begin();
    ans.PB(cur);
    s.erase(s.begin());

    for(auto it : adj[cur]) {
      in[it]--;

      if(in[it] == 0)
	s.insert(it);
    }
  }

  return;
}

int main() {

  int i, j;
  int n, m;

  SI(n);
  SI(m);
  
  adj.resize(n+1);

  int a, b;

  while(m--) { 
    SI(a); SI(b);
    adj[a].PB(b);
    in[b]++;
  }
  
  rep(i, 1, n+1) 
    if(taken[i] == 0)
      dfs(i);
  
  if(ok) {
    cout<<"Sandro fails"<<endl;
    return 0;
  }
  
  rep(i, 1, n+1) 
    if(in[i] == 0)
      s.insert(i);
  
  bfs();

  for(auto it : ans)
    printf("%d ", it);
  
  cout<<endl;

  return 0;
}
