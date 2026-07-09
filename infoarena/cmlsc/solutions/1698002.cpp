#include<fstream>
#include<algorithm>
#include<stack>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int A[1050], B[1050], l_a, l_b, D[1050][1050], i, j;
stack<int> stk;
int main()
{
	
	in >> l_a >> l_b;

	for (i = 1; i <= l_a; ++i)
		in >> A[i];

	for (j = 1; j <= l_b; ++j)
		in >> B[j];

	for (i = 1;i <= l_a;++i)
		for (j = 1;j <= l_b;++j)
			if (A[i] == B[j])
				D[i][j] = D[i - 1][j - 1] + 1;
			else
				D[i][j] = max(D[i - 1][j], D[i][j - 1]);

	out << D[--i][--j]<<'\n';

	while (D[i][j])
	{
		if (D[i - 1][j] == D[i][j])
			--i;
		else if (D[i][j - 1] == D[i][j])
			--j;
		else
		{
			stk.push(A[i]);
			--i, --j;
		}
	}

	while (stk.size())
		out << stk.top() << " ", stk.pop();

	return 0;
}