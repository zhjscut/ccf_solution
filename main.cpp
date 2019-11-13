#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    int price = 10;
    int money;
    cin >> money;
    int num = money / price;
    cout << num / 5 * 7 + (num % 5 / 3) * 4 + (num % 5 % 3) << endl;
    
    return 0;
}
