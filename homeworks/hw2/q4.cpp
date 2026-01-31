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
  string s; cin >> s;
  int n = (int)s.size();

  vector<char> suf(n+1,'{');
  for (int i = n - 1; i >= 0; i--) {
    suf[i] = min(s[i], suf[i+1]);
  }

  string u;
  u.reserve(n);
  vector<char> t;
  t.reserve(n);

  for (int i = 0; i < n; i++) {
    t.push_back(s[i]);
    while (!t.empty() && t.back() <= suf[i+1]) {
      u.push_back(t.back());
      t.pop_back();
    }
  }

  while(!t.empty()) {
    u.push_back(t.back());
    t.pop_back();
  }

  cout << u << '\n';
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

