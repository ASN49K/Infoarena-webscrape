# include <fstream>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int euclid(int a, int b){
    if (a%b==0) return b;

    return euclid(b,a%b);
    }

int main()
{
    int t,a,b;
    cin>>t;
    for (;t;t--)
    {
        cin>>a>>b;
        cout<<euclid(a,b)<<"\n";
    }

   cin.close();
   cout.close();

}
