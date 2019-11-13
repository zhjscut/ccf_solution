#include <iostream>
#include <cmath>
using namespace std;

int cnt_numbers[10000] = {};

int main() {
    int n;
    cin >> n;
    int num;
    for (unsigned i = 0; i != n; ++i) {
        cin >> num;
        cnt_numbers[num] += 1;
    }

    int max_cnt = 0, max_num = 0;
    for (unsigned i = 10000 - 1; i != -1; --i) {
        if (cnt_numbers[i] >= max_cnt) {
            max_cnt = cnt_numbers[i];
            max_num = i;
        }
    }    
    
    cout << max_num << endl;        
    
    return 0;
}
