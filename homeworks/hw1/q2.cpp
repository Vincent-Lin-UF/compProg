#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

static inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

static void solve_one() {
  int n; cin >> n;

  priority_queue<ll> pq;
  ll res = 0;

  for(int i = 0; i < n;i++){
    ll val;
    cin >> val;
    if (val > 0){
      pq.push(val);
    } else {
      if (!pq.empty()){
        res += pq.top();
        pq.pop();
      }
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

