#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct Child {
	int id;
	Child *prev;
	Child *next;		
};
	

int main() {
	int n, k;
	cin >> n >> k;
	vector<Child> vchild;
	for (int i = 0; i != n; ++i) {
		Child child = Child{i + 1};
		vchild.push_back(child);
	}
	for (int i = 0; i != n; ++i) {
		vchild[i].next = &vchild[(i + 1) % n]; 	
		vchild[i].prev = &vchild[(i - 1 + n) % n];
	}
	//for (auto c: vchild)
	  //  cout << "id: " << c.id << "prev: " << c.prev->id << "next: " << c.next->id << endl;
	int cnt = 1, nn = n;
	Child *pchild = &vchild[0], *tmp_pchild = 0;
	
	while (nn != 1) {
		//cout << nn << endl;
		if (cnt % k == 0 || cnt % 10 == k) {
		   // cout << pchild->id << " out." << endl;
			pchild->prev->next = pchild->next;
			pchild->next->prev = pchild->prev;
			--nn;
		}
		pchild = pchild->next;
		++cnt;
	}
	
	cout << pchild->id << endl;

    return 0;
}

