#include<bits/stdc++.h>

using namespace std;
#define MAX 1030

int d[MAX][MAX];
int a[MAX] , b[MAX] , k= 0  , ans[MAX],z;
int i , j ;
int main(){
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    int n , m  ;

    in >> n >> m ;

    for(int i = 1 ; i <= n ; i ++)
        in >> a[i] ;
    for(int i = 1 ; i <= m ; i ++)
        in >> b[i] ;

    for( i = 1 ; i <= m ; i++)
        for( j = 1; j <= n ; j++){
            if(a[j] == b[i])
                d[i][j] = d[i-1][j-1] + 1 ;
            else
                d[i][j] = max(d[i-1][j],d[i][j-1]);
    }

    i = m ;
    j = n;
    while(i && j){
        if(a[j] == b[i]){
            ans[k++] = a[j];
            i--;
            j--;

        }
        else if(d[i-1][j] < d[i][j-1]) j--;
        else i--;

    }

    out << d[m][n] << '\n';
    for(int i = k-1 ; i>= 0 ; i--)
        out << ans[i] << " ";

}
