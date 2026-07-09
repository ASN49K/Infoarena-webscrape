#include <fstream>
using namespace std;

ifstream cin ("cmlsc.in");
ofstream cout("cmlsc.out");

int a[1025],b[1025],rasp[1025];

struct dp{
    int max1,l,c;
}v[1025][1025];

int main()
{

    int n,m,i,j,ci;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=m;i++)
        cin>>b[i];
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(v[i-1][j].max1>v[i][j].max1){
                v[i][j].max1=v[i-1][j].max1;
                v[i][j].l=i-1;v[i][j].c=j;
            }
            if(v[i][j-1].max1>v[i][j].max1){
                v[i][j].max1=v[i][j-1].max1;
                v[i][j].l=i;v[i][j].c=j-1;
            }
            if(a[i]==b[j] && v[i-1][j-1].max1+1>v[i][j].max1){
                v[i][j].max1=v[i-1][j-1].max1+1;
                v[i][j].l=i-1;v[i][j].c=j-1;
            }
        }
    }
    cout<<v[n][m].max1<<"\n";
    int cnt=0;
    i=n;j=m;
    while(i>0 && j>0){
        if(v[i][j].l==i-1 && v[i][j].c==j-1){
            rasp[cnt]=a[i];
            cnt++;
        }
        ci=i;
        i=v[i][j].l;j=v[ci][j].c;
    }
    for(i=cnt-1;i>=0;i--){
        cout<<rasp[i]<<" ";
    }
    return 0;
}
