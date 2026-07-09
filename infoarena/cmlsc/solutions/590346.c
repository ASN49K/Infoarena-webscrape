#include <stdio.h>
#include <stdlib.h>

void print_vector(int *x, int len_x)
{
    int i;

    for (i = 0; i < len_x; i++)
        printf("%3d", x[i]);
    printf("\n");
}

void lcs(int *a, int len_a, int *b, int len_b)
{
    int i, j, k = 0, max = 0; 

    int **m = (int**)calloc(len_b, sizeof(int*));
    int *common = NULL;

    for (i = 0; i < len_b; i++)
        m[i] = (int*)calloc(len_a, sizeof(int));

    for (i = 0; i < len_b; i++)
    {
        for (j = 0; j < len_a; j++)
        {
            if (b[i] == a[j])
            {
                m[i][j] = 1;
                if ((i > 0) && (j > 0))
                    m[i][j] += m[i - 1][j - 1];
                max = (max > m[i][j]) ? max : m[i][j];
            }
            else
            {
                if ((i > 0) && (j > 0))
                    m[i][j] = (m[i - 1][j] > m[i][j - 1]) ? m[i - 1][j] : m[i][j - 1];
            }
        }
    }

    printf("%d\n", max);

    if (max == 0)
        goto cleanup;

    common = (int*)calloc(max, sizeof(int));

    i = len_b - 1;
    j = len_a - 1;
    k = max;

    while ((i >= 0) && (j >= 0))
    {
        if (b[i] == a[j])
        {
            common[k - 1] = b[i];
            k--;
            i--;
            j--;
        } else {
            if (m[i - 1][j] > m[i][j - 1])
                i--;
            else
                j--;
        }
    }

    for (i = 0; i < max; i++)
        printf("%d ", common[i]);
    printf("\n");

cleanup:    
    for (i = 0; i < len_b; i++)
        free(m[i]);
    free(m);

    if (NULL != common)
        free(common);
}

int main()
{
    int *a = NULL, *b = NULL;
    int len_a = -1, len_b = -1, i;

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &len_a, &len_b);

	if ((len_a < 1) || (len_a > 1024))
		return;
	
	if ((len_b < 1) || (len_b > 1024))
		return;

    a = (int*)calloc(len_a, sizeof(int));
    b = (int*)calloc(len_b, sizeof(int));

    for (i = 0; i < len_a; i++)
        scanf("%d", &a[i]);
    
    for (i = 0; i < len_b; i++)
        scanf("%d", &b[i]);
    
    lcs(a, len_a, b, len_b);

    return 0;
}
