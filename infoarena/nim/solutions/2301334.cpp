#include <fstream>
std::ifstream cin("nim.in");
std::ofstream cout("nim.out");
int T,n; //NEED TO LEARN MORE ABOUT GAMES IN C++
int main() //BUT I HATE THEM ATM XD
{
	int sol,a;
	cin>>T;
	for(;T--;){
		sol=0;
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a;
			sol^=a;
		}
		if(sol)
			cout<<"DA\n";
		else
			cout<<"NU\n";
	}
	return 0;
}
