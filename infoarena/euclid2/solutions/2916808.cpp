#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int euclid(int x, int y){
    while(y!=0){
int r=x%y;
x = y;
y = r;
    }
    cout << x << endl;
    return 0;

}
int main()
{
 int T;
 cin >> T;
 for(int i=1;i<=T;i++)
 {
     int x,y;
     cin >> x >> y;
     euclid(x,y);
}


}
