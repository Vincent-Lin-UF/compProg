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
  // build p vector of all values
  vector<int> p(n);
  forn(i,n) cin >> p[i];

  // calculuate suffix max for each index
  vector<int> sufmx(n);
  sufmx[n-1] = p[n-1];
  for(int i = n-2; i >= 0; i--) sufmx[i] = max(p[i],sufmx[i+1]);

  // find when next suffix max is higher than current value so we can switch these
  int l = -1;
  forn(i,n){
    if (sufmx[i] > p[i]) { l = i; break; }
  }

  // if suffix max higher exists then we iterat until we find the right distance then reverse
  if (l != -1){
    int mx = sufmx[l];
    int r = l;
    while (r < n && p[r] != mx) r++;
    reverse(p.begin() + l, p.begin() + r + 1);
  }

  // print it all out
  forn(i,n) {
    cout << p[i] << ((i+1==n)?"\n":" ");
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

