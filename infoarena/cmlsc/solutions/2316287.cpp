#include <iostream>
#include <fstream>
using namespace std;

int rezolvare(int *vect1, int *vect2, int **&memo, int n, int m){
    int rezultat;
    if(n == 0 || m == 0)
        return 0;
    if(memo[n][m] != -1)
        return memo[n][m];
    if(vect1[n] == vect2[m])
        rezultat = 1 + rezolvare(vect1, vect2, memo, n-1, m-1);
    else{
        int temp1, temp2;
        temp1 = rezolvare(vect1, vect2, memo, n-1, m);
        temp2 = rezolvare(vect1, vect2, memo, n, m-1);
        rezultat = max(temp1, temp2);
    }
        memo[n][m] = rezultat;
        return rezultat;
}

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    int **memo, n, m, *vectorul1, *vectorul2, MAXIM = 0;
    fin >> n >> m;
    vectorul1 = new int[n+1];
    vectorul2 = new int[m+1];
    memo = new int*[n+1]();
    for(int i = 1 ; i <= n ; i++)
        fin >> vectorul1[i];
    for(int i = 1 ; i <= n ; i++)
        memo[i] = new int[m+1]();
    for(int i = 1 ; i <= m ; i++)
        fin >> vectorul2[i];
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            memo[i][j] = -1;
    rezolvare(vectorul1, vectorul2, memo, n, m);
    fout << memo[n][m] << endl;
    for(int i = 1; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            if (memo[i][j] > MAXIM){
                MAXIM = memo[i][j];
                fout << vectorul1[i] << ' ';
            }
    return 0;
}
