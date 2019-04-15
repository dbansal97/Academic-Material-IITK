#include <stdio.h>

long int a,b,c,n,m;

long int itfib(long int a,long int b,long int c,long int n,long int m){
	if(n==1){
		return 1%m;
	}
	else if (n==2){
		return 1%m;
		}
	else {
		long int x=1,y=1,temp,i=3;
		while(i<=n){
			temp = y ;
			y = x ;
			x = ( (a*(x%m))%m + (b*(temp%m))%m + c%m)%m ;
			i++ ;
		} return x ;
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

		value = itfib(a,b,c,n,m) ;
	
		printf("%ld\n",value);
	}
	return 0 ;
}