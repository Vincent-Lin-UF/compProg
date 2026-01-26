#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//static const ll INF = (1LL << 62);

#define all(x) (x).begin(), (x).end()

static inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

static void escape_from_stones(string s){
 int n = (int)s.size();
 deque<int> dq;
 dq.push_back(n);

 for(int i = n - 1; i >= 1; --i){
   if (s[i-1] == 'l') dq.push_back(i);
   else dq.push_front(i);
 }

 for (const int& x : dq) cout << x << "\n";
}

static void solve_one() {
  string s; cin >> s;
  escape_from_stones(s);
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

