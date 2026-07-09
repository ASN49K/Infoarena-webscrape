#include <bits/stdc++.h>
#define  max(a,b)(( a>b) ? a : b)
using namespace std;
ifstream fin  ("cmlsc.in");
ofstream fout ("cmlsc.out");

int D[1024][1024];
int n,m;

int main()
{
    int a[1024];
    int b[1024];
    fin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
        fin >> a[i];
    for(int j = 1 ; j <=m ;j++)
        fin >> b[j];

    for(int i = 1; i <=n ; i++){
        for(int j=1 ; j<= m ; j++){
            if(a[i] == b[j]){
                D[i][j] = D[i-1][j-1] + 1;
            }else{
                D[i][j] = max(D[i-1][j] , D[i][j-1]);
            }
        }
    }

    // solution create
    int i,j,c=0,arr[1024];
    i= n; j =m;
    while( i>=1 &&  j>=1){
        if(a[i] == b[j]){
            arr[c] = a[i];
            --i;
            --j;
            c++;
        }else if(D[i-1][j] < D[i][j-1]){
            --j;
        }
        else{
            --i;
        }
    }

    fout << c << "\n";
    while(c){
        fout << arr[c-1] << " ";
        c--;
    }
    return 0;
}


