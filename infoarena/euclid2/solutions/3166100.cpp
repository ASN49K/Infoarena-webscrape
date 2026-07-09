#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int T,a,b,i,d;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>T;
    for(int i=1; i<=T;i++)
    {
        fin>>a;
        fin>>b;
        while(a!=b)
        {
            if(a>b)
            {
                a=a-b;
            }
            else
            {
                b=b-a;
            }
        }
        fout<<a<<'\n';

    }
    return 0;
}
