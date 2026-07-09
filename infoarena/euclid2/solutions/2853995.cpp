#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int a,int b)
{
    while(b)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main(){
    int n;
    in>>n;
    for(int i=1;i<=n;++i,out<<'\n')
    {
        int x,y;
        in>>x>>y;
        out<<euclid(x,y);
    }
    return 0;
}
