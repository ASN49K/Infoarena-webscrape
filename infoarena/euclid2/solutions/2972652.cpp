#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    int t,a,b,i,aux;
    in>>t;
    for(i=1;i<=t;i++)
    {
        in>>a>>b;
        while(b!=0)
        {
            a%=b;
            aux=a;
            a=b;
            b=aux;
        }
        out<<a<<'\n';
    }
    return 0;
}
