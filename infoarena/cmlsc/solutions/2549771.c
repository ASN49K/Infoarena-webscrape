#include <stdio.h>
#include <stdlib.h>

void read(FILE *fin, int m, int n, int a[], int b[])
{
    for(int i = 0; i < m; i++)
    {
        fscanf(fin,"%d ", &a[i]);
        if(a[i] > 256)
        {
            printf("Invalid input!");
            exit(1);
        }
    }

    for(int i = 0; i < n; i++)
    {
        fscanf(fin, "%d ", &b[i]);
        if(b[i] > 256)
        {
            printf("Invalid input!");
            exit(1);
        }
    }
}

void find(int m, int n, int a[], int b[], FILE *fout)
{
    int *v = malloc((m+n)*sizeof(int)), vlen = 0, *vmax = malloc((m+n)*sizeof(int)), maxlen = 0;

    if(m < n)
    {
        int jfound = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = jfound; j < n; j++)
            {
                if(a[i] == b[j])
                {
                    v[vlen++] = a[i];
                    jfound = j + 1;
                    if(jfound >= n)
                    {
                        jfound = 0;
                        if(vlen > maxlen)
                        {
                            for(int k = 0; k < vlen; k++)
                            {
                                vmax[k] = v[k];
                            }
                            maxlen = vlen;
                            vlen = 0;
                        }
                    }
                    break;
                }
            }
        }
    }
    else
    {
        int jfound = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = jfound; j < m; j++)
            {
                if(b[i] == a[j])
                {
                    v[vlen++] = a[j];
                    jfound = j + 1;
                    if(jfound >= m)
                    {
                        jfound = 0;
                        if(vlen > maxlen)
                        {
                            for(int k = 0; k < vlen; k++)
                            {
                                vmax[k] = v[k];
                            }
                            maxlen = vlen;
                            vlen = 0;
                        }
                    }
                    break;
                }
            }
        }
    }

    fprintf(fout, "%d\n", maxlen);
    for(int i = 0; i < maxlen; i++)
    {
        fprintf(fout, "%d ", vmax[i]);
    }




}
int main()
{
    FILE *fin = fopen("cmlsc.in","r"), *fout = fopen("cmlsc.out", "w");
    int M, N;
    fscanf(fin, "%d %d", &M, &N);

    if(M < 1 || M > 256 || N < 1 || N > 256)
    {
        printf("Invalid input!");
        exit(1);
    }

    int A[M], B[N];

    read(fin, M, N, A, B);
    find(M, N, A, B, fout);

    fclose(fin);
    fclose(fout);
    return 0;
}
