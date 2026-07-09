#include <iostream>
#include <fstream>
using namespace std;
int rasp[1026][1026], ss[1026], c;
int main(){
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    int n, m, i, j, s1[1026], s2[1026];
    fin >> n >> m;
    for(i=1;i<=n;++i)
        fin >> s1[i];
    for(i=1;i<=m;++i)
        fin >> s2[i];
    for(j=1;j<=m;++j)
        for(i=1;i<=n;++i)
            if(s1[i]==s2[j])
                rasp[i][j]=rasp[i-1][j-1]+1;
            else
                rasp[i][j]=max(rasp[i][j-1], rasp[i-1][j]);
    fout << rasp[n][m] << "\n";
    int p1=n, p2=m;
    while(p1 && p2){
        if(s1[p1]==s2[p2]){
            ss[++c]=s1[p1];
            p1--;
            p2--;
        }
        else
            if(rasp[p1-1][p2]<rasp[p1][p2-1])
                --p2;
            else
                --p1;
    }
    for(i=c;i>=1;--i)
        fout << ss[i] << " ";
    return 0;
}
