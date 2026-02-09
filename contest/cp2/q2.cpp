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
  vector<ll> a(n);
  forn(i,n) cin >> a[i];

  vector<vector<ll>> res;
  set<pair<ll,int>> prev;

  forn(i,n) {
    auto it = prev.lower_bound({a[i],-1});
    if (it == prev.begin()) {
      int idx = (int)prev.size();
      res.push_back({a[i]});
      prev.insert({a[i],idx});
    } else {
      it--;
      int idx = it->second;
      prev.erase(it);
      res[idx].push_back(a[i]);
      prev.insert({a[i],idx});
    }
  }

  for (auto& seq : res) {
    for (auto& val : seq) cout << val << " ";
    cout << "\n";
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

