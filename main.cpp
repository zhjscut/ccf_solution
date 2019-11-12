#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    int prices[1000], new_prices[1000];
    int n;
    cin >> n;    
    for (unsigned i = 0; i != n; ++i)
        cin >> prices[i];
    new_prices[0] = int(double(prices[0] + prices[1]) / 2);
    for (unsigned i = 1; i != n-1; ++i)
        new_prices[i] = int(double(prices[i-1] + prices[i] + prices[i+1]) / 3);
    new_prices[n-1] = int(double(prices[n-2] + prices[n-1]) / 2);
    
    for (unsigned i = 0; i != n; ++i)
        cout << new_prices[i] << " ";
    return 0;
}
