#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    long t;
    long a,b;
    fin>>t;
    while(t!=0)
    {
        fin>>a>>b;
        long e;
        while(b!=0)
        {
        e=b;
        b=a%b;
        a=e;
        }
        fout<<a<<endl;
        t--;
    }
    fin.close();
    fout.close();
    return 0;
}
