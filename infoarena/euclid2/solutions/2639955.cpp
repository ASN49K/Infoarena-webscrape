#include <iostream>
#include <fstream>

using namespace std;
int test(int _n , int _m );
int main()
{

    ifstream fisier_in("euclid2.in");
    ofstream fisier_out("euclid2.out");
    int t;
    fisier_in >> t;
    while(t != 0){
    int a,b;
    fisier_in >> a>>b;
    fisier_out << test(a,b) << '\n';
    t--;
    }
return 0;

}


int test(int _n , int _m ){
if(_m == 0){
    return _n;
}
    return test(_m , _n%_m);

}



