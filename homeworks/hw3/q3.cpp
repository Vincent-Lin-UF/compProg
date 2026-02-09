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
  int n,k;
  cin >> n >> k;
  vector<ll> a(n),b(n);
  forn(i,n) cin >> a[i];
  forn(i,n) cin >> b[i];

  map<ll, pair<ll,ll>> mp;

  forn(i,n) {
    mp[b[i]].first += 1;
    mp[b[i]].second += 1;
    mp[a[i]].second -= 1;
  }

  ll buyers = 0, neg = 0, res = 0;

  for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
    ll p = it->first;
    ll db = it->second.first;
    ll dn = it->second.second;

    buyers += db;
    neg += dn;

    if (neg <= k) {
      res = max(res, p * buyers);
    }
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

