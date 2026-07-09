#include <fstream>

using namespace std;
ifstream cin("euclid2.in.in");
ofstream cout("euclid2.in.out");
int mi(int a,int b)
{
    int min;
    if(a<b)
        min=a;
    else
        min=b;
    return min;
}
int cmmdc(int a,int b)
{
    int i,sol=0;
    for(i=2;i<=mi(a,b);i++)
    {
        if(a%i==0 and b%i==0)
            sol=i;
    }
    return sol;
}
int main()
{
    int n,i,a,b;
    cin>>n;
    for(i=1;i<=n;i++)
    {
    cin>>a>>b;
    cout<<cmmdc(a,b)<<"\n";
    }
    cin.close();
    cout.close();
    return 0;
}
