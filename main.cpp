#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int num, prev_num;
    cin >> prev_num;
    int cnt = 1;
    for (unsigned i = 1; i != n; ++i) {
        cin >> num;
        if (num != prev_num) {
            ++cnt;
            prev_num = num;
        }
    }
    
    cout << cnt << endl;
    
    return 0;
}



