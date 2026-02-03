#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//static const ll INF = (1LL << 62);

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i,a,b) for (int i = (a); i <= (b); i++)
#define forn(i,n) for (int i = 0; i < (n); i++)

#define print(x) (cout<<#x<<"="<<(x)<<"\n")

static inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

static void solve_one() {
  int n, k;
  cin >> n >> k;

  vector<ll> a(n), b(k);
  forn(i, n) cin >> a[i];
  forn(i, k) cin >> b[i];

  vector<ll> pre(n);
  pre[0] = a[0];
  rep(i, 1, n-1) pre[i] = pre[i-1] + a[i];

  set<ll> pSet(all(pre));

  set<ll> cand;
  forn(i, n) {
    cand.insert(b[0] - pre[i]);
  }

  int res = 0;
  for (ll s : cand) {
    bool valid = true;
    forn(j, k) {
      if (pSet.find(b[j] - s) == pSet.end()) {
        valid = false;
        break;
      }
    }
    if (valid) res++;
  }

  cout << res << "\n";
}

int main() {
    fast_io();

    solve_one();
    

    // int T; cin >> T;
    // while (T--) solve_one();
    

    // int n;
    // while (cin >> n && n != 0){
    //  solve_one(n);
    // }

    return 0;
}

