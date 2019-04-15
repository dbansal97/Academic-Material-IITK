#include <iostream>

using namespace std;

long long int a,b,c,m ;
unsigned long long int n ;


long long int refib(long long int a,long long int b,long long int c,long long int n,long long int m){
	if(n==1){
		return 1%m;
	}
	else if (n==2){
		return 1%m;
		}
		else {
			return ((a*(refib(a,b,c,n-1,m)%m))%m + (b*(refib(a,b,c,n-2,m)%m))%m + c%m)%m ;
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
		value = refib(a,b,c,n,m) ;
		res[k] = value ;

	}
	for(k=0;k<t;k++){
		cout << res[k] << "\n";
	}
	return 0 ;
}
