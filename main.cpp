#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    int trees, epochs;
    cin >> trees >> epochs;
    cin.get(); // remove the '\n' of the first line
    istringstream iss;
    vector<int> apple_each_tree;
    vector<int> decrease_each_tree; // number of apples during the decreasing process
    int dec_i; // number of apples decreased in the ith epoch
    int begin_each_tree; // number of apples before the decreasing process
    string line;
    while (getline(cin, line)) {
        iss.clear(); iss.str(line);
        iss >> begin_each_tree;
        apple_each_tree.push_back(begin_each_tree);
        int remain = 0;
        while (iss >> dec_i) {
            remain += dec_i;
        }
        decrease_each_tree.push_back(-remain); // revert negative number to a positive one
    }
    int max = decrease_each_tree[0], max_id = 1;
    for (int ix = 1; ix != epochs; ++ix) {
        if (decrease_each_tree[ix] > max) {
            max = decrease_each_tree[ix];
            max_id = ix + 1;
        }
    }
    int sum = 0;
    for (auto num: apple_each_tree) {
        sum += num;
    }
    for (auto num: decrease_each_tree) {
        sum -= num;
    }
    cout << sum << " " << max_id << " " << max << endl;  
    
    return 0;
}

