#include <bits/stdc++.h>
 
//#define int long long
//
using namespace std;
int const N = 1e6 + 2, M = 998244353;
int n, idx, m;
int const dx[] = {-1, 1, 0, 0};
int const dy[] = {0, 0, 1, -1};
 
bool valid(int x, int y) {
    return (1 <= x && x <= n && 1 <= y && y <= m);
}
 
void dowork() {
    cin >> n >> m;
    char grid[n + 2][m + 2];
    int grid2[n + 2][m + 2];
    bool vis[n + 2][m + 2];
    memset(vis, 0, sizeof vis);
    map<array<int, 2>, int> col, row;
    map<int, int> sz;
    stack<array<int, 3>> q;
    int id = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == '#') {
                q.push({i, j, id++});
            } else {
                grid2[i][j] = 0;
            }
        }
    }
 
    while (!q.empty()) {
        array<int, 3> cur = q.top();
        q.pop();
        int X = cur[0], Y = cur[1], ID = cur[2];
        if (!vis[X][Y]) {
            grid2[X][Y] = ID;
            sz[ID]++;
            col[{Y, ID}]++;
            row[{X, ID}]++;
            vis[X][Y] = true;
        }
        for (int i = 0; i < 4; ++i) {
            int x = X + dx[i];
            int y = Y + dy[i];
            if (valid(x, y) && grid[x][y] == '#' && !vis[x][y]) {
                q.push({x, y, ID});
                grid2[x][y] = ID;
                sz[ID]++;
                col[{y, ID}]++;
                row[{x, ID}]++;
                vis[x][y] = true;
            }
        }
    }
 
    int Mx = max(n, m);
    for (int i = 1; i <= m; ++i) {
        int S{};
        set<int> st;
        for (int j = 1; j <= n; ++j) {
            if (i - 1 >= 1) {
                st.insert(grid2[j][i - 1]);
            }
            if (i + 1 <= m) {
                st.insert(grid2[j][i + 1]);
            }
        }
 
        for (auto j: st) {
            S += sz[j];
            S -= col[{i, j}];
        }
 
        Mx = max(Mx, S + n);
    }
 
    for (int i = 1; i <= n; ++i) {
        int S{};
        set<int> st;
        for (int j = 1; j <= m; ++j) {
            if (i - 1 >= 1) {
                st.insert(grid2[i - 1][j]);
            }
            if (i + 1 <= n) {
                st.insert(grid2[i + 1][j]);
            }
        }
 
        for (auto j: st) {
            S += sz[j];
            S -= row[{i, j}];
        }
        Mx = max(Mx, S + m);
    }
 
    cout << Mx;
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        idx++;
        //cout << "Case " << idx << ": ";
        dowork();
        cout << "\n";
    }
}