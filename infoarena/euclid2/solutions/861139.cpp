#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <stdlib.h>
#include <sstream>

#include <stdio.h>
#define PI 3.1415926535897932384626433832795

using namespace std;


int main() {
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int t;
    cin >> t;
    for (int w = 0; w < t; ++w){
        int a,b;
        cin >> a >> b;
        if (a < b) {
            swap(a,b);
        }
        while (b > 0) {
            a = a - b;
            if (a < b) {
                swap(a,b);
            }
            
        }

        cout << a << endl;
    }
    return 0;
}
