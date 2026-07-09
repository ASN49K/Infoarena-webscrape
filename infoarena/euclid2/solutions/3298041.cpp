#include <fstream>
using namespace std;
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int n,a,b;
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>a>>b;
        int rest;
        while(b)
        {
            rest=a%b;
            a=b;
            b=rest;
        }
        fout<<a<<'\n';
    }
    return 0;
}
