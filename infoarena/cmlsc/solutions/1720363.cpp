#include<fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int n,d[1200][1200],m,a[1200],b[1200],rez[1200],aux,rez1;
int main(){
    cin>>m>>n;
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i==0||j==0)d[i][j]=0;
            if(a[i]==b[j])d[i][j]=d[i-1][j-1]+1,rez[aux++]=a[i],rez1=max(rez1,d[i][j]);
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    }
    for(int i=n-1, j=m-1; i>=0 ; ){
        if(a[i]==b[i])rez[++aux]=a[i],i--,j--;
        else if(d[i-1][j]<d[i][j-1])j--;
        else i--;
    }
    //for(int i=0 ;i<m ;i++){
        //for(int j=0;j<n;j++){
        //    cout<<d[i][j]<<" ";
       // }
      //  cout<<"\n";
    //}
    cout<<rez1<<"\n";
    for(int i = 0; i<aux ; i++)cout<<rez[i]<<" ";
}