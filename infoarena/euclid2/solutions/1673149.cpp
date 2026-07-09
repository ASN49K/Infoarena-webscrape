#include <iostream>
#include <stdio.h>

using namespace std;

int euclid(int a, int b){
    if (b == 0)
        return a;
    else
        return euclid(b, a%b);
}

int main()
{
    int a, b, n;

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &n);

    for (int i = 0 ; i < n ; i++){
        scanf("%d %d", &a, &b);
        cout << euclid(a,b) << endl;
    }

    fclose(stdout);
    fclose(stdin);
    return 0;
}
