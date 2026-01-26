#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//static const ll INF = (1LL << 62);

#define all(x) (x).begin(), (x).end()

static inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

static void solve_one() {
  string s; cin >> s;
   
  stack<char> st;
  int moves = 0;
  
  for (const char& ch : s) {
    if(!st.empty() && st.top() == ch) { st.pop(); moves++; }
    else st.push(ch);
  }

  cout << (moves%2? "Yes\n" : "No\n");
};

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

