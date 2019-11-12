#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    int score = 1, total_score = 0;
    int status;
    while (cin >> status) {
        if (status == 0) {
            cout << total_score;
            break;
        }
        else if (status == 1) {
            score = 1;
            total_score += score;
        }
        else if (status == 2) {
            if (score == 1 || total_score == 0)
                score = 2;
            else
                score += 2;
            total_score += score;
        }
    }
        
    return 0;
}
