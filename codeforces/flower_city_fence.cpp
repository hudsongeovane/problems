#include <iostream>
#include <set>
#include <string>
#include <vector>


using namespace std;

int main() {
    int testcases;
    cin >> testcases;
    while (testcases--) {
        int s;
        cin >> s;
        vector<long long int> fence;
        for(long long int i = 0; i < s; i++) {
            long long int x;
            cin >> x;
            fence.push_back(x);
        }
        if (fence[0] != fence.size()) {
            cout << "NO" << endl;
            continue;
        }

        vector<long long int> transp = vector<long long int>(fence[0]+1, 0);
        bool error = false;
        for(long long int v: fence) {
            transp[0]++;
            if (v > fence[0]) {
                error = true;
                break;
            }
            transp[v]--;
        }
        vector<long long int> new_fence;
        if (!error){
            int continuing_value = 0;
            for(long long int i = 0; i < transp.size()-1; i++) {
                continuing_value += transp[i];
                new_fence.push_back(continuing_value);
            }
        }
        if (!error && fence == new_fence) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}
