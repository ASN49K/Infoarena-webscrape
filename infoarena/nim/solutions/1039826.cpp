#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);

    int n,t, current, xorSum;

    scanf("%d", &t);

    for (int i=0; i<t; i++){
        scanf("%d", &n);

        xorSum = 0;
        for (int j=0; j<n; j++){
            scanf("%d", &current);

            xorSum = xorSum ^ current;
        }

        if (xorSum == 0){
            printf("NU\n");
        } else {
            printf("DA\n");
        }
    }

    return 0;
}
