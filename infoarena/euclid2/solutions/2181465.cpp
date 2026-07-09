#include <bits/stdc++.h>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

void euclid(int x,int y){
    int z;
    while(y){
        z = x % y;
        x = y;
        y = z;
    }
    out << x << '\n';
}

int main()
{
    int a,b,t;
    in >> t;
    for(int i=0;i<t;i++){
        in >> a >> b;
        euclid(a,b);
    }
    return 0;
}
