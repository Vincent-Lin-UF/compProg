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
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> a(n);
  rdvec(a,n);

  forn(i,n-1) {
    ll req = max(0LL, a[i+1]-k);
    if (a[i] >= req) { // take
      m += a[i] - req;
    } else {
      ll add = req - a[i]; // add
      if (m < add) { // fail
        cout << "NO\n";
        return;
      }
      m -= add;
    }
  }
  cout << "YES\n";
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

