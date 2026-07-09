#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int euclid(int a, int b){
    if(a < b)
        return euclid(b, a);
    if(b == 0)
        return a;
    return euclid(b, a%b);
}
int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int t, a, b;
    cin>>t;
    for(int i = 1; i <= t; i++) {
        cin>>a>>b;
        cout<<euclid(a, b)<< '\n';
    }
    return 0;
}
