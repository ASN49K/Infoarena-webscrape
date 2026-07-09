#include <fstream>

using namespace std;

ifstream cin ("euclid2.in");
ofstream cout ("euclid2.out");

int main()
{
    int n,a,b,aux;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a>>b;
        while (b!=0)
        {
            aux=b;
            b=a%b;
            a=aux;
        }
        cout<<a<<endl;
    }
    return 0;
}
