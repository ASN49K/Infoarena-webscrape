#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
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
    int i = n, j = m;

    int remaining = memo[n][m];
    vector<int> sol;

    while(remaining) {
        if(i - 1 >= 0 and memo[i - 1][j] == remaining)
            i -= 1;
        else if(j - 1 >= 0 and memo[i][j - 1] == remaining)
            j -= 1;
        else {
            sol.push_back(vectorul1[i]);
            i -= 1;
            j -= 1;
            remaining --;
        }
    }

    reverse(sol.begin(), sol.end());
    for(auto val : sol)
        fout << val << " ";

    return 0;
}
