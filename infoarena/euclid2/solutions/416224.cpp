#include <stdio.h>
#include <iostream>


using namespace std;
int A,B,n,i;

int euclid(int a, int b){
      if(!b) return a;
    return  euclid(b, a%b);
} 

int main(void){
    
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&n);
    for(;n;--n){
                      scanf("%d %d",&A,&B);
                      printf("%d\n",euclid(A,B));
                    }
                      
    system("PAUSE");
    return EXIT_SUCCESS;
}
