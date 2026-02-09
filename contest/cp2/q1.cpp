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
  ll n,x,y;
  cin >> n >> x >> y;

  vector<ll> a(n);
  forn(i,n) cin >> a[i];

  ll sum = 0;
  forn(i,n) sum += a[i];

  ll lo = sum - y;
  ll hi = sum - x;

  sort(all(a));

  ll res = 0;
  forn(i,n) {
    ll loBound = lo - a[i];
    ll hiBound = hi - a[i];
    ll left = lower_bound(a.begin() + i + 1, a.end(), loBound) - a.begin();
    ll right = upper_bound(a.begin() + i + 1, a.end(), hiBound) - a.begin();
    res += right - left;
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

