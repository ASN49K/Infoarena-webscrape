/*
 * main.cpp
 *
 *  Created on: Jun 25, 2013
 *      Author: alexei
 */

#include <cmath>
#include <cstdio>

#include <string>

/*
 * Custom Math Library
 * Purpose: Fun
 */

template< class T >
class cMath{

public:

	static T gcd( T a, T b )
	{
		T t;

		while( b )
		{
			t = a%b;
			a = b;
			b = t;
		}

		return a;
	}

};

void read()
{
	int T;
	scanf("%d\n", &T);

	int a1, a2;
	while( T-- )
	{
		scanf("%d %d\n", &a1, &a2 );
		printf("%d\n", cMath<int>::gcd(a1,a2) );
	}

}

int main()
{

#ifndef ONLINE_JUDGE
	std::string TASK_ID("euclid2");
	freopen( (TASK_ID + ".in").c_str(), "r", stdin );
	freopen( (TASK_ID + ".out").c_str(), "w", stdout );
#endif

	read();

	return 0;
}


