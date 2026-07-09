#include <iostream>
#include <fstream>

using namespace std;


struct num_pair
{
	int a;
	int b;
};


int cmmdc(num_pair& p) 
{
	while(1)
	{
		if(!p.a)
		   return p.b;
		else if(!p.b)
		   return p.a;
		else
		{
			if(p.a > p.b)
			  p.a -= p.b;
			else
			  p.b -= p.a;
		}
	}
}



int main()
{
	std::ifstream is("euclid2.in");
	std::ofstream os("euclid2.out");

	int max;
	is >> max;

	num_pair* vect = new num_pair[max];

	for(int i = 0; i < max; ++i)
	{
		is >> vect[i].a;
		is >> vect[i].b;  
	}

	for(int i = 0; i < max; ++i)
	   os << cmmdc(vect[i]) << endl;

	delete vect;

	return 0;
}