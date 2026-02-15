#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//static const ll INF = (1LL << 62);

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i,a,b) for (int i = (a); i <= (b); i++)
#define forn(i,n) for (int i = 0; i < (n); i++)
#define rdvec(a,n) do { forn(i,n) cin >> a[i]; } while(0)
#define print(x) (cout<<#x<<"="<<(x)<<"\n")

static inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

static void solve_one() {
  int n,m;
  cin >> n >> m;
  vector<int> ja,jd,c(m);
  forn(i,n) {
    string pos;
    int val;
    cin >> pos >> val;
    if (pos == "DEF") jd.push_back(val);
    else ja.push_back(val);
  }
  rdvec(c,m);

  sort(all(jd)); sort(all(ja)); sort(all(c));
  
  // cand 1 -> max(c[...k]) - min(a[..k])
  int s = (int)min(c.size(),ja.size());
  ll b1 = 0;
  rep(k,1,s) {
    int cidx = (int)c.size() - k;
    ll cur = 0;
    bool ok = true;
    forn(i,k) {
      int x = c[cidx + i];
      int y = ja[i];
      if (x < y) { ok = false; break; }
      cur += (ll)(x-y);
    }
    if (ok) b1 = max(cur,b1);
  }

  // cand 2 -> remove DEF then search to remove then all rest
  ll b2 = 0;
  multiset<int> ms;
  for (int val : c) ms.insert(val);

  for (int d : jd) {
    auto it  = upper_bound(all(ms),d);
    if (it == ms.end()) { cout << b1; return; }
    ms.erase(it);
  }

  for (int a : ja) {
    auto it = lower_bound(all(ms),a);
    if (it == ms.end()) { cout << b1; return; }
    b2 += (ll)(*it - a);
    ms.erase(it);
  }

  for (int val : ms) b2 += val;

  cout << max(b1,b2); 
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

