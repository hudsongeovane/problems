#include <iostream>
#include <vector>
#include <map>

#define MP make_pair
using namespace std;

int a[1005][1005];
int n, m;
map< pair < pair<int,int>, int >, bool > dp;


int abs(int a) {
    if (a < 0) return a * (-1);
    else return a;
}

bool is_possible(int start_i, int start_j, int sum) {
    if (start_i > n || start_j > m) return false;
    if (start_i == n-1 && start_j == m-1) return sum == 0;
    if (abs(sum) > ((n-1-start_i)+(m-1-start_j))) return false;
    if (dp.find(MP(MP(start_i,start_j), sum)) != dp.end()) return dp.find(MP(MP(start_i,start_j), sum))->second;
    bool res = is_possible(start_i+1,start_j,sum + a[start_i+1][start_j]) || is_possible(start_i,start_j+1,sum + a[start_i][start_j+1]);
    dp[MP(MP(start_i,start_j),sum)] = res;
    return res;
}

int main() {
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        dp.clear();
        cin >> n >> m;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }

        if((n+m)% 2== 0){
            cout << "NO"<< endl;
            continue;
        }

        if (is_possible(0,0,a[0][0])) {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }

}