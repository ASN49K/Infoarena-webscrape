#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    int a,b,nr=0;
    fin>>a>>b;
    int m[a],n[b],s[1024];
    for (int i = 0;i<a ;i++ )
        fin>>m[i];
    for (int i = 0;i<b ;i++ )
        fin>>n[i];
    for (int i = 0;i<a ;i++ )
    {
        for (int j = 0 ;j<b ;j++ )
            if(m[i]==n[j])
            {
                s[nr]=m[i];
                m[i]=257;
                n[j]=257;
                nr++;
                break;
            }
    }
    fout<<nr<<"\n";
    for (int i = 0;i<nr ;i++ )
        fout<<s[i]<<" ";
    fin.close();
    fout.close();
    return 0;
}
