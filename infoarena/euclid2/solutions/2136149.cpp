#include <bits/stdc++.h>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int x, int y){
    while (y){
        int r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int a,b,m;

int main()
{
    in >> m;
    for (int i =1; i<=m; i++){
        in >> a >> b;
        out << euclid(a,b) << endl;
    }
    return 0;
}
