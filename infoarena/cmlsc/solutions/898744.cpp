// Include
#include <fstream>
#include <vector>
using namespace std;

// Definitii
#define pb push_back

// Constante
const int sz = 1025;

// Variabile
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int firstLen, secondLen;
int first[sz], second[sz];

int best[sz][sz];

vector<int> answer;

// Main
int main()
{
	in >> firstLen >> secondLen;
	for(int i=1 ; i<=firstLen ; ++i)
		in >> first[i];
	for(int i=1 ; i<=secondLen ; ++i)
		in >> second[i];
	
	for(int i=1 ; i<=firstLen ; ++i)
		for(int j=1 ; j<=secondLen ; ++j)
			if(first[i] == second[j])
				best[i][j] = best[i-1][j-1] + 1;
			else
				best[i][j] = max(best[i][j-1], best[i-1][j]);
	
	out << best[firstLen][secondLen] << '\n';
	
	while(firstLen && secondLen)
	{
		if(first[firstLen] == second[secondLen])
		{
			answer.pb(first[firstLen]);
			--firstLen, --secondLen;
		}
		else
		{
			if(best[firstLen][secondLen-1] < best[firstLen-1][secondLen])
				--firstLen;
			else
				--secondLen;
		}
	}
	
	vector<int>::reverse_iterator it, end=answer.rend();
	for(it=answer.rbegin() ; it!=end ; ++it)
		out << *it << ' ';
	out << '\n';
	
	
	
	
	in.close();
	out.close();
	return 0;
}
