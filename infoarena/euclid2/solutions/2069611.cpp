#include <iostream>
#include <fstream>
using namespace std;
int cmmdc(int a,int b)
{
    if(b)
        return cmmdc(b,a%b);
    return a;
}
int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int n,a,b;
    in>>n;
    while(n)
    {
        in>>a;
        in>>b;
        a=cmmdc(a,b);
        out<<a<<endl;
        n-=1;
    }
    return 0;
}
