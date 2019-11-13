#include <iostream>
#include <cmath>
using namespace std;

int visits[1000] = {};

int main() {
    int n;
    cin >> n;
    int num;
    for (unsigned i = 0; i != n; ++i) {
        cin >> num;
        visits[num] += 1;
        cout << visits[num] << " ";
    }
    
    return 0;
}
