	#include<stdio.h>
	FILE *f ,*g ;
	int v1[101] , v2[101] , m , n  , a[101][101] , k , subsir[101] ;
	
	void citire();
	void max();
	void parcurgere();
	void tipar();
	
	int main()
	{
		citire();
		max();
		parcurgere();
		tipar();
		return 0;
	}
	
	void citire()
	{
		f=fopen("cmlsc.in" , "r" );
		fscanf(f , "%d" , &n );
		fscanf(f , "%d" , &m );
		for ( int  i = 1 ;  i <= n ; ++i )
			fscanf(f , "%d" , &v1[i] ) ;
		for ( int  i = 1 ; i <= m ; ++i )
			fscanf(f , "%d" , &v2[i] );
		fclose(g);
	}
	
	void max()
	{
		for( int i = 1 ; i <= n ; ++i )
			for ( int j = 1 ; j <= m ; ++j )
				if( v1[i] == v2[j])
					a[i][j] = 1 + a[i-1][j-1];
					else 
						if( a[i-1][j] >= a[i][j-1])
							a[i][j] = a[i-1][j];
						else 
							a[i][j] = a[i][j-1];
	}
	
	void parcurgere()
	{
		int	j = m , i = n ;
		k = 1;
		while(k <= a[n][m])
		{
			if(v1[i] == v2[j])
			{
				subsir[k++] = v1[i] ;
				i--;
				j--;
			}
			else 
				if( a[i-1][j] > a[i][j-1])
					i--;
				else 
					j--;
		}
	}
	
	void tipar()
	{
		g=fopen("cmlsc.out" , "w" );
		fprintf(g , "%d\n" , a[n][m] );
		for ( int i = k-1 ; i >= 1 ; --i )
			fprintf(g , "%d " , subsir[i] );
		fclose(g);
	}
	