#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


int NoCases , NoGroups , XorSum ;
int main(){
    int x , i ;

    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);


    scanf("%d",&NoCases);

    while( NoCases -- ){
        scanf("%d",&NoGroups );

        XorSum = 0 ;
        for( i = 0 ; i < NoGroups ; i++ ){
            scanf("%d",&x );

            XorSum = XorSum ^ x ;
        }

        if ( XorSum == 0 ){
            printf("NU");
        }else {
            printf("DA");
        }
        printf("\n");
    }

    return 0;
}
