#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

static inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

static void solve_one(int n) {
  ll best = 0, cur = 0;
  for (int i = 0; i < n; i++){
    ll x; cin >> x;
    cur = max(0LL, cur +x);
    best = max(best, cur);
  }
  if (best > 0) cout << "The max winning streak " << best << "\n";
  else cout << "Losing streak\n";
}

int main() {
    fast_io();

    // solve_one();
    

    // int T; cin >> T;
    // while (T--) solve_one();
    

    int n;
    while (cin >> n && n != 0){
      solve_one(n);
    }

    return 0;
}

