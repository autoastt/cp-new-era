#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define GET_MACRO(_1, _2, _3, _4, NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2, rep1, rep0)(__VA_ARGS__)
#define rrep(...) GET_MACRO(__VA_ARGS__, rrep3, rrep2, rrep1, rrep0)(__VA_ARGS__)
#define rep0(a) for (int i = 0; i < a; i++)
#define rep1(i, a) for (int i = 0; i < a; i++)
#define rep2(i, a, b) for (int i = a; i <= b; i++)
#define rep3(i, a, b, c) for (int i = a; i <= b; i += c)
#define rrep0(a) for (int i = (a) - 1; i >= 0; i--)
#define rrep1(i, a) for (int i = (a) - 1; i >= 0; i--)
#define rrep2(i, a, b) for (int i = a; i >= b; i--)
#define rrep3(i, a, b, c) for (int i = a; i >= b; i -= c)
#define NL '\n'

const bool CASES = false;
const int N = 2e2 + 5;
const int M = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 1e18;

bool vis[N][N][4];

void solve() {
    vector<string> a;
    string s;
    while (getline(cin, s)) {
        if (s == "exit") break;
        a.pb(s);
    }
    int n = sz(a), m = sz(a[0]), ans = 0, sx, sy;
    int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
    rep (n) rep (j, m) if (a[i][j] == '^') sx = i, sy = j;
    rep (n) rep (j, m) {
        if (a[i][j] != '.') continue;
        a[i][j] = '#';
        queue<pii> q;
        fill_n(vis[0][0], N * N * 4, 0);
        q.push({sx, sy});
        bool loop = false;
        int di = 0;
        vis[sx][sy][di] = 1;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            int xx = x + dx[di], yy = y + dy[di];
            if (xx >= n || xx < 0 || yy >= m || yy < 0) break;
            if (a[xx][yy] == '#') di = (di + 1) % 4, xx = x, yy = y;
            if (vis[xx][yy][di]) {
                loop = true;
                break;
            }
            vis[xx][yy][di] = 1;
            q.push({xx, yy});
        }
        ans += loop;
        a[i][j] = '.';
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if (CASES) cin >> t;
    while (t--) {
        solve();
    }
}
