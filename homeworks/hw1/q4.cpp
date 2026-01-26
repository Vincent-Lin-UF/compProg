#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//static const ll INF = (1LL << 62);

#define all(x) (x).begin(), (x).end()

static inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

static void solve_one() {
  int n; cin >> n;
  int val;
  deque<int> res;

  for(int i = 0; i < n; i++){
    cin >> val;
    if (!res.empty() && res.front() < val) res.push_back(val);
    else res.push_front(val);
  }
  for(int i = 0; i < n; i++){
    cout << res[i] << (i==n-1?'\n':' ');
  }
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

