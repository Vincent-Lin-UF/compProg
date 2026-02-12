#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//static const ll INF = (1LL << 62);

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i,a,b) for (int i = (a); i <= (b); i++)
#define forn(i,n) for (int i = 0; i < (n); i++)
#define rforn(i,n) for (int i = (n)-1; i > -1; i--)
#define rdvec(a,n) do { forn(i,n) cin >> a[i]; } while(0)
#define print(x) (cout<<#x<<"="<<(x)<<"\n")

static inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

static void solve_one() {
  int n; cin >> n;
  vector<ll> a(n);
  rdvec(a,n);

  set<ll> suf,pre;
  int r = n;
  rforn(i,n) {
    if (suf.contains(a[i])) break;
    suf.insert(a[i]);
    r = i;
  }

  int con = 0;
  int res = n;
  int l = -1;
  while (true) {
    while (r < l+1 || con > 0) {
      if (pre.contains(a[r])) con--;
        suf.erase(a[r]);
        r++;
    }
    res = min(res,r-l-1);
    l++;
    if (l >= n) break;
    if (pre.contains(a[l])) break;
    pre.insert(a[l]);
    if (suf.contains(a[l])) con++;
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

