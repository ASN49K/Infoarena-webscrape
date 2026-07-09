#include<fstream>
#include<iostream>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int v[40],t,n,i,a,w[40],k,j,q,z,ok,maxim,b[40],s,c;
int main(){
    fin>>t;
    for(z=1;z<=t;z++){
        ok=0;
        maxim=-1;
        fin>>n;
         for(q=0;q<=40;q++){
            w[q]=0;
        }
        for(i=1;i<=n;i++){
            fin>>a;
            k=-1;
            while(a!=1){
                v[++k]=a%2;
                a/=2;
            }
            v[++k]=1;
            for(s=0;s<=k;s++){
                b[s]=v[k-s];
            }
            for(s=0;s<=k;s++){
                v[s]=b[k-s];
            }
            if(k>maxim)
            maxim=k;
            for(j=0;j<=k;j++){
                w[j]+=v[j];
            }
        }
        for(j=0;j<=maxim;j++){
                //fout<<w[j]<<" ";
            if(w[j]%2==1){
                fout<<"DA"<<"\n";
                ok=1;
                break;
            }
        }
        //fout<<"\n";
        if(ok==0){
            fout<<"NU"<<"\n";
        }
    }
    return 0;
}
