/**
 Asta e pentru fanii care ma stalk-uiesc <3
 Da, si eu va iubesc tot asa mult <3
**/

#include <cstdio>

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    size_t r7, r4, r5, r6;
    scanf("%d", &r7);

    loopN:
    --r7;
    scanf("%d%d", &r4, &r5);

    start:
    if(r5 == 0) {
        printf("%d\n", r4);
        if(r7)
            goto loopN;;
        return 0;
    }
    r6 = r4 % r5;
    r4 = r5;
    r5 = r6;
    goto start;
}
