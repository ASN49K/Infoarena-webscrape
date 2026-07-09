#include<fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int v1[1024],v2[1024],a[1024][1024],sol[1024];
int n,m,i,j,k=0;

void citire(){
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>v1[i];
    for(i=1;i<=m;i++)
        cin>>v2[i];
}
void cmlsc(){
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            if(v1[i]==v2[j])
                a[i][j]=a[i-1][j-1]+1;
            else
                a[i][j]=max(a[i-1][j],a[i][j-1]);
        }
}
void afisare(){
    cout<<a[n][m]<<endl;
    i=n;
    j=m;
    while(a[i][j]!=0){
        if(v1[i]==v2[j]){
            k++;
            sol[k]=v1[i];
            i--;
            j--;
        }
        else{
            if(a[i-1][j]>a[i][j-1])
                i--;
            else
                j--;
        }
    }
    for(i=1;i<=k;i++)
        cout<<sol[k-i+1]<<" ";
}
int main(){
    citire();
    cmlsc();
    afisare();
    return 0;
}
