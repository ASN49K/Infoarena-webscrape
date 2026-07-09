#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int comun[1025];
int main(){
    int lunga,lungb,i,j,c=1;
    fin>>lunga>>lungb;
    int a[lunga+1],b[lungb+1];
    for(i=1;i<=lunga;++i)
        fin>>a[i];
    for(i=1;i<=lungb;++i)
        fin>>b[i];
    for(i=1;i<=lunga;++i)
        for(j=i;j<=lungb;++j)
            if(a[i]==b[j]){
                comun[c]=a[i];
                c++;
                break;
            }
    fout<<c-1<<"\n";
    for(i=1;i<c;++i)
        fout<<comun[i]<<" ";
    return 0;
}
