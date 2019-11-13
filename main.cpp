#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    int n_friends = 0;
    int n_cakes, min_weight;
    int weight, weight_i;
    cin >> n_cakes >> min_weight;
    int i_cake = 0;
    while (i_cake != n_cakes) {
        if (weight == 0) {
            n_friends += 1;
            cin >> weight;
        }
        else {
            cin >> weight_i;  
            weight += weight_i;                      
        }
        if (weight >= min_weight)
            weight = 0;
        ++i_cake;
    }
    cout << n_friends << endl;
    
    return 0;
}
