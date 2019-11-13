#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int prev_price, today_price;
    cin >> prev_price;
    int diff, max_diff = 0;
    for (unsigned i = 1; i != n; ++i) {
        cin >> today_price;
        diff = abs(today_price - prev_price);
        if (diff > max_diff) { max_diff = diff; }
        prev_price = today_price;
    }
    cout << max_diff << endl;
            
    return 0;
}
