#include<fstream>
long long int a[1025],b[1025],v[1025];
using namespace std ;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int main(){
    long long int m,n,l=0;
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
                l++;
                v[l]=a[i];
            }
        }
    }
    out<<l<<'\n';
    for(int i=1;i<=l;i++){
        out<<v[i]<<" ";
    }
}
