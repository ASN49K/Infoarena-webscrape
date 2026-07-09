#include <fstream>
#define DMAX 1032
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m;
int a[DMAX], b[DMAX];
int LCS[DMAX][DMAX];
char unde[DMAX][DMAX];//pentru memorie
void read();
void pd();
void print();

int main(){
    read();
    pd();
    print();
    return 0;
}

void read(){
    int i;
    fin >> n >> m;//in enunt sunt inversate
    for(i = 1; i <= n; i++) fin >> a[i];
    for(i = 1; i <= m; i++) fin >> b[i];
}

void pd(){
    int i, j;
    for(i = n; i > 0; i--)
        for(j = m; j > 0; j--)
            if(a[i] == b[j]){
                LCS[i][j] = 1 + LCS[i + 1][j + 1];
                unde[i][j] = '1';
            }
            else
                if(LCS[i + 1][j] > LCS[i][j + 1]){
                    LCS[i][j] =  LCS[i + 1][j];
                    unde[i][j] = '2';
                }
                else{
                    LCS[i][j] =  LCS[i][j + 1];
                    unde[i][j] = '3';
                }
}

void print(){
    int i, j;
    fout << LCS[1][1] << '\n';
    i = 1; j = 1;
    while(i <= n && j <= m){
        if(unde[i][j] == '1')
            {fout << a[i] << ' '; i++; j++;}
        else
            if(unde[i][j] == '2')
                i++;
            else
                j++;
    }
    fout << '\n';
    fout.close();
}
