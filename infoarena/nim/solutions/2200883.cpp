#include <iostream>

using namespace std;

int main()
{

    int t, n;
    scanf("%d", &t);
    int i;
    for(i = 0; i < t; i++)
    {
        int s = 0;
        int x,j;
        scanf("%d", &n);
        for(j = 0; j < n; j++)
        {
            scanf("%d", &x);
            s = s^x;
        }
        if(s == 0) printf("NU\n");
           else printf("DA\n");
    }
    return 0;
}
