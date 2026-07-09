#include <iostream>
#include <fstream>
using namespace std;
int cmmdc(int x,int y)
{
    if(!y)
        return x;
    return cmmdc(y,x%y);
}
int main()
{
    int n;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        fin>>x>>y;
        fout<<cmmdc(x,y)<<"\n";
    }
    return 0;
}
