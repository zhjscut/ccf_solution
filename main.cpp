#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sale_2d_ago, sale_1d_ago, sale_today;
    int cnt = 0;
    for (unsigned i = 0; i != n; ++i) {
        if (i == 0) { cin >> sale_2d_ago; continue; }
        else if (i == 1) { cin >> sale_1d_ago; continue; }
        cin >> sale_today;
        if ( ( (sale_1d_ago > sale_2d_ago) && sale_1d_ago > sale_today) ||
             (sale_1d_ago < sale_2d_ago && sale_1d_ago < sale_today) )
             ++cnt;
        sale_2d_ago = sale_1d_ago;
        sale_1d_ago = sale_today;
    }
    
    cout << cnt << endl;
    
    return 0;
}



