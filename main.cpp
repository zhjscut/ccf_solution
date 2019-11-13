#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    int cnt_numbers[10000] = {};
    int n;
    cin >> n;    
    int num;
    for (unsigned i = 0; i != n; ++i) {
        cin >> num;
        if (cnt_numbers[num] == 1) { // has the same two numbers
            cout << 0 << endl;
            return 0;
        }
        cnt_numbers[num] = 1;
    }
    int min = 1e+8;
    int prev_num = -1;
    for (unsigned i = 0; i != 10000; ++i) {    
        if (cnt_numbers[i] == 0) { continue; }
        else {
            if (prev_num == -1) { prev_num = i; continue;} // init left number and right number
            if (i - prev_num < min) { min = i - prev_num;}
            prev_num = i;
        }
        if (min == 1) {
            cout << 1 << endl;
            return 0;
        }
    }
    cout << min << endl;

    
    return 0;
}
