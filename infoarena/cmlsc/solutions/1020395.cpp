// lcs.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include<fstream>
using namespace std;
int m,n;
short int first[260],second[260],matrix[260][260],solution[260],C=0;

ifstream f("cmlsc.in");
ofstream g ("cmlsc.out");

void read()
{
	int i = 1;
	while(i <=m)
	{
		f>>first[i];
		++i;
	}
	i = 1;
	while(i <=n)
	{
		f>>second[i];
		++i;
	}
}


void lcs()
{
		for(int i=0;i<=m;i++)
			matrix[i][0]=0;

		for(int j=0;j<=n;j++)
			matrix[0][j]=0;

		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
			{
				
				if(first[i] ==second[j])
					{
						matrix[i][j] = matrix[i-1][j-1]+1;
					}
				else
					matrix[i][j] = max(matrix[i][j-1],matrix[i-1][j]);
			}
			
		

}

int back(int i,int j)
{

	if(i ==0 || j==0)
		return 1;
	else if(first[i]==second[j])
		{
			solution[++C]=first[i];
			return back(i-1,j-1)+ first[i];
		}
	else
	{
	
		if (matrix[i][j-1] >= matrix[i-1][j])
            return back(i, j-1);
        else
            return back( i-1, j);
	}
}

void print()
{
	   g<<C<<"\n";
	   for(int i=C;i>0;i--)
	   {
			g<<solution[i]<<" ";
	   }
}


int main()
{
	f>>m>>n;
	read();
	lcs();
	back(m,n);
	print();
	return 0;
}

