#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
	double num, ans;
	cin >> num;
	if (num <= 3500) { ans = num; }
	else if (num <= 4955 ) { ans = (num - 3500) / 0.97 + 3500; }
	else if (num <= 7655 ) { ans = (num - 4955) / 0.9 + 5000; }
	else if (num <= 11255 ) { ans = (num - 7655) / 0.8 + 8000; }
	else if (num <= 30755 ) { ans = (num - 11255) / 0.75 + 12500; }
	else if (num <= 44755 ) { ans = (num - 30755) / 0.7 + 38500; }
	else if (num <= 61005 ) { ans = (num - 44755) / 0.65 + 58500; }
	else { ans = (num - 61005) / 0.55 + 83500; }
	
	cout << int(ans) << endl;
	return 0; 
} 
