#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <fstream>
#include <set>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <stack>
#include <string.h>
#include <stdio.h>
#include <limits.h>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a, int b){
    int c;
    while(b > 0){
        c = b;
        b = a % b;
        a = c;
    }
    return a;
}

int main()
{
    int i, j;
    f >> i >> j;
    g << cmmdc(i, j);

    return 0;
}
