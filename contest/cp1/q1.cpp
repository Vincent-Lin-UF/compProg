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
  int n; cin >> n;
  vector<ll> v(n+1), u(n+1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    u[i] = v[i];
  }
  sort(u.begin()+1, u.end());

  vector<ll> pv(n+2), pu(n+2);
  for (int i = 1; i <= n; i++) {
    pv[i] = pv[i-1] + v[i];
    pu[i] = pu[i-1] + u[i];
  }

  int m; cin >> m;
  while (m--) {
    int type, l, r;
    cin >> type >> l >> r;
    if (type == 1) {
      cout << pv[r] - pv[l-1] << "\n";
    } else {
      cout << pu[r] - pu[l-1] << "\n";
    }
  }
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

