#include <fstream>
#include <iostream>
using namespace std;
int hack(int x,int y)
{
    if(!y) return x;
    return hack(y,x%y);
}
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int t,a,b;
    fin>>t;
    for(int i=1;i<=t;i++)
    {
        fin>>a>>b;
        fout<<hack(a,b)<<endl;
    }
    return 0;
}
