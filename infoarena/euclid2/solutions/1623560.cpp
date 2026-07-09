#include <iostream>
#include <fstream>
using namespace std;
int euclid(int a,int b)
{
    if(a<b)return euclid(a,b-a);
    if(a>b)return euclid(a-b,b);
    return a;
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int a,b,n;
    f>>n;
    while(n){
        n--;
        f>>a>>b;
        g<<euclid(a,b)<<endl;
    }
}
