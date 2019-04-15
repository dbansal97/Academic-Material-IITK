#include <stdio.h>

long int a,b,c,n,m ;


long int refib(long int a,long int b,long int c,long int n,long int m){
	if(n==1){
		return 1;
	}
	else if (n==2){
		return 1;
		}
		else {
			return ((a*(refib(a,b,c,n-1,m)%m))%m + (b*(refib(a,b,c,n-2,m)%m))%m + c%m)%m ;
		}
}

int main(){

	long int t,k,value ;
	
	scanf("%ld",&t);
	for(k=0;k<t;k++){
		scanf("%ld %ld %ld %ld %ld",&a,&b,&c,&n,&m);
		a = a%m ;
		b = b%m ;
		c = c%m ;
		value = refib(a,b,c,n,m) ;
		printf("%ld\n",value);

	}
	return 0 ;
}