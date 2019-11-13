#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

#include <stdio.h>

using namespace std;

int main() {
    int num_trees, turns;
    cin >> num_trees;
    vector<int> apples_trees;
    vector<bool> is_drop;
    int apples_tree, decrease_one_turn;
    for (unsigned i = 0; i != num_trees; ++i) {
        cin >> turns;
        cin >> apples_tree;
        apples_trees.push_back(apples_tree);
        is_drop.push_back(false);
        for (unsigned j = 0; j != turns - 1; ++j) { // 第一个数值是苹果初始数量，不是疏果数
            cin >> decrease_one_turn;
            if (decrease_one_turn > 0) { // 正数，表示重新确认树上苹果数量
                if (decrease_one_turn < apples_trees[i]) {// 说明除了疏果之外，还有自然掉落，才会导致数量不相等
                    is_drop[i] = true;
                }
                apples_trees[i] = decrease_one_turn;
            }
            else // 负数，表示疏果数量
                apples_trees[i] += decrease_one_turn; 
        }
    }
    
    int sum = 0;
    for (auto n: apples_trees)
        sum += n;
        
    int drop_trees = 0;
    for (auto b: is_drop)
        drop_trees += b;
        
    int continuous_drop = 0;
    for (unsigned i = 0; i != num_trees; ++i) {
        if (is_drop[(i - 1 + num_trees) % num_trees] && is_drop[i] && is_drop[(i + 1) % num_trees])
            ++continuous_drop;    
    }
    
    cout << sum << " " << drop_trees << " " << continuous_drop << endl;
        
    
    return 0;
}
