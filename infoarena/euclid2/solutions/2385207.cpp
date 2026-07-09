#include <fstream>

using namespace std;
ifstream cin ("euclid2.in");
ofstream cout ("euclid2.out");
long long n,a,b,i,aux;
int main()
{
    cin>>n;
    for (i=0;i<n;i++)
    {
        cin>>a;
        cin>>b;
        while (a)
        {
            aux=a;
            a=b%a;
            b=aux;
        }
        cout<<b<<'\n';
    }
    return 0;
}
