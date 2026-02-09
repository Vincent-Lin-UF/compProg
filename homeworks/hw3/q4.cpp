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
    int n;
    ll m;
    cin >> n >> m;

    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];

    vector<int> c;
    c.reserve(n);
    rep(i, 1, n) c.push_back(a[i]);
    sort(all(c));

    vector<ll> pref(n + 1, 0);
    rep(i, 1, n) pref[i] = pref[i - 1] + c[i - 1];

    int res = n + 1; 

    for (int k = 1; k <= n; k++) {
        if (pref[k] > m) break;

        if (k == n) {
            res = 1;
            break;
        }

        int x = k + 1;       
        ll ax = a[x];
        int small = c[k - 1]; 

        ll need;
        if (ax <= small) need = pref[k];
        else need = pref[k - 1] + ax;

        int place = (need <= m) ? (n - k) : (n - k + 1);
        res = min(res, place);
    }

    cout << res << "\n";
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

