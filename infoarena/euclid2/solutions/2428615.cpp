#include <iostream>
#include <fstream>
using namespace std;
int cmmmdc(int x,int y)
{
    int i=y,j=x,r;
    if(x>y)
    {
        i = x;
        j = y;
    }
    r = i%j;
    while(r!=0)
    {
        i = j;
        j = r;
        r = i%j;
    }
    return j;
}
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int t;
    fin>>t;
    for(int i = 0,x,y;i<t;i++)
    {
        fin>>x>>y;
        fout<<cmmmdc(x,y)<<endl;
    }
    return 0;
}
