#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

#define SIGMA 512
#define MAXP 2048
#define pb push_back
#define mkp make_pair

int X[MAXP], Y[MAXP];
int N, M, P, S[MAXP];

vector <int> alpha[SIGMA];
vector <pair<int, int> > A[MAXP];

void recon(int l, int c, int layer)
{
	if (layer <= 0) goto finally;

	for (int i = 0; i < A[layer].size(); ++i)
	{
		int nl = A[layer][i].first;
		int nc = A[layer][i].second;
		if (nl < l && nc < c)
		{
			recon(nl, nc, layer - 1);
			break;
		}
	}	

	finally: 
	printf("%d ", X[l]);
}

void printA()
{
	// Here we print A in case we need to debug
	for (int i = 1; i <= P; ++i)
	{
		for (int j = 0; j < A[i].size(); ++j)
			cout << "(" << A[i][j].first << "," << A[i][j].second << ") "; 
		cout << endl;
	}	
}

int main()
{
	// We assume the alphabet is the lowercase english alphabet(for simplicity, without restraining generality)
	//cin >> X >> Y;
	//N = X.size();
	//M = Y.size();	

	

	freopen ("cmlsc.in", "r", stdin);
	freopen ("cmlsc.out", "w", stdout);

	scanf ("%d %d", &N, &M);

	for (int i = 0; i < N; ++i) scanf ("%d", &X[i]);
	for (int i = 0; i < M; ++i) scanf ("%d", &Y[i]);

	for (int i = 0; i < M; ++i) alpha[Y[i]].pb(i);
	for (int i = 0; i < MAXP; ++i) S[i] = N;	

	// Here we compute A's
	for (int i = 0; i < N; ++i)
	{
		int ind = X[i];
		int curA = 1;
		int curS = S[curA];	
		for (int j = 0; j < alpha[ind].size();)
		{
			int pos = alpha[ind][j];
			P = max(P, curA);
			if (pos <= S[curA])
			{
				A[curA].pb(mkp(i,pos));	
				curS = min(curS, pos);
				++j;
			}
			else
			{
				S[curA] = curS;
				++curA;
				curS = S[curA];
			}
		}
		S[curA] = curS;
	}

	//printA();
	//cout << "The longest common subsequence of " << X << " and " << Y << " is: ";

	// Here we reconstruct the solution	
	printf ("%d\n", P);
	int l = A[P][0].first, c= A[P][0].second;
	recon(l, c, P-1);
	printf ("\n");

	return 0;
}
