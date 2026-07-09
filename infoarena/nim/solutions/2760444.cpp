#include <iostream>
#include <stdio.h>

using namespace std;


int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);

    int t;
    scanf("%d", &t);

    for (int k=0; k<t; k++){
        unsigned int n, x=0, a;
        scanf("%d", &n);

        for (int i=0; i<n; i++){
            scanf("%d", &a);
            x ^= a;
        }

        if (x != 0) printf("DA\n");
        else       printf("NU\n");
    }
}

/*
2
4
1 3 5 7
3
4 8 17
*/
