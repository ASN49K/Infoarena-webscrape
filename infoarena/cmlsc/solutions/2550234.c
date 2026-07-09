#include <stdio.h>
#include <stdlib.h>

void read(FILE *fin, int m, int n, int a[], int b[])
{
    for(int i = 0; i < m; i++)
    {
        fscanf(fin,"%d ", &a[i]);
        /*if(a[i] > 256)
        {
            printf("Invalid input!");
            exit(1);
        }*/
    }

    for(int i = 0; i < n; i++)
    {
        fscanf(fin, "%d ", &b[i]);
       /* if(b[i] > 256)
        {
            printf("Invalid input!");
            exit(1);
        */}
    }
}

void find(int m, int n, int a[], int b[], FILE *fout)
{
    int *v = malloc((m+n)*sizeof(int)), vi = 0, *vmax = malloc((m+n)*sizeof(int)), maxlen = 0;
    int ai, bi;
    if(m < n)
    {
        int found = 0;
        for(ai = 0; ai < m; ai++)
        {
            for(bi = found; bi < n; bi++)
            {
                if(a[ai] == b[bi])
                {
                    v[vi++] = a[ai];
                    found = bi+1;
                    break;
                }
            }
            if(found >= n)
            {
                if(vi > maxlen)
                {
                    maxlen = vi;
                    for(int k = 0; k < vi; k++)
                    {
                        vmax[k] = v[k];
                    }
                }
                found = 0;
                vi = 0;
            }
        }
        if(maxlen == 0)
        {
            for(int k = 0; k < vi; k++)
            {
                vmax[k] = v[k];
            }
            maxlen = vi;
        }
    }
    else
    {
        int found = 0;
        for(bi = 0; bi < n; bi++)
        {
            for(ai = found; ai < m; ai++)
            {
                if(a[ai] == b[bi])
                {
                    v[vi++] = a[ai];
                    found = bi+1;
                    break;
                }
            }
            if(found >= m)
            {
                if(vi > maxlen)
                {
                    maxlen = vi;
                    for(int k = 0; k < vi; k++)
                    {
                        vmax[k] = v[k];
                    }
                }
                found = 0;
                vi = 0;
            }
        }
        if(maxlen == 0)
        {
            for(int k = 0; k < vi; k++)
            {
                vmax[k] = v[k];
            }
            maxlen = vi;
        }
    }

    fprintf(fout,"%d\n",maxlen);
    for(int i = 0; i < maxlen; i++)
    {
        fprintf(fout,"%d ",vmax[i]);
    }

}

int main()
{
    FILE *fin = fopen("cmlsc.in","r"), *fout = fopen("cmlsc.out", "w");
    int M, N;
    fscanf(fin, "%d %d", &M, &N);

    /*if(M < 1 || M > 256 || N < 1 || N > 256)
    {
        printf("Invalid input!");
        exit(1);
    }*/

    int A[M], B[N];

    read(fin, M, N, A, B);
    find(M, N, A, B, fout);

    fclose(fin);
    fclose(fout);
    return 0;
}
