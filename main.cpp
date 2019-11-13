#include <iostream>
#include <cmath>
using namespace std;

int nums[10000] = {};

int main() {
    int n;
    cin >> n;
    int num;
    int cnt = 0;
    for (unsigned i = 0; i != n; ++i) {
        cin >> num;
        nums[num] += 1;
    }
    for (unsigned i = 0; i != 10000 - 1; ++i) {
        if (nums[i] == 1 && nums[i+1] == 1)
            ++cnt;
    }    
    
    cout << cnt << endl;
    
    return 0;
}
