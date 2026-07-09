#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n,i,aux,j;
    long a,b;
    bool ok;
    f >> n;
    for (i=1;i<=n;i++)
    {
        f >> a >> b;
        if (a>b)
        {
            aux=a;
            a=b;
            b=aux;
        }
        ok=0;
        for(j=a;j>=2;j--)
        {
            if ((a%j==0)&&(b%j==0))
                {
                    ok=1;
                    break;
                }
            break;
        }
        if(ok==1)
            g << j << endl;
        if(ok==0)
            g << 1 << endl;
    }

f.close();
g.close();
return 0;
}
