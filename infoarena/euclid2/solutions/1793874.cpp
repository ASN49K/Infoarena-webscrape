#include<iostream>
#include<fstream>

using namespace std;
//std is an abbreviation of standard=the standard namespace
//cout, cin and more are defined in it (one way to call them would be by using std::cout and std::cin) 


int euclid(int a, int b)
{
	while (a != 0 && b != 0)
	{
		if (a >= b)
			a = a%b;
		else
			b = b%a;
	}
	if (a == 0)
		return b;
	else
		return a;
}


int main()

{
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");

	int T, a, b;
	in >> T;
	for (int i = 0; i < T; i++)
	{
		in >> a;
		in >> b;
		out << euclid(a, b) << "\n";
	}
	in.close();
	out.close();
	return 0;
}