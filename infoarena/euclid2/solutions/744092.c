#include<stdio.h>

int main(void)
{

    FILE * ifs;
    FILE * ofs;

    ifs = fopen("euclid2.in", "r");
    ofs = fopen("euclid2.out", "w+");

    int n;
    fscanf(ifs, "%d", &n);
    int contor=1;
    int a, b;
    int temporar;
    for (contor; contor <= n; contor++)
    {

        fscanf(ifs, "%d", &a);
        fscanf(ifs, "%d", &b);
        temporar = a % b;

        while(temporar)
        {
            a = b;
            b = temporar;
            temporar = a % b;
        }

        fprintf(ofs, "%d\n", b);


    }

    return 0;
}
