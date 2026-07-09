#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int T,a,b;
int euclid(int a, int b)
{
    if(b==0)
        return a;
    return euclid(b,a%b);
}
int main()
{
    fin>>T;
    for(int i=1 ; i<=T; ++I)
    {
        fin>>a>>b;
        fout<<euclid(a,b)<<endl;
    }
    return 0;
}
