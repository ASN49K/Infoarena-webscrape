#include<fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int n,d[1200][1200],m,a[1200],b[1200],rez[1200],aux,rez1;
int main(){
    cin>>m>>n;
    for(int i = 1; i <= m; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(a[i]==b[j])d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    }
    for(int i=m, j=n; i; ){
        if(a[i]==b[j])rez[++aux]=a[i],--i,--j;
        else if(d[i-1][j]<d[i][j-1])j--;
        else i--;
      // cout<<i <<" "<<j<<"\n";
    }
    //for(int i=0 ;i<m ;i++){
        //for(int j=0;j<n;j++){
        //    cout<<d[i][j]<<" ";
       // }
      //  cout<<"\n";
    //}
    cout<<aux<<"\n";
    for(int i = aux; i>=1 ; i--)cout<<rez[i]<<" ";
}