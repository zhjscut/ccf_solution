#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

#include <stdio.h>

using namespace std;

int main() {
  //  int num1, num2, num3, num4;
//    char ch1, ch2, ch3;
    int num[4];
    char ch[3];
    int n;
    cin >> n;
    int ans;
    int compute(int num[4], char ch[3]); 
   // cin >> num1 >> ch1 >> num2 >> ch2 >> num3 >> ch3 >> num4;   
    //cout << num1 << " " << ch1 << " " << num2 << " " << ch2 << " " << num3 << " " << ch3 << " "
      //   << num4 << endl;     
    for (unsigned i = 0; i != n; ++i) {
        cin >> num[0] >> ch[0] >> num[1] >> ch[1] >> num[2] >> ch[2] >> num[3];  
       // cout << num[0]<< " " << ch[0] << " " << num[1] << " " << ch[1] << " " << num[2] << " " 
         //    << ch[2] << " " << num[3] << endl;  
        
        ans = compute(num, ch);             
        /*
        ans = num[0];
        for (unsigned j = 0; j != 3; ++j) {
            if (ch[j] == '+') { ans += num[j + 1]; }
            else if (ch[j] == '-') { ans -= num[j + 1]; }
            else { ; }
        }
        */
        if (ans == 24)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;        
    }

    
    return 0;
}

