#include <iostream>
#include <cmath>
using namespace std;

int nums[2001] = {};

int main() {
    int n;
    cin >> n;
    int num;
    int cnt = 0;
    for (unsigned i = 0; i != n; ++i) {
        cin >> num;
        nums[num + 1000] += 1;
    }
    for (unsigned i = 0; i != 1000; ++i) {
        if (nums[i] == 1 && nums[2000 - i] == 1)
            ++cnt;
    }    
    
    cout << cnt << endl;
    
    return 0;
}
