#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int a,b,t;
    fin>>t;
    for(int i=1;i<=t;i++)
    {
        fin>>a>>b;
        int r;
        while(b)
        {
            r=b;
            b=a%b;
            a=r;
        }
        fout<<a;
    }
    return 0;
}
