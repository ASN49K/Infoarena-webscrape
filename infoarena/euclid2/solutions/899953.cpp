#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <deque>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

#define nmax

#define ll long long

int cmmdc(int x, int y){
    while(y!=0){
        int rest = x % y;
        x = y; y = rest;
    }
    return x;
}

void rezolva(){
    int t = 0, x , y;
    f >> t;
    for(; t; --t){
        f >> x >> y;
        g << cmmdc(x, y) << "\n";
    }

}

int main(){
    rezolva();

    f.close();
    g.close();

    return 0;
}

