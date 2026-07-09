#include <iostream>
#include <fstream>
using namespace std;
int a,b,r,t,i,j;
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>t;
    a=0;
    b=0;
    for(i=1;i<=t;i++)
    {
        fin>>a>>b;
        while(b>0)
        {
            r = a%b;
            a = b;
            b = r;
        }
        fout<<a<<"\n";
    }
    fout.close();
    fin.close();
    return 0;
}
