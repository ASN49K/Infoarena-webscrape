#include <fstream>;
using namespace std;


int cmmdcBrut(int a, int b){
    int i = min(a,b);
    for (i; i>0; i--){
        if((a % i == 0) && (b % i == 0)){
            break;
        }
    }
    return i;
}

int cmmdcScaderi(int a, int b){
    while (a != b){
        if (a > b){
            a = a - b;
        } else
        {
            b = b - a;
        }

    }

    return a;

}

int cmmdcImpartiri(int a, int b){
    if (b == 0) return a;
    return cmmdcImpartiri(b, a % b);

}

int main(){
    int n,a,b;
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &n);
    for (; n; --n)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", cmmdcScaderi(a, b));
    }
    return 0;

}
