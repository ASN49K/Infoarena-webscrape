#import<fstream>
std::ifstream f("nim.in");std::ofstream g("nim.out");main(){int t,n,x,a;f>>t;while(t--){f>>n;x=0;while(n--)f>>a,x^=a;if(x)g<<"DA\n";else g << "NU\n";}}
