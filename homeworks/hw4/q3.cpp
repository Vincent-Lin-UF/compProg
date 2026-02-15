#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//static const ll INF = (1LL << 62);

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i,a,b) for (int i = (a); i <= (b); i++)
#define forn(i,n) for (int i = 0; i < (n); i++)
#define rforn(i,n) for (int i = (n)-1; i > -1; i--)
#define rdvec(a,n) do { forn(i,n) cin >> a[i]; } while(0)
#define print(x) (cout<<#x<<"="<<(x)<<"\n")

static inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

static void solve_one() {
  int n,m,k; 
  cin >> n >> m >> k;

  int lMax = k - 1;
  int rMax = n - k;

  int res = 1;
  rep(i,0,max(lMax,rMax)) {
    int j = m - (i+i-1);
    if (j < 0) continue;
    j = min(i,j);

    if (i <= lMax) res = max(res,1 + i + min(j,rMax));
    if (i <= rMax) res = max(res,1 + i + min(j,lMax));
  }
  cout << res << "\n";

}

int main() {
    fast_io();

    // solve_one();
    

    int T; cin >> T;
    while (T--) solve_one();
    

    // int n;
    // while (cin >> n && n != 0){
    //  solve_one(n);
    // }

    return 0;
}

