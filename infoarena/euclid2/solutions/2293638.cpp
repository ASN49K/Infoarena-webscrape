#include <iostream>
#include <fstream>
using namespace std;

int euclid(int a,int b)
{
    if(b==0)
        return a;
    return euclid(b,a%b);
}
int main()
{
    int T,a,b;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>T;
    for(int i = 0; i < T; i++)
    {
        fin>>a>>b;
        fout<<euclid(a,b)<<'\n';
    }
    return 0;
}
