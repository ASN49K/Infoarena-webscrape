//
//  main.cpp
//  Subsir Comun Maximal
//
//  Created by Ilie Marius Emanuel on 23.11.2013.
//  Copyright (c) 2013 Ilie Marius Emanuel. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
    char a[100], b[100], d[100]; a[0]=b[0]='/';
    int sp[100][100]={0}, s[100], i=0, j=0, k=0;
    
    printf("Sirul 1: "); scanf("%s", d);
    strcat(a, d);
    printf("Sirul 2: "); scanf("%s", d);
    strcat(b, d);
    
    for(i=1; i<=strlen(b); i++)
        for(j=1; j<=strlen(a); j++)
            if(a[j]==b[i]) sp[i][j]=sp[i-1][j-1]+1;
            else if(sp[i-1][j]>sp[i][j-1]) sp[i][j]=sp[i-1][j];
                 else sp[i][j]=sp[i][j-1];
    
    i=strlen(b); j=strlen(a);
    
    while(sp[i][j])
    {
        if(a[j]==b[i])
        {
            i--;
            s[++k]=j--;
        }
        else if(sp[i-1][j]>sp[i][j-1]) i--;
             else j--;
    }
    
    printf("\nSolutie: ");
    for(i=k; i>1; i--)
        printf("%c ", a[s[i]]);
    printf("\n\n");
    
    return 0;
}

