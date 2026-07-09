#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("cmmdc.in");
ofstream fout("cmmdc.out");
int euclid(int x,int y)
{
    if (y==0)
    return x;
    else return euclid(y, x%y);
}
int main()
{
    int a,b;
    fin>>a>>b;
    if(euclid(a,b)==1) cout<<"0"<<endl;
    else
    cout<<euclid(a,b);
    return 0;
}
