#include <iostream>
//#include <fstream>

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
	FILE* in_handle = fopen("euclid2.in", "r"); 
	FILE* out_handle = fopen("euclid2.out", "w");

	if(in_handle)
	{
		int max;

		fscanf(in_handle, "%d", &max);

		num_pair* vect = new num_pair[max];

		for(int i = 0; i < max; ++i)
		{
			fscanf(in_handle, "%d", &vect[i].a);
			fscanf(in_handle, "%d", &vect[i].b);
		}

		for(int i = 0; i < max; ++i)
		   fprintf(out_handle, "%d\n", cmmdc(vect[i]));	  

		delete vect;
	}

	fclose(in_handle);
	fclose(out_handle);

	return 0;
}