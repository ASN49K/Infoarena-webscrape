#include <cstdio>
using namespace std;

template<class T>
class Euclid {
public:
	static T gcd(T x, T y) {
		if (y == 0) {
			return x;
		}
		else {
			return gcd(y, x % y);
		}
	}
};

int main(void)
{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	int t, x, y;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &x);
		scanf("%d", &y);
		printf("%d\n", Euclid<int>::gcd(x, y));
	}

	return 0;
}