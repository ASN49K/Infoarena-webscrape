#include <iostream>
#include <stdio.h>

int Euclid(int a, int b)
{
    int rest = a % b;
    
    if (!rest)
        return b;
        
    else
        return Euclid(b, rest);

}

int main()
{
    int a, b;
    
    printf("Introduceti 2 numere:\n");
    
    scanf("%d %d",&a,&b);
            
    printf( "Cel mai mare divizor comun este: %d\n", Euclid(a,b) );
    
    return 0;
}
