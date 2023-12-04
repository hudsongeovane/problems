#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

pair<int,  set<int>> compute(string s, set<int> numbers, char l, int div) {
    if (s.compare(string(s.length(), l)) == 0) return make_pair(numbers.size(), numbers);
    if (div > s.length()) {
        return make_pair(99999999, set<int>());
    }
    for(int i = 0; i < s.length(); i++) {
        if (s[i] != l && (i+1)%div != 0) {
            set<int> n_numbers = numbers;
            n_numbers.insert(div);
            
            string new_s = s;
            for(int j = 0; j < s.length(); j++) {
                if ((j+1)%div != 0) new_s[j] = l;
            }

            pair<int, set<int>> without = compute(s, numbers, l, div+1);
            pair<int, set<int>> with = compute(new_s, n_numbers, l, div+1);

            if (with.first < without.first) return with;
            return without;
        }
    }
    return make_pair(99999999, set<int>());
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a;
        char l;
        cin >> a >> l;
        string s;
        cin >> s;

        string finish(a, l);

        int div = s.length();
        pair<int, set<int>> numbers = compute(s, set<int>(), l, 2);

        cout << numbers.first << endl;
        for(int a: numbers.second) {
            cout << a << " ";
        }
        if (numbers.second.size()) cout << endl;
    }
}