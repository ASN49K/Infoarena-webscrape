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

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main() {
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int t;
    cin >> t;
       int a,b;
 
    for (int w = 0; w < t; ++w){
        cin >> a >> b;


        printf("%d\n", gcd(A, B));
    }
    return 0;
}
