#include <iostream>
#include <fstream>
#define lim 1111
#define myMax(a,b) (a > b) ? a : b

using namespace std;
ofstream fout ("cmlsc.out");
ifstream fin ("cmlsc.in");
int n,m;
int a[lim];
int b[lim];

int sol[lim][lim];
void scan(){

    fin >> n >> m;
    for(int i =1; i <= n; i++){
        fin >> a[i];
    }
    for(int i =1; i <= m; i++){
        fin >> b[i];
    }
    if( n < m ){
    swap(a,b);
    swap(n,m);
    }



}


void solve(){

    for(int i =0 ; i <= n ; ++i)
        for(int j = 0; j <= m; ++j)
            sol[i][j] =0;

    for(int j = 1; j <=m; j++){

            for(int i = 1; i <=n; i++){
                if(a[i] == b[j])
                    sol[i][j] = sol[i-1][j-1] + 1;
                else
                    sol[i][j] = max(sol[i][j-1] , sol[i-1][j]);
            }
    }
    fout << sol[n][m] << endl;

}


void printSubsequence(int i, int j){

    if(i == 0 || j == 0)
    return;

    if(a[i] == b[j])
    {
        printSubsequence(i-1,j-1);
        fout << a[i] << " ";
        return;
    }
    if(sol[i-1][j] > sol[i][j-1])
    printSubsequence(i-1,j);
    else
    printSubsequence(i,j-1);
    return;

}

int main()
{
    scan();
    solve();
    printSubsequence(n,m);
    return 0;
}
