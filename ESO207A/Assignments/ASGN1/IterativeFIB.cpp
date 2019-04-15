#include <iostream>

using namespace std;

long long int a,b,c,m;
unsigned long long int n ;

long long int itfib(long long int a,long long int b,long long int c,unsigned long long int n,long long int m){
	if(n==1){
		return 1%m;
	}
	else if (n==2){
		return 1%m;
		}
	else {
		long long int x=1,y=1,temp,i=3;
		while(i<=n){
			temp = y ;
			y = x ;
			x = ( (a*(x%m))%m + (b*(temp%m))%m + c%m)%m ;
			i++ ;
		} return x ;
	}
}

int main(){

	long long int t,k,value ;
	
	cin >> t ;
	long long int res[t];

	for(k=0;k<t;k++){
		cin >> a >> b >> c >> n >> m ;
		a = a%m ;
		b = b%m ;
		c = c%m ;

		value = itfib(a,b,c,n,m) ;
		res[k] = value ;
	}
	for(k=0;k<t;k++){
		cout << res[k] << "\n";
	}

	return 0 ;
}

	


