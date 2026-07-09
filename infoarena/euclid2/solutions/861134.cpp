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

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main() {
    int t;
    in >> t;
    for (int w = 0; w < t; ++w){
        int a,b;
        in >> a >> b;
        if (a < b) {
            swap(a,b);
        }
        int p;
        while (b > 0) {
            p = a%b;
            a = b;
            b = p;
        }
        out << a;
    }
    return 0;
}
