#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define pb push_back
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const bool CASES = true;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    if (s[0] == '0') {
        for (int i = 0; i < n; i++) {
            if (s[i] == '0' && t[i] == '1') return void(cout << "NO\n");
            else if (s[i] == '1') break;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
