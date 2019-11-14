#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    int n, L, time;
    cin >> n >> L >> time;
    vector<int> speeds(n, 1);
    vector<int> positions;
    int tmp;
    for (unsigned i = 0; i != n; ++i) {
        cin >> tmp;
        positions.push_back(tmp);    
    }
    bool is_collide(int, vector<int> &);
  //  cout << "t=0: ";
  //  for (auto pos: positions)
  //      cout << pos << " ";
  //  cout << endl;      
    for (int t = 0; t != time; ++t) {
        for (unsigned i = 0; i != n; ++i)
            positions[i] += speeds[i];
        for (unsigned i = 0; i != n; ++i) {
            if (positions[i] == 0) { speeds[i] = 1; }
            else if (positions[i] == L) { speeds[i] = -1; }
            else if ( is_collide(positions[i], positions) ) { speeds[i] = -speeds[i]; } 
        }
    //    cout << "t=" << t+1 << ": ";
    //    for (auto pos: positions)
    //        cout << pos << " ";
    //    cout << endl;        
    }
    
    for (auto pos: positions)
        cout << pos << " ";
    cout << endl;
    
    return 0;
}


bool is_collide(int pos, vector<int> &vpos)
{
    int cnt = 0;
    for (auto p: vpos)    
        if (pos == p) { // cnt必定不小于1，因为vpos里面有自己
            ++cnt;
            if (cnt == 2)
                return true;
        }
            
    return false;
}
