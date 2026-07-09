#include <fstream>
#include <cstring>
#include <algorithm>
#include <stack>
#define dim 1030
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,i,j,a[dim],b[dim],c[dim][dim];
stack<int> S;

int main(){

        f>>n>>m;
        for(i=1;i<=n;i++)
        f>>a[i];
        for(j=1;j<=m;j++)
        f>>b[j];

        memset(c,0,sizeof(c));
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
             if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
             else c[i][j]=max(c[i-1][j],c[i][j-1]);

        i=n,j=m;
        g<<c[n][m]<<"\n";
        while(c[i][j]!=0)
        {
            if(a[i]==b[j]) S.push(a[i]),i--,j--;
            else if(c[i][j-1]>c[i-1][j]) j--;
                 else i--;
        }

        while(!S.empty())
        g<<S.top()<<" ",S.pop();
}
