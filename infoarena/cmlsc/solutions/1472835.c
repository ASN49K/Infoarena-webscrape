#include <stdio.h>
#define maxim(x,y) ( (x>y) ? x:y )
#define NMAX 1024

int lungime_sir1,lungime_sir2,sir1[NMAX],sir2[NMAX],D[NMAX][NMAX],sir_comun[NMAX],nr_elemente;

int main()
{
    int i,j;

    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d %d",&lungime_sir1,&lungime_sir2);

    for( i=1; i<=lungime_sir1 ;i++ ){
        scanf("%d",&sir1[i]);
    }
    for( i=1; i<=lungime_sir2 ;i++ ){
        scanf("%d",&sir2[i]);
    }

    for( i=1; i<=lungime_sir1 ;i++ ){
        for( j=1; j<=lungime_sir2 ;j++ ){
            if( sir1[i] == sir2[j] ){
                D[i][j] = 1+D[i-1][j-1];
            }
            else{
                D[i][j] = maxim( D[i-1][j],D[i][j-1] );
            }
        }
    }

    for( i=lungime_sir1 , j=lungime_sir2; i>0 ; ){
        if( sir1[i] == sir2[j] ){
            sir_comun[++nr_elemente] = sir1[i];
            i--;
            j--;
        }
        else if( D[i-1][j] < D[i][j-1] ){
            j--;
        }
        else{
            i--;
        }
    }

    printf( "%d\n",nr_elemente );
    for( i=nr_elemente; i>0 ;i-- ){
        printf("%d ",sir_comun[i] );
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}
