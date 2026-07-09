#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int comun[1025];
bool repetable(int a,int c){
    for(int i=1;i<c;++i)
        if(comun[i]==a)
            return 1;
    return 0;
}
int main(){
    int lunga,lungb,i,j,c=1;
    fin>>lunga>>lungb;
    int a[lunga+1],b[lungb+1];
    for(i=1;i<=lunga;++i)
        fin>>a[i];
    for(i=1;i<=lungb;++i)
        fin>>b[i];
    for(i=1;i<=lunga;++i)
        for(j=1;j<=lungb;++j)
            if(a[i]==b[j] && repetable(a[i],c)==0){
                comun[c]=a[i];
                c++;
                break;
            }
    fout<<c-1<<"\n";
    for(i=1;i<c;++i)
        fout<<comun[i]<<" ";
    return 0;
}
