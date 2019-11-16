#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
	int n, p;
	cin >> n;
	int seats[100] = {};
	bool assigned;
	for (unsigned i = 0; i != n; ++i) {
		cin >> p;
		assigned = false;
		for (unsigned row = 0; row != 100 / 5; ++row) {
			for (unsigned col = 0; col != 5; ++col) {
				if (seats[row * 5 + col] == 0 && col + p <= 5) {
					for (unsigned j = 0; j != p; ++j) {
						seats[row*5 + col + j] = 1;
						cout << row*5 + col + j + 1 << " ";
					}
					cout << endl;	
					assigned = true;
					break;			
				}		
			}
			//	seats[0] = 100;
			if (assigned) { break; }
		}
		if (assigned) { continue; }
		else {
			for (unsigned j = 0; j != 100; ++j) {
				if (seats[j] == 0) {
					seats[j] == 1;
					cout << j + 1 << " ";
					--p;
					if (p==0) { break; }					
				}
			}
			cout << endl;
		}
	}
//	for (auto c: seats)
//		cout << c << " ";
//	cout << endl; 
	
	return 0;	
} 
