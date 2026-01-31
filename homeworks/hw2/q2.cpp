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
  int q; cin >> q;

  vector<ll> arr(n), diff(n+1), cnt(n);
  for (int i = 0; i < n; i++) cin >> arr[i];

  for (int i = 0; i < q; i++) {
    int l; cin >> l;
    int r; cin >> r;

    --l; --r;
    diff[l] += 1;
    if (r + 1 < n) diff[r + 1] -= 1;
  }

  ll cur = 0;
  for (int i = 0; i < n; i++) {
    cur += diff[i];
    cnt[i] = cur;
  }

  sort(all(arr));
  sort(all(cnt));

  ll res = 0;
  for (int i = 0; i < n; i++) res += arr[i] * cnt[i];
  cout << res << '\n';


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

