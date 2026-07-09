#include <fstream>

using namespace std;
ifstream cin ("euclid2.in");
ofstream cout ("euclid2.out");
int main()
{
    int n,a,b,i,r,aux;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>a>>b;
        if(a>b)
        {
            aux=a;
            a=b;
            b=aux;
        }
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        cout<<a<<'\n';
    }
    return 0;
}
