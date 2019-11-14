#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    vector<int> mina, maxa, minb, maxb;
    int n;
    cin >> n;
    int min, max;
    for (unsigned i = 0; i != n; ++i) {
        cin >> min >> max;
        mina.push_back(min); maxa.push_back(max);
    }
    for (unsigned i = 0; i != n; ++i) {
        cin >> min >> max;
        minb.push_back(min); maxb.push_back(max);
    }   
    unsigned ix1 = 0, ix2 = 0;
    int total_time = 0;
    int compute_time(int, int, int, int);    
    while (1) { 
        if (mina[ix1] < maxb[ix2] && minb[ix2] < maxa[ix1]) {
          //  cout << mina[ix1] << " " << maxa[ix1] << " " << minb[ix2] << " " << maxb[ix2] << " ";
          //  cout << compute_time(mina[ix1], maxa[ix1], minb[ix2], maxb[ix2]) << endl;
            total_time += compute_time(mina[ix1], maxa[ix1], minb[ix2], maxb[ix2]);
            if ( ix1 != (n - 1) && mina[ix1 + 1] < maxb[ix2] && minb[ix2] < maxa[ix1 + 1] ) { ++ix1; }
            else if ( ix2 != (n - 1) && mina[ix1] < maxb[ix2 + 1] && minb[ix2 + 1] < maxa[ix1]) { ++ix2; }
            else if ( ix1 != (n - 1) ) { ++ix1; }
            else if ( ix2 != (n - 1) ) { ++ix2; }
            else { break; }
        }

        else if (minb[ix2] >= maxa[ix1]) {
            if ( ix1 == (n - 1) ) { break; }
            else { ++ix1; }
        } 
        else if (mina[ix1] >= maxb[ix2]) {
            if ( ix2 == (n - 1) ) { break; }
            else { ++ix2; }
        }
    } 
    
    cout << total_time << endl;
       
    return 0;
}

int compute_time(int min_a, int max_a, int min_b, int max_b)
{
    if (min_a <= min_b && min_b < max_a && max_a <= max_b) { return (max_a - min_b); }
    else if (min_a <= min_b && max_b <= max_a) { return (max_b - min_b); }
    else if (min_b <= min_a && min_a < max_b && max_b <= max_a) { return (max_b - min_a); }
    else if (min_b <= min_a && max_a <= max_b) { return (max_a - min_a); }
}

