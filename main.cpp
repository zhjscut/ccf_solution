#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    int r, y, g;
    int light[3];
    cin >> r >> y >> g;
    int n;
    cin >> n;
    //cin >> light[0] >> light[2] >> light[1] >> n;
    int type, time;
    long long total_time = 0;
    int interval[3] = {r, y, g};
    void update(int [3], long long, int &, int &);    
    int sum = light[0] + light[1] + light[2];
    
    for (int i = 0; i != n; ++i) {
        cin >> type >> time;
      //  cout << "before: " << i << " " << type << " " << time << " " << total_time << endl;        
        update(interval, total_time, type, time);
      //  cout << "after: " << i << " " << type << " " << time << endl;
        if (type == 0) { total_time += time; }
        if (type == 1) { total_time += time; }
        if (type == 2) { total_time += time + r; } 
        if (type == 3) { ; } 
    }
    
    cout << total_time;    
    return 0;
}

void update(int interval[3], long long total_time, int &type, int &time)
{
    if (type == 0)
        return;
   // 加上这个会导致很多错误，只剩30分 
  //  int sum = interval[0] + interval[1] + interval[2];
  //  while (total_time > sum)
  //      total_time -= sum;
    
    while (total_time > time) {
      //  cout << total_time << endl;
        total_time -= time; 
        type = (type - 2 + 3) % 3 + 1; // 为了实现3 -> 2, 2 -> 1, 1 -> 3的转换
        time = interval[type - 1];       
    }
    
    time = time - total_time;
   
    return;
}


