#include<fstream>
#include<iostream>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int v[40],t,n,i,a,w[40],k,j,q,z,ok;
int main(){
    fin>>t;
    for(z=1;z<=t;z++){
        ok=0;
        fin>>n;
        for(i=1;i<=n;i++){
            fin>>a;
            k=-1;
            while(a!=1){
                v[++k]=a%2;
                a/=2;
            }
            v[++k]=1;
            for(j=0;j<=k;j++){
                w[j]+=v[k-j];
            }
        }
        for(j=0;j<=k;j++){
            if(w[k]%2==1){
                fout<<"DA"<<"\n";
                ok=1;
                break;
            }
        }
        if(ok==0)
            fout<<"NU"<<"\n";
    }
    return 0;
}
