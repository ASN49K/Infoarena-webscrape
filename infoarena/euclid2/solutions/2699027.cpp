#include <fstream>

using namespace std;
int Euclid(int x , int y){
    if(y == 0)
        return y;
    else return Euclid(y, x%y);
}

int main()
{
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    int n , a , b;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a >> b;
       cout<< Euclid(a,b) << endl;
    }

    return 0;
}
