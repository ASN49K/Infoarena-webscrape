#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int a[1025], b[1025];
int DIN[1025][1025];
int n, m;

void citire(){
    in >> n >> m;

    for(int i = 1; i <= n; i++)
        in >> a[i];

    for(int i = 1; i <= m; i++){
        in >> b[i];
    }
}

void cmlsc(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i] != b[j]){
                DIN[i][j] = max(DIN[i][j - 1], DIN[i - 1][j]);
            }
            else
                DIN[i][j] = DIN[i - 1][j - 1] + 1;
        }
    }
    out << DIN[n][m] << "\n";
}

vector <int> sol;

void afisareSol(){
    int i = n, j = m;
    while(DIN[i][j] != 0){
        if(DIN[i][j - 1] == DIN[i - 1][j] && DIN[i][j - 1] < DIN[i][j]){
            sol.push_back(a[i]);
            i--;
            j--;
            continue;
        }
        if(DIN[i][j - 1] >= DIN[i - 1][j]){
            j--;
            continue;
        }
        if(DIN[i][j - 1] < DIN[i - 1][j]){
            i--;
        }
    }

    for(int i = sol.size() - 1; i >= 0; i--)
        out << sol[i] << " ";
}


int main()
{
    ios::sync_with_stdio(false);
    citire();
    cmlsc();
    afisareSol();
    return 0;
}
