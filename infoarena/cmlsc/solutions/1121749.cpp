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
int best[sz][sz]; // best[i][j] e lungimea celui mai lung subsir comun a sirurilor a[1..i] si b[1..j]

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
			// In cazul in care a[i] este egal cu b[j], lungimea cmlsc a sirurilor a[1..i] si b[1..j] va
			// cu 1 mai mare decat lungimea cmlsc a sirurilor a[1..i-1], b[1..j-1], deci best[i-1][j-1]+1
			if(a[i] == b[j])
				best[i][j] = best[i-1][j-1] + 1;
			// Altfel, lungimea cmlsc a sirurilor a[1..i], b[1..j] va fi maximul dintre lungimea cmlsc
			// a sirurilor a[1..i-1], b[1..j] si lungimea cmlsc a sirurilor a[1..i], b[1..j-1]
			else
				best[i][j] = max(best[i-1][j], best[i][j-1]);
		}
	}
	
	// Pentru ca best[aLen][bLen] reprezinta lungimea cmlsc a sirurilor a[1..aLen], b[1..bLen],
	// deci a sirurilor a si b, acela va fi rezultatul final
	out << best[aLen][bLen] << '\n';
	
	// Parcurg matricea de la coada la cap
	
	int i=aLen, j=bLen;
	while(i && j)
	{
		// In cazul in care, in timpul constructiei, a[i] era egal cu b[j], ma intorc pe diagonala (de unde am venit).
		// Tot in acest caz, deoarece lungimea a crescut, sunt pe o solutie buna si o retin pentru raspuns
		if(a[i] == b[j])
		{
			answer.push(a[i]);
			--i;
			--j;
		}
		// In caz contrar, ma voi intoarce pe drumul cu valoare mai mare,
		// aceea fiind valoarea aleasa de maxim in timpul constructiei
		else
		{
			if(best[i-1][j] > best[i][j-1])
				--i;
			else
				--j;
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
