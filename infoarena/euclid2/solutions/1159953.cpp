#include <fstream>
using namespace std;
int t,a,b;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    fin>>t;
    for (;t;t--)
    {
        fin>>a>>b;
        while (b!=0)
        {
            int c=a%b;
            a=b;
            b=c;
        }
        fout<<a<<endl;
    }
}



































