#include <iostream>
using namespace std;


int main(void)
{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	int n;
	cin >> n;

	long a, b;
	for(int i=0;i<n;++i) 
	{
		cin >> a >> b;
		if(a<b) 
		{
			int c = a;
			a = b;
			b = c;
		}
		
		int r;
		do 
		{
			r = a%b;
			a = b;
			b = r;
		}while(r != 0);
		cout << a << endl;
	}
	return 0;
}