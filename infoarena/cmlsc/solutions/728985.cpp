//Include
#include <fstream>
#include <vector>
using namespace std;

//Constante
const int MAX_SIZE = 257;

//Variabile
ifstream in("cmlsc.in"); // Puteati si voi sa-i dati un nume mai ok
ofstream out("cmlsc.out");

int sir1Len, sir2Len;
int sir1[MAX_SIZE], sir2[MAX_SIZE];
int best[MAX_SIZE][MAX_SIZE];

vector<int> rasp;
vector<int>::reverse_iterator rit, rend;

//Main
int main()
{
	in >> sir1Len >> sir2Len;
	for(int i=1 ; i<=sir1Len ; ++i)
		in >> sir1[i];
	
	for(int i=1 ; i<=sir2Len ; ++i)
		in >> sir2[i];
	
	for(int i=1 ; i<=sir1Len ; ++i)
		for(int j=1 ; j<=sir2Len ; ++j)
		{
			if(sir1[i] == sir2[j])
				best[i][j] = best[i-1][j-1] + 1;
			else
				best[i][j] = max(best[i-1][j], best[i][j-1]);
		}
	
	out << best[sir1Len][sir2Len] << '\n';
	
	rasp.reserve(best[sir1Len][sir2Len]);
	int i = sir1Len;
	int j = sir2Len;
	
	while(i && j)
	{
		if(sir1[i] == sir2[j])
		{
			rasp.push_back(sir1[i]);
			--i, --j;
		}
		else
		{
			if(best[i][j-1] > best[i-1][j])
				--j;
			else
				--i;
		}
	}
	
	rend = rasp.rend();
	for(rit=rasp.rbegin() ; rit!=rend ; ++rit)
		out << *rit << ' ';
	out << '\n';
	
	in.close();
	out.close();
	return 0;
}
