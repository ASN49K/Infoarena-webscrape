// Include
#include <fstream>
#include <stack>
using namespace std;

// Constante
const int sz = 1025;

// Variabile
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int aLen, bLen;
int a[sz], b[sz];
int best[sz][sz];

stack<int> answer;

// Main
int main()
{
	in >> aLen >> bLen;
	for(int i=1 ; i<=aLen ; ++i)
		in >> a[i];
	
	for(int i=1 ; i<=bLen ; ++i)
		in >> b[i];
	
	for(int i=1 ; i<=aLen ; ++i)
	{
		for(int j=1 ; j<=bLen ; ++j)
		{
			if(a[i] == b[j])
				best[i][j] = best[i-1][j-1] + 1;
			else
				best[i][j] = max(best[i][j-1], best[i-1][j]);
		}
	}
	
	out << best[aLen][bLen] << '\n';
	
	while(aLen && bLen)
	{
		if(a[aLen] == b[bLen])
		{
			answer.push(a[aLen]);
			--aLen;
			--bLen;
		}
		else
		{
			if(best[aLen-1][bLen] < best[aLen][bLen-1])
				--bLen;
			else
				--aLen;
		}
	}
	
	while(!answer.empty())
	{
		out << answer.top() << ' ';
		answer.pop();
	}
	
	out << '\n';
	
	in.close();
	out.close();
	return 0;
}
