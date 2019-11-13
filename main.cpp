#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

#include <stdio.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> numbers;
    int num;
    int max, min;
    double mid;

    for (unsigned i = 0; i != n; ++i) {
        cin >> num;
        numbers.push_back(num);
    }
    if (numbers[0] > numbers[n-1]) { max = numbers[0]; min = numbers[n-1]; }
    else { max = numbers[n-1]; min = numbers[0]; }        
    if (n % 2 == 0) { 
        mid = double(numbers[n/2 - 1] + numbers[n/2]) / 2; 
    }
    else { mid = numbers[n/2]; }
    
    if (n % 2 == 0 && (numbers[n/2 - 1] + numbers[n/2]) % 2 == 1)
        printf("%d %.1lf %d", max, mid, min);
    else
        printf("%d %d %d", max, int(mid), min);

    return 0;
}
