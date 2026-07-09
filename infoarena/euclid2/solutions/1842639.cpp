// #include <fstream>

// using namespace std;




// int main(){
// 	ifstream file("euclid2.in");
// 	ofstream file_o("euclid2.out");
// 	int it,a,b;
// 	file>>it;
// 	for(int i=0;i<it;i++){
// 		file>>a>>b;
// 		int c;
// 	while(b){
// 		c=a%b;
// 		a=b;
// 		b=c;
// 	}
// 	file_o<<a<<endl;
// 	}

// }
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{int n,i,a,b,r;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        while(a%b)
        {
            r=a%b;a=b;b=r;
        }
        g<<b<<'\n';
    }
    return 0;
}
