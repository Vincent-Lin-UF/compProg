#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//static const ll INF = (1LL << 62);

#define all(x) (x).begin(), (x).end()

static inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

static void stripe(int n) {
  vector<int> arr(n);
  int rsum = 0;
  
  for(int i = 0; i < n;i++){
    cin >> arr[i];
    rsum += arr[i];
  }
  

  int lsum = 0;
  int total = 0;
  for(int i = 0; i < n - 1; i++){
    lsum += arr[i];
    rsum -= arr[i];
    if (lsum == rsum) total++;
  }
  cout << total << "\n";
}

static void solve_one() {
  int n; cin >> n;
  stripe(n);
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

