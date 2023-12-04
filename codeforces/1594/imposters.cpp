#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define MP make_pair

using namespace std;

// pair -> idx - team
vector< vector< pair<int, int> > > adj;
vector<int> visited;
bool error = false;
int crew, imp;


void dfs(int id, int mark) {
    visited[id] = mark;
    if (mark == 1) imp++;
    else crew++;
    for(auto x: adj[id]) {
        if (visited[x.first] == -1) {
            dfs(x.first, mark^x.second);
        }
        else if ((mark && x.second == visited[x.first]) || (!mark && x.second != visited[x.first])) {
            error = true;
            return;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, n_info;
        cin >> n >> n_info;
        adj = vector< vector< pair<int, int> > >(n, vector< pair<int, int> >());
        int ans = 0;
        error = false;
        visited = vector<int>(n, -1);
        for(int i = 0; i < n_info; i++) {
            int f, t;
            string team;
            cin >> f >> t >> team;
            adj[f-1].push_back(MP(t-1, team[0] == 'c' ? 0 : 1));
            adj[t-1].push_back(MP(f-1, team[0] == 'c' ? 0 : 1));
        }

        for(int x = 0; x < n; x++) {
            crew = 0;
            imp = 0;
            if (visited[x] == -1) {
                dfs(x, 1);
            }
            if (error) {
                ans = -1;
                break;
            }
            ans += max(crew, imp);
        }
        cout << ans << endl;
    }
}