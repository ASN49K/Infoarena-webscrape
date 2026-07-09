#include <fstream>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int main()
{
    int a, b, c, n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    cin>>a>>b;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    cout<<a<<endl;

    }
}
