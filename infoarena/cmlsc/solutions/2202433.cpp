
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


void cel_mai_lung_subsir_comun(int A[], int B[], int M, int N)
{
	int cmax = 0, c=0,pozA,i=0,j=0;
	while (i < M)
	{
		
		while (j < N)
		{
			if (A[i] == B[j])
			{
				c++;
				if (cmax < c)
				{
					cmax = c;
					pozA = i;
				
				}
				i++;
				j++;
			}
			else
			{
				c = 0;
				j++;

			}

		}
		i++;
		j = 0;
	}
	for (int i =0;i<cmax;i++)
		cout << A[pozA-i] << " ";

}


int main()
{
	freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
	
	scanf("%d %d", &M, &N);
    FOR (int i=0;i<M;i++)
        scanf("%d", &A[i]);
    FOR (int j=0;j<N;j++)
        scanf("%d", &B[i]);
	cel_mai_lung_subsir_comun(A, B,M,N);
	
	return 0;
}