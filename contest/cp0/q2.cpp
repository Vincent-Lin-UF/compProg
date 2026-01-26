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
  int k; cin >> k;
  ll val;

  const int MOD = 1e9 + 7;

  ll sum = 0;
  ll cur = 0;
  ll total = 0;
  
  forn(i,n) {
    cin >> val;
    total = total+val;
    cur = max(cur+val,val);
    sum = max(sum,cur);
  }

  forn(i,k){
    total = ((total+sum)%MOD+MOD)%MOD;
    sum = ((sum+sum)%MOD+MOD)%MOD;
  }
  
  cout << total << "\n";

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

