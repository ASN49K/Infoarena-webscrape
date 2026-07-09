#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int v[100003][2],i,j,n,h[100003];
    cin>>n;
    for(i=1; i<=n; i++) cin>>v[i][1]>>v[i][2];
    for(i=1; i<=n; i++)
    {
        if(v[i][1]>v[i][2])j=v[i][2]-1;
        else j=v[i][1]-1;
        while(v[i][1]%j!=0 && v[i][2]%j!=0 || j!=1) j--;
            h[i]=j;
    }
    for(i=1; i<=n; i++) cout<<h[i]<<' ';
    return 0;
}
