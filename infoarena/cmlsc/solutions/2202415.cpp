void cel_mai_lung_subsir_comun(int A[], int B[], int M, int N)
{
	int cmax = 0, c,pozA,pozB,i=0,j=0;
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