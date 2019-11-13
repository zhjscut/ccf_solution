#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

#include <stdio.h>

using namespace std;

int main() {
    int num_trees, turns;
    cin >> num_trees >> turns;
    vector<int> apples_trees;
    vector<int> decrease_trees;
    int apples_tree, decrease_one_turn;
    for (unsigned i = 0; i != num_trees; ++i) {
        cin >> apples_tree;
        apples_trees.push_back(apples_tree);
        decrease_trees.push_back(0);
        for (unsigned j = 0; j != turns; ++j) {
            cin >> decrease_one_turn;
            decrease_trees[i] += decrease_one_turn; // 负数
        }
    }
    
    int max_decrease = 0;
    unsigned max_ix;
    for (unsigned i = num_trees - 1; i != -1; --i) {
        if (-decrease_trees[i] >= max_decrease) {
            max_decrease = -decrease_trees[i];
            max_ix = i;
        }
            
    }
    
    int sum = 0;
    for (auto n: apples_trees)
        sum += n;
    for (auto n: decrease_trees)
        sum += n;
    
    cout << sum << " " << max_ix + 1 << " " << max_decrease << endl;
        
    
    return 0;
}
