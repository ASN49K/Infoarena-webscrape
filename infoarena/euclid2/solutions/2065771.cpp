#include <fstream>

using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int main()
{
    int i,a,b,t,cmmdc(int,int);
    cin >> t;
    for(i=t;i>0;i--){
        cin >> a >> b;
        cout << cmmdc(a,b) << endl;
    }
    return 0;
}
int cmmdc(int a, int b){
    if(b==0){
        return a;
    }
    return cmmdc(b,b%a);

}
