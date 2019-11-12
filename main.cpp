#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    int r, y, g;
    cin >> r >> y >> g;
    int n;
    cin >> n;
    int type, time;
    int total_time = 0;
    for (unsigned i = 0; i != n; ++i) {
        cin >> type >> time;
        if (type == 0) { total_time += time; }
        if (type == 1) { total_time += time; }
        if (type == 2) { total_time += time + r; } 
        if (type == 3) { ; } 
    }
    cout << total_time;    
    return 0;
}
