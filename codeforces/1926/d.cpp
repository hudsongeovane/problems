#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
#define ui unsigned int

int main() {
    ui y = 2147483647;
    int t;
    cin >> t;
    while (t--) {
        map<ui, ui> numbers;
        int n;
        cin >> n;
        int groups = 0;
        for(int i = 0; i < n; i++) {
            ui tmp;
            cin >> tmp;

            if (numbers.find(~tmp&y) != numbers.end()) {
                numbers[~tmp&y] = numbers[~tmp&y] - 1;
                if (numbers[~tmp&y] == 0) numbers.erase(~tmp&y);

                groups++;
                continue;
            }

            if (numbers.find(tmp) == numbers.end()) {
                numbers[tmp] = 1;
            }
            else {
                numbers[tmp] = numbers[tmp] + 1;
            }
        }

        for(map<ui, ui>::iterator it = numbers.begin(); it != numbers.end(); it++) {
            groups += it->second;
        }
        

        cout << groups << endl;
    }
}