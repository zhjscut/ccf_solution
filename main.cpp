#include <iostream>
#include <cmath>
using namespace std;
int matrix[1000][1000] = {};
int main() {

    int row, col;
    cin >> row >> col;
    for (unsigned i = 0; i < row; ++i) {
        for (unsigned j = 0; j < col; ++j) {
            cin >> matrix[i][j];
        }
    }
    for (unsigned j = col - 1; j < -1; --j) {
        for (unsigned i = 0; i < row; ++i) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
