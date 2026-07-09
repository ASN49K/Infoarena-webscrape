#include<cstdio>

template<class T>
class euclid
{
	T A,B;
	public:
	euclid() {A=0; B=0;}
	void setA(T a) {A=a;}
	void setB(T b) {B=b;}
	void setAB(T a, T b) {A=a; B=b;}
	T getCmmdc()
	{
		T r;
		if(A>B) {r=A; A=B; B=r;}
		while(B)
		{
			r=A%B;
			A=B;
			B=r;
		}
		return A;
	}
};

int main()
{
	int t,a,b;
	euclid<int> aux;
	freopen("euclid2.in","rt",stdin);
	freopen("euclid2.out","wt",stdout);
	scanf("%d",&t);
	for(register int i=0;i<t;i++)
	{
		scanf("%d%d",&a,&b);
		aux.setAB(a,b);
		printf("%d\n",aux.getCmmdc());
	}
	return 0;
}
