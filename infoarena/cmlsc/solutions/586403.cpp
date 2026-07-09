#include <stdio.h>

#define L 1024

int m, n;			// lengths
int a[L], b[L];		// arrays
int dm[L][L];		// dynamic matrix
int max;			// longest length
int result[L];		// result

int main(void)
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
	// get lengths
    scanf("%d %d", &m, &n);
	// get first array
    for (int i=0; i<n; i++)
        scanf("%d", &a[i]);
	//get second array
    for (int i=0; i<m; i++)
        scanf("%d", &b[i]);
	// populate matrix
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            if (a[i] == b[j])
                dm[i][j] = 1 + dm[i-1][j-1];
            else
                dm[i][j] = dm[i-1][j] > dm[i][j-1] ? dm[i-1][j] : dm[i][j-1];
	// return backwards and create de result array 
	int auxX = m-1, auxY = n-1;
	while (auxX>=0)
		if (a[auxX] == b[auxY])
		{
			result[max++] = a[auxX];
			auxX--;
			auxY--;
		}
		else
			if (dm[auxX-1][auxY] > dm[auxX][auxY-1])
				auxX--;
			else
				auxY--;
	// store results (reversed)
    printf("%d\n", max);
    for (int i = max-1; i>=0; i--)
        printf("%d ", result[i]);

    return 0;
}


