#include<fstream>
using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");

int t, n, x, s;

int main(){
	int player_unu=0;

	in>>t;
	for(int shp = 0; shp<t; shp++)
	{
		in>>n;
		s = 0;
		for(int i = 0; i<n; i++)
		{
			in>>x;
			s = s ^ x;
		}

		if(s==0)
			out<<"NU"<<'\n';
		else
			out<<"DA"<<'\n';
	}

	return player_unu;
}