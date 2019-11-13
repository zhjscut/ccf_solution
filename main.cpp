#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int num, cnt_numbers[1000] = {};
    for (unsigned i = 0; i != n; ++i) {
        cin >> num;
        cnt_numbers[num] += 1;
    }
    
    int cnt = 0;
    int mid, n_mid;
    for (unsigned i = 0; i != 1000; ++i) {
        cnt += cnt_numbers[i];
        if (cnt >= n / 2 + 1) {
            mid = i;
            n_mid = cnt_numbers[i];
            break;
        }
    }
    
    if (n % 2 == 1 && n_mid % 2 == 1) { cout << mid << endl; }
    else if (n % 2 == 1 && n_mid % 2 == 0) { cout << -1 << endl; }
    else if (n % 2 == 0 && n_mid % 2 == 1) { cout << -1 << endl; }    
    else if (n % 2 == 0 && n_mid % 2 == 0) { cout << mid << endl; }    
        
    return 0;
}
