#include <fstream>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int a,b,t,n,i;

int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a;
        cin>>b;
        if(a<b)
            swap(a,b);
        while(b)
        {
            t=a%b;
            a=b;
            b=t;
        }
        cout << a << '\n';
    }
    return 0;
}
