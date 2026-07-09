#include <stdio.h>

int main() {
	int a = 6;
	int b = 9;
	int r;
	printf("%d\n", 3%6);
    while(a%b!=0) {
        r=a%b;

        a=b;

        b=r;
    }

	printf("%d", b);

    return 0;
}
