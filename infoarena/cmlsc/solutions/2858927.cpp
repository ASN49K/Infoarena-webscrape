#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    short n,m,a[1024],b[1024],c[1024],t=0;
    fin>>n>>m;
    for(int i=0;i<n;i++) fin>>a[i];
    for(int i=0;i<m;i++) fin>>b[i];
    fin.close();
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
        if(a[i]==b[j]){
            c[t]=a[i];
            t++;
            break;
        }
    }
    fout<<t<<endl;
    for(int i=0;i<t;i++){
        fout<<c[i]<<" ";
    }
    return 0;
}
