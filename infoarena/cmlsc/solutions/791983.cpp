// 1-Longest_Common_Subsequence.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <stdio.h>
#include <list>

void compute(int* N, int* K, int NLength, int KLength)
{
	int R[1024];
	int RPosition = -1;
	int LatestKPosition = -1;
	for (int i = 0; i < 1024; i++)
	{
		R[i]=-1;
	}

	for (int i = 0; i < NLength; i++)
	{
		for (int j = 0; j < KLength; j++)
		{
			if (K[j] == N[i])
			{
				if (R[0] == -1)
				{
					R[0]=K[j];
					RPosition++;
					LatestKPosition = j;
					break;
				}
				else
				{						
					if (j > LatestKPosition)
					{
						RPosition++;
						R[RPosition] = K[j];
						LatestKPosition=j;
						break;
					}
				}
			}
		}
	}
	printf("%d\n", RPosition+1);
	for (int i = 0; i < RPosition+1; i++)
	{
		printf("%d ", R[i]);
	}
}

int main()
{
	int NLength, KLength;
	int N[1024], K[1024];

	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	scanf("%d %d", &NLength, &KLength);
	for (int i = 0; i < NLength; i++)
	{
		scanf("%d", &N[i]);
	}

	for (int i = 0; i < KLength; i++)
	{
		scanf("%d", &K[i]);
	}	

	if (NLength > KLength)
	{
		compute(N, K, NLength, KLength);	
	}
	else
	{
		compute(K, N, KLength, NLength);
	}
	
	return 0;
}

