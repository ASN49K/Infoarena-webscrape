#include<fstream>
using namespace std;
int d[1024][1024]={},a[1024],b[1024],c[1024];
int main(){
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    long long int m,n,t,l=0;
    in>>m>>n;
    for(int i=1;i<=m;i++){
        in>>a[i];
    }
    for(int i=1;i<=n;i++){
        in>>b[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i]==b[j]){
                d[i][j]=d[i-1][j-1]+1;
                if(l<d[i][j]){
                    t=i+j;
                    l=d[i][j];
                    c[l]=a[i];
                }else{
                    if(l==d[i][j]){
                        if(t>i+j){
                            t=i+j;
                            c[l]=a[i];
                        }
                    }
                }
            }else{
                d[i][j]=max(d[i-1][j],d[i][j-1]);
            }
        }
    }
    out<<l<<'\n';
    for(int i=1;i<=l;i++){
        out<<c[i]<<" ";
    }
}
