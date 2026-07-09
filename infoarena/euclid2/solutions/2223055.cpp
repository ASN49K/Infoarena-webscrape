#include <fstream>
///https://infoarena.ro/problema/euclid2
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    long long a,b;
    int T;
    fin>>T;
    for(int i=1;i<=T;i++)
    {
        fin>>a>>b;
        while(a*b!=0)
            if(a<b)
                b%=a;
            else
                a%=b;
        if(a>b)fout<<a<<endl;
        else fout<<b<<endl;
    }
}
