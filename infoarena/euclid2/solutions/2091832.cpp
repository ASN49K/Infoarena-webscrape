#include <iostream>
#include <fstream>
using namespace std;

int t,a[100001],b[100001],r[100001];

int main()
{
    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    fin>>t;
    for(int i=1;i<=t;i++){
        fin>>a[i]>>b[i];
        if(a[i]>b[i]){
            while(a[i]>b[i] && a[i]-b[i]!=0){
                if(a[i]-b[i]>0)a[i]=a[i]-b[i];
            }
            if(b[i]%a[i]==0)
            r[i]=a[i];
            else r[i]=1;
        }else{
            while(b[i]>a[i] && b[i]-a[i]!=0){
                if(b[i]-a[i]>0)b[i]=b[i]-a[i];
            }
            if(a[i]%b[i]==0)
            r[i]=b[i];
            else r[i]=1;
        }


    }
    for(int i=1;i<=t;i++){
        fout<<r[i]<<"\n";
    }
    return 0;
}
