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


int cmmmdc(int x, int y){
    for(; y!=0;){
        int aux = y;
        y = x % y;
        x = aux;
    }
    return x;
}

void rezolva(){
    int t= 0;
    f >> t; int x, y;
    for(; t; --t){
        f >> x >> y;
        g << cmmmdc(x, y) << "\n";
    }
}

int main(){
    //citeste();
    rezolva();

    f.close();
    g.close();

    return 0;
}