int compute(int num[4], char ch[3]) 
{   
    int ans;
    if (ch[0] == '+') {
        if (ch[1] == '+') {
            if (ch[2] == '+') {
                ans = num[0] + num[1] + num[2] + num[3];
            } else if (ch[2] == '-') {
                ans = num[0] + num[1] + num[2] - num[3];
            } else if (ch[2] == 'x') {
                ans = num[0] + num[1] + num[2] * num[3];
            } else if (ch[2] == '/') {
                ans = num[0] + num[1] + num[2] / num[3];
            }
        } else if (ch[1] == '-') {
            if (ch[2] == '+') {
                ans = num[0] + num[1] - num[2] + num[3];
            } else if (ch[2] == '-') {
                ans = num[0] + num[1] - num[2] - num[3];
            } else if (ch[2] == 'x') {
                ans = num[0] + num[1] - num[2] * num[3];
            } else if (ch[2] == '/') {
                ans = num[0] + num[1] - num[2] / num[3];
            }
        } else if (ch[1] == 'x') {
            if (ch[2] == '+') {
                ans = num[0] + num[1] * num[2] + num[3];
            } else if (ch[2] == '-') {
                ans = num[0] + num[1] * num[2] - num[3];
            } else if (ch[2] == 'x') {
                ans = num[0] + num[1] * num[2] * num[3];
            } else if (ch[2] == '/') {
                ans = num[0] + num[1] * num[2] / num[3];
            }
        } else if (ch[1] == '/') {
            if (ch[2] == '+') {
                ans = num[0] + num[1] / num[2] + num[3];
            } else if (ch[2] == '-') {
                ans = num[0] + num[1] / num[2] - num[3];
            } else if (ch[2] == 'x') {
                ans = num[0] + num[1] / num[2] * num[3];
            } else if (ch[2] == '/') {
                ans = num[0] + num[1] / num[2] / num[3];
            }
        }
    } else if (ch[0] == '-') {
        if (ch[1] == '+') {
            if (ch[2] == '+') {
                ans = num[0] - num[1] + num[2] + num[3];
            } else if (ch[2] == '-') {
                ans = num[0] - num[1] + num[2] - num[3];
            } else if (ch[2] == 'x') {
                ans = num[0] - num[1] + num[2] * num[3];
            } else if (ch[2] == '/') {
                ans = num[0] - num[1] + num[2] / num[3];
            }
        } else if (ch[1] == '-') {
            if (ch[2] == '+') {
                ans = num[0] - num[1] - num[2] + num[3];
            } else if (ch[2] == '-') {
                ans = num[0] - num[1] - num[2] - num[3];
            } else if (ch[2] == 'x') {
                ans = num[0] - num[1] - num[2] * num[3];
            } else if (ch[2] == '/') {
                ans = num[0] - num[1] - num[2] / num[3];
            }
        } else if (ch[1] == 'x') {
            if (ch[2] == '+') {
                ans = num[0] - num[1] * num[2] + num[3];
            } else if (ch[2] == '-') {
                ans = num[0] - num[1] * num[2] - num[3];
            } else if (ch[2] == 'x') {
                ans = num[0] - num[1] * num[2] * num[3];
            } else if (ch[2] == '/') {
                ans = num[0] - num[1] * num[2] / num[3];
            }
        } else if (ch[1] == '/') {
            if (ch[2] == '+') {
                ans = num[0] - num[1] / num[2] + num[3];
            } else if (ch[2] == '-') {
                ans = num[0] - num[1] / num[2] - num[3];
            } else if (ch[2] == 'x') {
                ans = num[0] - num[1] / num[2] * num[3];
            } else if (ch[2] == '/') {
                ans = num[0] - num[1] / num[2] / num[3];
            }
        }
    } else if (ch[0] == 'x') {
        if (ch[1] == '+') {
            if (ch[2] == '+') {
                ans = num[0] * num[1] + num[2] + num[3];
            } else if (ch[2] == '-') {
                ans = num[0] * num[1] + num[2] - num[3];
            } else if (ch[2] == 'x') {
                ans = num[0] * num[1] + num[2] * num[3];
            } else if (ch[2] == '/') {
                ans = num[0] * num[1] + num[2] / num[3];
            }
        } else if (ch[1] == '-') {
            if (ch[2] == '+') {
                ans = num[0] * num[1] - num[2] + num[3];
            } else if (ch[2] == '-') {
                ans = num[0] * num[1] - num[2] - num[3];
            } else if (ch[2] == 'x') {
                ans = num[0] * num[1] - num[2] * num[3];
            } else if (ch[2] == '/') {
                ans = num[0] * num[1] - num[2] / num[3];
            }
        } else if (ch[1] == 'x') {
            if (ch[2] == '+') {
                ans = num[0] * num[1] * num[2] + num[3];
            } else if (ch[2] == '-') {
                ans = num[0] * num[1] * num[2] - num[3];
            } else if (ch[2] == 'x') {
                ans = num[0] * num[1] * num[2] * num[3];
            } else if (ch[2] == '/') {
                ans = num[0] * num[1] * num[2] / num[3];
            }
        } else if (ch[1] == '/') {
            if (ch[2] == '+') {
                ans = num[0] * num[1] / num[2] + num[3];
            } else if (ch[2] == '-') {
                ans = num[0] * num[1] / num[2] - num[3];
            } else if (ch[2] == 'x') {
                ans = num[0] * num[1] / num[2] * num[3];
            } else if (ch[2] == '/') {
                ans = num[0] * num[1] / num[2] / num[3];
            }
        }
    } else if (ch[0] == '/') {
        if (ch[1] == '+') {
            if (ch[2] == '+') {
                ans = num[0] / num[1] + num[2] + num[3];
            } else if (ch[2] == '-') {
                ans = num[0] / num[1] + num[2] - num[3];
            } else if (ch[2] == 'x') {
                ans = num[0] / num[1] + num[2] * num[3];
            } else if (ch[2] == '/') {
                ans = num[0] / num[1] + num[2] / num[3];
            }
        } else if (ch[1] == '-') {
            if (ch[2] == '+') {
                ans = num[0] / num[1] - num[2] + num[3];
            } else if (ch[2] == '-') {
                ans = num[0] / num[1] - num[2] - num[3];
            } else if (ch[2] == 'x') {
                ans = num[0] / num[1] - num[2] * num[3];
            } else if (ch[2] == '/') {
                ans = num[0] / num[1] - num[2] / num[3];
            }
        } else if (ch[1] == 'x') {
            if (ch[2] == '+') {
                ans = num[0] / num[1] * num[2] + num[3];
            } else if (ch[2] == '-') {
                ans = num[0] / num[1] * num[2] - num[3];
            } else if (ch[2] == 'x') {
                ans = num[0] / num[1] * num[2] * num[3];
            } else if (ch[2] == '/') {
                ans = num[0] / num[1] * num[2] / num[3];
            }
        } else if (ch[1] == '/') {
            if (ch[2] == '+') {
                ans = num[0] / num[1] / num[2] + num[3];
            } else if (ch[2] == '-') {
                ans = num[0] / num[1] / num[2] - num[3];
            } else if (ch[2] == 'x') {
                ans = num[0] / num[1] / num[2] * num[3];
            } else if (ch[2] == '/') {
                ans = num[0] / num[1] / num[2] / num[3];
            }
        }
    }
    
    return ans;
}


