#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int f(int a,int b)
{
    if(b==0)
        return a;
    else
        return f(b,a%b);
}
int main()
{
    int n,a,b,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a>>b;
        cout<<f(a,b)<<"\n";
    }
    cin.close();
    cout.close();
    return 0;
}
