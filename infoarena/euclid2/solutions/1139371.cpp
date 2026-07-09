#include<fstream>
#include<iostream>

using namespace std;

int euclid (int first, int second)
{
	if (!second)
	{
		return first;
	}
	return euclid(second,first%second);
}

int main ()
{
  	ifstream in;
  	ofstream out;
  	in.open("euclid2.in");
  	out.open("euclid2.out");
  	int T;
  	int a,b;
  	in>>T;
  	while (T)
  	{
    		in>>a>>b;
    		out<<euclid(a,b)<<endl;
    		--T;
  	}
  	in.close();
  	out.close();
  	return 0;
}

