#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int max, min;
    double mid;
    int num;
    if (n % 2 == 1) {
        int mid_ix = n / 2;
        for (unsigned i = 0; i != n; ++i) {
            cin >> num;
            if (i == 0) { max = num; }
            if (i == n - 1) { min = num; }
            if (i == mid_ix) { mid = num; }
        }    
    }
    else if (n % 2 == 0) {
        int mid_ix1 = n / 2, mid_ix2 = mid_ix1 - 1;
        int mid1, mid2;
        for (unsigned i = 0; i != n; ++i) {
            cin >> num;
            if (i == 0) { max = num; }
            if (i == n - 1) { min = num; }
            if (i == mid_ix1) { mid1 = num; }
            if (i == mid_ix2) { mid2 = num; }            
        } 
        mid = double(mid1 + mid2) / 2;
    }
    if (min > max) {
        int tmp = max;
        max = min;
        min = tmp;
    }
    cout << max << " " << mid << " " << min << endl;
    return 0;
}
