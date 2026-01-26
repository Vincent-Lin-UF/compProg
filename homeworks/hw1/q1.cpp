#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

static inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

static void solve_one() {
  int n; cin >> n;

  vector<string> s(n);
  unordered_set<string> st;

  for(int i = 0; i < n; i++){
    cin >> s[i];
    st.insert(s[i]);
  }

  string res;
  res.reserve(n);

  for(int i = 0; i < n; i++){
    const string& cur = s[i];
    bool found = false;

    for(int j = 0; j < (int)cur.size(); j++){
      string a = cur.substr(0,j);
      string b = cur.substr(j);
      if (st.count(a) && st.count(b)){
        found = true;
        break;
      }
    }
    res.push_back(found?'1':'0');
  }
  cout << res << '\n';
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

