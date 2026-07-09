#include <iostream>
#include <fstream>

#define nMax 1025

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m, n, v1[nMax], v2[nMax], din[nMax][nMax], r[nMax], rIdx;

int main()
{
    fin>>m>>n;

    for(int i=1;i<=m;i++)
        fin>>v1[i];
    for(int i=1;i<=n;i++)
        fin>>v2[i];


    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(v1[i]==v2[j])
                din[i][j]=din[i-1][j-1]+1;
            else
                din[i][j]=std::max(din[i-1][j], din[i][j-1]);
            //cout<<din[i][j]<<" ";
        }
        //cout<<"\n";
    }

    for(int i=m,j=n;i>0;)
        if(v1[i]==v2[j]){
            r[++rIdx]=v1[i];
            i--;
            j--;
        }
        else if(din[i - 1][j] < din[i][j - 1]) j--;
        else i--;
    fout<<rIdx<<"\n";
    for(int i=rIdx;i>0;i--)
        fout << r[i] << ' ';

    return 0;
}
