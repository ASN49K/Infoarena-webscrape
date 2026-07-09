#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream fin("pbinfo.in");
    ofstream fout("euclid2.out");
    int a,b,nr=0,stop=0;
    fin>>a>>b;
    int m[a],n[b],s[1024];
    for (int i = 0;i<a ;i++ )
        fin>>m[i];
    for (int i = 0;i<b ;i++ )
        fin>>n[i];
    for (int i = 0;i<a ;i++ )
    {
        for (int j = stop ;j<b ;j++ )
            if(m[i]==n[j])
            {
                s[nr]=m[i];
                stop=j;
                nr++;
                break;
            }
    }
    cout<<nr<<"\n";
    for (int i = 0;i<nr ;i++ )
        cout<<s[i]<<" ";
}
