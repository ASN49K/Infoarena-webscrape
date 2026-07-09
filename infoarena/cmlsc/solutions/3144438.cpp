#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int Mlen, M[1025], Nlen, N[1025], cmlscTable[1025][1025], MAX, cmlsc[1025], tm, tn, c;

int main()
{
    fin>>Mlen>>Nlen;
    for(int i = 1; i<=Mlen; i++)
        fin>>M[i];
    for(int j = 1; j<=Nlen; j++)
        fin>>N[j];
    for(int i = 1; i<=Mlen; i++){
        for(int j = 1; j<=Nlen; j++){
            if(M[i]==N[j])
                cmlscTable[i][j] = cmlscTable[i-1][j-1] + 1;
            else
                cmlscTable[i][j] = max(cmlscTable[i-1][j], cmlscTable[i][j-1]);
        }
    }
    tm = Mlen;
    tn = Nlen;
    c = cmlscTable[tm][tn];
    while(cmlscTable[tm][tn]!=0){
        if(cmlscTable[tm][tn] == max(cmlscTable[tm-1][tn], cmlscTable[tm][tn-1])){
            if(cmlscTable[tm-1][tn]>cmlscTable[tm][tn-1])
                tm = tm-1;
            else
                tn = tn-1;
        }
        else{
            cmlsc[c] = M[tm];
            --tm;
            --tn;
            --c;
        }
    }
    fout<<cmlscTable[Mlen][Nlen]<<'\n';
    for(int i = 1; i<=cmlscTable[Mlen][Nlen]; i++)
        fout<<cmlsc[i]<<' ';
    return 0;
}
