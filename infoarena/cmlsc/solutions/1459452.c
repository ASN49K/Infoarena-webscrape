#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int M , N ;
int * X = NULL ;
int * Y = NULL ;
int ** C  = NULL ;
int * subsecventa = NULL ;
int POZ = 0 ;
void print(int * a, int dim,FILE * out){
    
    int i ; 
    fprintf(out,"%d\n",dim );
    for(i = 0 ; i < dim ; i++)
        fprintf(out,"%d ",a[i] );
    fprintf(out,"\n");
}
void print_matrix(){
    int i , j ;
    for ( i = 0; i <= M ; i++){
        printf("\n");
        for( j = 0 ; j <= N ; j++)
            printf("%d ",C[i][j] );
    }
}    
void generate_matrix(){
    int i , j ;
    for(i = 1 ; i <= M; i++)
        for ( j = 1 ; j <= N ; j++)
            if(X[i] == Y[j])
                C[i][j] = C[i-1][j-1] + 1;
            else
                C[i][j] = fmax(C[i][j-1],C[i-1][j]);
}

void backtrack(int i , int j){
    if (i == 0 || j == 0)
        return ;
    else if(X[i] == Y[j]){
        subsecventa[POZ--] = X[i];
        backtrack(i-1,j-1);
    }
    else {
        if(C[i][j-1] > C[i-1][j])
            backtrack(i,j-1);
        else
            backtrack(i-1,j);
    }

}    
int main(){
    FILE * in = fopen("cmlsc.in","r");
    FILE * out = fopen("cmlsc.out","w");
    fscanf(in,"%d %d\n",&M,&N);
    X = (int*)malloc((M+1)*sizeof(int));
    Y = (int*)malloc((N+1)*sizeof(int));
    int i ;
    for(i = 1 ; i <= M ; i ++){
        fscanf(in,"%d",&X[i]);
        
    }
 
    for(i = 1; i <= N ; i ++){
        fscanf(in,"%d",&Y[i]);
        
    }
    //initializam matricea 
    C = (int **)malloc((M+1)*sizeof(int *));
    for(i = 0 ; i <= M ;i++ )
        C[i] = (int*)calloc((N+1),sizeof(int*));
    generate_matrix();
    
    int longest = C[M][N];

    subsecventa = (int*)malloc(longest*sizeof(int));

    POZ = longest - 1 ;
    backtrack(M,N);
    print(subsecventa,longest,out);
    fclose(in);
    fclose(out);
    return 0 ;
}