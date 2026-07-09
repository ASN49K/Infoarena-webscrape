#include <iostream>
#include <fstream>
#define nmax 1234
#define endl '\n'
using namespace std;

int v[nmax][nmax],a[nmax],b[nmax],sir[nmax],n,m,q ;


int main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");

    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1; i<=m; i++)
        cin>>b[i];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
                v[i][j]=1+v[i-1][j-1];
            else
                v[i][j]=max( v[i-1][j] , v[i][j-1] );

        for(int i=n, j=m; i ;){
                if(a[i]==b[j]){
                sir[q++]=a[i];
                i--,j--;
                }
                else if ( v[i-1][j] < v[i][j-1])
                    j--;
                    else
                        i--;
        }
       cout<<v[n][m]<<endl;

for(int i=q-1;i>=0;i--)
cout<<sir[i]<<" ";

}
