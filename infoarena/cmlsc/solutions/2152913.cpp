#include <cstdio>
#include <stack>
using namespace std;
#define NMAX 1030

int d[NMAX][NMAX], urm[NMAX][NMAX];
stack<int> st;

int main(){

    int i, j, n, m, a[NMAX], b[NMAX];
    int maxim = -1, starti, startj;
    FILE *fin, *fout;
    fin = fopen("cmlsc.in", "r");
    fout = fopen("cmlsc.out", "w");

    fscanf(fin, "%d %d", &n, &m);
    for(i=1; i<=n; i++)
        fscanf(fin, "%d ", &a[i]);
    for(i=1; i<=m; i++)
        fscanf(fin, "%d ", &b[i]);

    for(i=1; i<=m; i++){
        for(j=1; j<=n; j++){
            if(b[i] == a[j]){
                d[i][j] = d[i-1][j-1] + 1;
                urm[i][j] = 1;
            }else{
                if(d[i-1][j] > d[i][j-1]){
                    d[i][j] = d[i-1][j];
                }else{
                    d[i][j] = d[i][j-1];
                }
            }
            if(d[i][j] > maxim){
                maxim = d[i][j];
                starti = i;
                startj = j;
            }
        }
    }

    st.push( a[startj] );
    i = starti - 1;
    j = startj - 1;
    while(i != 0 && j != 0){
        if(urm[i][j]){
            st.push( a[j] );
            i -= 1;
            j -= 1;
        }else{
            if(d[i-1][j] > d[i][j-1]){
                    i -= 1;
            }else{
                    j -= 1;
            }
        }
    }

    fprintf(fout, "%d\n", (int)st.size());
    while(!st.empty()){
        fprintf(fout, "%d ", st.top());
        st.pop();
    }

    return 0;
}
