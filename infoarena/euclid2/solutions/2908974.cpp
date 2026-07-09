#include <iostream>
/* sa se afiseze */
using namespace std;
int divizor_comun(int a, int b){

}
int main() {
   int a, b, nr_perechi;


    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    cin>>nr_perechi;
    for (int i=0; i<nr_perechi; i++) {
        cin >> a >> b;
    }
    while (a != b){
        if(a>b)
            a-=b;
        else
            b-=a;

    }
    cout<<a;
    return 0;

}
