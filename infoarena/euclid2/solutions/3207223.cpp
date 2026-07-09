#include <iostream>
#include <stdio.h>

int Euclid(int a, int b)
{
    int rest = a % b;
    
    if (!rest)
        return b;
        
    else
        return Euclid(b, rest);

}

int main()
{
    int v[2], N;
    scanf ("%d", &N);
	while (N--)
	{
		scanf("%d %d",&v[0],&v[1]);     
		printf( "%d\n", Euclid(v[0],v[1]) );
    }
    return 0;
}
