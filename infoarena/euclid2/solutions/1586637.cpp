#include <iostream> 

using namespace std;

int euclid(int a, int b)
{
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
} 
 
int main()
{
    int n,a,b;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		cout << euclid(a,b)<<endl;
	} 
    return 0;
}
