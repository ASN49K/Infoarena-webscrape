#include <iostream>
#include <fstream>
using namespace std;

ifstream inf("cmlsc.in");
ofstream oinf("cmlsc.out");
void cmlsc(int a[],int n,int b[], int m,int &a1,int &x){
    int k,c,d;
    for(int i=1;i<n; i++){
        for(int j=1;j<m; j++){
            if(a[i]==b[j]){
                k=0;c=i;d=j;
                while(a[c]==b[d]){
                    k++;c++;d++;
                }
                if(k>x){
                    a1=i;x=k;
                    }
                }
            }
    }
}
int main()
{
    int a[1024],b[1024],n,m,x=0,a1;
    inf>>n>>m;
    cmlsc(a,n,b,m,a1,x);
    oinf<<x<<"\n";
    for(int i=a1;i<a1+x; i++){
        oinf<<a[i]<<" ";
    }
    return 0;
}
