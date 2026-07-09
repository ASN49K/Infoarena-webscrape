#include <cstdio>
#include <deque>
#define pb(x) push_back(x)

int cmmdc(int a, int b);

int main(){ 
	std::deque<int> a;
	std::deque<int>::iterator it;
	int n, x, y;
	
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	
	scanf("%d", &n);
	
	while(n--){
		scanf("%d %d", &x, &y);
		a.pb(x);
		a.pb(y);
		
		x = cmmdc(a.front(), a.back());
		printf("%d\n", x);
		
		a.pop_back();
		a.pop_back();
	}
	
	return 0;
}

int cmmdc(int a, int b){
	int r;
	while(b){
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
