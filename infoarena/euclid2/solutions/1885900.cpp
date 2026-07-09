#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int t;
    fin>>t;
    for(int i=1;i<=t;i++)
    {
        int x,y;
        fin>>x>>y;
        int r=x%y;
        while(r!=0)
        {
            x=y;
            y=r;
            r=x%y;
        }
        fout<<y<<endl;
    }
    return 0;
}
