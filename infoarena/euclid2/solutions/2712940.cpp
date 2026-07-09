#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int main(){
    int x, a,b;
    cin >> x;
    for(int i = 1; i <= x; i++){
        cin >> a >> b;
        while(a!=b){
        if(a>b)
            a=a-b;
        else
            b=b-a;
    }
    cout << a<< endl;
}

    return 0;
}
