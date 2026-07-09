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
    int t;
    cin >> t;
    for (int w = 0; w < t; ++w){
        int a,b;
        cin >> a >> b;
        if (a < b) {
            swap(a,b);
        }
        int p;
        while (b > 0) {
            p = a%b;
            a = b;
            b = p;
        }
        cout << a;
    }
    return 0;
}
