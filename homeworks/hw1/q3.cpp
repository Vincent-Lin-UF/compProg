#include <bits/stdc++.h>
using namespace std;

using ll = long long;
static const ll INF = (1LL << 62);

#define all(x) (x).begin(), (x).end()

static inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

static void solve_one() {
  int n,k; cin >> n >> k;

  vector<int> a(k), t(k);
  for(int i = 0; i < k; i++) cin >> a[i];
  for(int i = 0; i < k; i++) cin >> t[i];

  vector<ll> base(n+1,INF), left(n+1,INF), right(n+1,INF);
  for(int i = 0; i < k; i++){
    base[a[i]] = t[i];
  }

  for(int i = 1; i <= n; i++){
    if (i == 1) left[i] = base[i];
    else left[i] = min(base[i], left[i-1]+1);
  }

  for(int i = n; i >= 1; i--){
    if (i == n) right[i] = base[i];
    else right[i] = min(base[i], right[i+1]+1);
  }

  for(int i = 1; i <= n; i++)
    cout << min(left[i],right[i]) << (i==n? '\n' : ' ');

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

