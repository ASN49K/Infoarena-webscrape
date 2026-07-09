
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
					pozB = j;
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
	int A[] = { 10,11,3,4,5,0,1 };
	int B[] = { 3,4,5,12,88,9 };
	cel_mai_lung_subsir_comun(A, B,7,6);
	
	retrun 0;
}