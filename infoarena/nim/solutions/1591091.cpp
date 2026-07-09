#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    freopen("nim.in", "rt", stdin);
    freopen("nim.out", "wt", stdout);
    int T, sumaXor, x, nrGr;
    scanf("%d", &T);
    while(T--)
    {
        sumaXor=0;
        scanf("%d", &nrGr);
        while(nrGr--){
            scanf("%d", &x);
            sumaXor = sumaXor ^ x;
        }
        cout<<(sumaXor == 0 ? "NU\n" : "DA\n");
    }

}
