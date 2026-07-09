#include<iostream>
#include<fstream>

//InfoArena
//Euclid

using namespace std;

int cmmdc(int a, int b) {
	
	if (!b) return a;
	else return cmmdc(b, a % b);
}

int main() {
	freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

	scanf("%d", &n);
    for (; n; --n)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", cmmdc(A, B));
    }        
	return 0;
}

