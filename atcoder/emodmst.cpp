#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long n, m, k;
vector< pair< pair<int, int>, long long> > edges;
long long minimum = LLONG_MAX;

int find(vector<int> & s, int i) {
    while(s[i] != i) {  
        s[i] = s[s[i]];  
        i = s[i];  
    }  
    return i;
}
void join(vector<int> & s, int i, int j) {
    int p = find(s, i);
    int q = find(s, j);
    s[p] = s[q];
}

long long calculate_weight(vector<bool> & used) {
    long long sum = 0;
    for(int i = 0; i < used.size(); i++) {
        if (used[i]) sum = (sum + (edges[i].second % k)) % k;
    }
    return sum % k;
}

int ones(vector<bool> &used) {
    return count(used.begin(), used.end(), true);
}

long long backtracking(vector<int> s, vector<bool> used, int start_edge) {
    if (ones(used) == n-1) {
        return min(minimum, calculate_weight(used));
    }
    
    // check if this search can not even find a MST
    if (m-start_edge + ones(used) < n-1) return LLONG_MAX;

    // test if this edge will make a cycle
    if (find(s, edges[start_edge].first.first) == find(s, edges[start_edge].first.second)) {
        minimum = min(minimum, backtracking(s, used, start_edge+1));
        return minimum;
    }
    //not using this edge
    long long avoid_edge = backtracking(s, used, start_edge+1);

    //or using this edge
    used[start_edge] = true;
    join(s, edges[start_edge].first.first, edges[start_edge].first.second);
    minimum = min(minimum, min(backtracking(s, used, start_edge+1), avoid_edge));
    return minimum;
}

int main() {
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        long long f, t, w;
        cin >> f >> t >> w;
        edges.push_back(make_pair(make_pair(f-1, t-1), w));
    }

    vector<int> s(n,-1);
    for(int i = 0; i < n; i++) {
        s[i] = i;
    }

    vector<bool> used(m, false);
    cout << backtracking(s, used, 0) << endl;
}

// https://atcoder.jp/contests/abc328/tasks/abc328_e