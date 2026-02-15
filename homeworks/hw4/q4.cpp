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
  int n,k; 
  cin >> n >> k;
  vector<int> a(n);

  bool hasK = false;
  forn(i,n) {
    int val; cin >> val;
    if (val == k) hasK = true;
    a[i] = val;
  }

  if (!hasK) { cout << "no\n"; return; }
  if (n == 1) { cout << "yes\n"; return; }

  bool ok = false;
  forn(i,n-1) if (a[i] >= k && a[i+1] >= k) ok = true;
  forn(i,n-2) if (a[i] >= k && a[i+2] >= k) ok = true;

  cout << (ok ? "yes\n" : "no\n");
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

