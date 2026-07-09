#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int a,b,t,i;
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>a>>b;
        while(a!=b)
        {
            if(a>b)
                a=a-b;
            else
                b=b-a;
        }
        fout<<a<<"\n";
    }
    fin.close();
    fout.close();
    return 0;
}
