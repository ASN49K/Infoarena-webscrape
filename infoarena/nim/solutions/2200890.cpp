#include <iostream>

using namespace std;

int main()
{

    int t, n;
    FILE* fi = fopen("nim.in", "r");
     FILE* fo = fopen("nim.out", "w");
     fscanf(fi,"%d", &t);
    int i;
    for(i = 0; i < t; i++)
    {
        int s = 0;
        int x,j;
        fscanf(fi,"%d", &n);
        for(j = 0; j < n; j++)
        {
            fscanf(fi,"%d", &x);
            s = s^x;
        }
        if(s == 0) fprintf(fo,"NU\n");
           else fprintf(fo,"DA\n");
    }
    fclose(fi);
    fclose(fo);
    return 0;
}
