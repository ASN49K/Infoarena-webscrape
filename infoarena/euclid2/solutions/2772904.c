#include <stdio.h>
#include <ctype.h>

FILE *fin, *fout;

int readInt()
{
    int result = 0;
    char ch;

    while(!isdigit(ch = fgetc(fin)));

    do
    {
        result = result * 10 + ch - '0';
    }
    while (isdigit(ch = fgetc(fin)));

    return result;
}

int main()
{
    int t, a, b, r;

    fin = fopen("euclid2.in", "r");
    fout = fopen("euclid2.out", "w");

    t = readInt();

    for (int contor = 1; contor <= t; contor++)
    {
        a = readInt();
        b = readInt();

        while (b)
        {
            r = a % b;
            a = b;
            b = r;
        }
        fprintf(fout, "%d\n", a);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
