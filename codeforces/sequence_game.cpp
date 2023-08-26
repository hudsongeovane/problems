#include <iostream>
#include <set>
#include <string>
#include <vector>


using namespace std;

int main() {
    int testcases;
    cin >> testcases;
    while (testcases) {
        testcases--;
        int n;
        cin >> n;
        vector<int> b;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            b.push_back(x);
        }
        
        vector<int> res;
        res.push_back(b[0]);
        for(int i = 1; i < n; i++) {
            if (b[i-1] > b[i]) res.push_back(b[i]);
            res.push_back(b[i]);
        }

        cout << res.size() << endl;

        for (int i = 0; i < res.size(); i++) {
            if (i == res.size()-1) {
                cout << res[i] << endl;
            }
            else {
                cout << res[i] << ' ';
            }
        }
    }
}