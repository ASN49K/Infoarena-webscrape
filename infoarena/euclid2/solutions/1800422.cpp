#include <fstream>
using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int a,b,rest,t;
    fin>>t;
    for(int i=1;i<=t;i++)
    {
        fin>>a>>b;
        while(b)
        {
            rest=a%b;
            a=b;
            b=rest;
        }
        fout<<a<<"\n";
    }
    return 0;
}
