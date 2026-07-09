#include <stdio.h>
#include <stdlib.h>
void print(int * a, int dim,FILE * out){
    
    int i ; 
    fprintf(out,"%d\n",dim );
    for(i = 0 ; i < dim ; i++)
        fprintf(out,"%d ",a[i] );
    fprintf(out,"\n");
}
int  check(int * secventa ,int dim_sec , int * b , int N ){
    int i = 0;
    int ok = 1 ; // presupunem ca e secventa
    int poz = 0 ;
    for (i = 0 ; i < dim_sec ; i++){
        while(poz < N && secventa[i] != b[poz])
            poz ++ ;

        if(poz == N){
            ok = 0 ;
            break ;
        }

         poz ++ ;
    }
    return ok ;

}
void generate(int * a , int M,int index,int * aux, int  dim,int * b , int N , int * secventa_max , int * dim_sec){
    if(index == M){
        if(dim > * dim_sec){
            int test = check(aux,dim,b,N);
            if(test == 1){
                *dim_sec = dim ;
                int i ;
                for (i = 0 ; i < dim ; i++)
                    secventa_max[i] = aux[i];

            }
        }
        return ;
    }
    generate(a,M,index + 1 , aux , dim,b,N,secventa_max,dim_sec); 
    aux[dim] = a[index];
    generate(a,M,index + 1 , aux , dim + 1,b,N,secventa_max,dim_sec); 

}
int main(){
    FILE * in = fopen("cmlsc.in","r");
    FILE * out = fopen("cmlsc.out","w");
    int M,N;
    int *a , *b ; 
    fscanf(in,"%d %d\n",&M,&N);
    a = (int*)malloc(M*sizeof(int));
    b = (int*)malloc(N*sizeof(int));
    int i ;
    for(i = 0 ; i < M ; i ++){
        fscanf(in,"%d",&a[i]);
        
    }
 
    for(i = 0 ; i < N ; i ++){
        fscanf(in,"%d",&b[i]);
        
    }
    if (M > N){//facem un swap ;
        int auxx = M ;
        M = N ;
        N = auxx;
        int * vect_aux = a ;
        a = b ;
        b = vect_aux ;

    }
    int * aux = (int * )malloc(M*sizeof(int));
    int * secventa = (int * )malloc(M*sizeof(int)); // dimensiunea maxima posibila
    int dim_max = 0 ;

    generate(a,M,0,aux,0,b,N,secventa,&dim_max);
    print(secventa,dim_max,out);
    fclose(in);
    fclose(out);
    return 0 ;
}