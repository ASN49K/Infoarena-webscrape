#include<stdio.h>

struct STEP{
    int val, step, elem;
};
struct STEP dyn[1025][1025];
int main() {
    FILE *in = fopen( "cmlsc.in", "r" ), *out = fopen( "cmlsc.out", "w" );
    int n,m, v[1024], w[1024];
    fscanf(in, "%d%d", &n,&m);
    for( int i = 0; i < n; i++)
        fscanf(in,"%d", &v[i]);
    for( int i = 0; i < m; i++)
        fscanf(in,"%d", &w[i]);
    for( int i = 1; i <= n; i++)
        for( int j = 1; j <=m; j++){
            if( v[i-1] == w[j-1]){
                dyn[i][j].val = dyn[i-1][j-1].val + 1;
                dyn[i][j].elem = v[i-1];
                dyn[i][j].step = 0;
            }
            else{
                if (dyn[i-1][j].val > dyn[i][j-1].val){
                    dyn[i][j].val = dyn[i-1][j].val;
                    dyn[i][j].step = -1;
                }
                else{
                    dyn[i][j].val = dyn[i][j-1].val;
                    dyn[i][j].step = 1;
                }
            }
        }

    /*fprintf(out, "\n");
    for( int i = 1; i <= n; i++){
        for( int j = 1; j <= m; j++)
            fprintf(out, "%d ", dyn[i][j].elem);
        fprintf(out,"\n");
    }*/
    fprintf(out, "%d\n", dyn[n][m].val );
    int sol[1024];
    int i = n, j = m, idx = dyn[n][m].val - 1;
    while( i > 0 && j > 0 ){
        if( dyn[i][j].step == 0 ){
            sol[ idx ] = dyn[i][j].elem;
            idx -= 1;
            i -= 1;
            j -= 1;
        }
        else if( dyn[i][j].step == -1 )
            i -= 1;
        else
            j -= 1;
    }
    for( int i = 0; i < dyn[n][m].val; i++)
        fprintf( out, "%d ", sol[i] );
    return 0;
}
