#include<bits/stdc++.h>
using namespace std;
void op(int arr[],int n){
	
	
		if(n<=1){
			return ;
		}
		else if(n==2){
		int temp=arr[1];
		arr[1]=arr[0];
		arr[0]=temp;
		return ;
	}
	else{
		int ans[n];
		int sz_a=n/3,sz_b=n/3,sz_c=n/3;
		if(n%3==0){	

		}
		else if(n%3==1){
			
			sz_c=n/3+1;
		}
		else if(n%3==2){
			
			sz_c=n/3+1;
			sz_b=n/3+1;
		}
		int j=0;
		for(int i=2;i<n;i+=3){
		ans[j]=arr[i];
		j++;
	}
		for(int i=1;i<n;i+=3){
		ans[j]=arr[i];
		j++;
	}
	for(int i=0;i<n;i+=3){
		ans[j]=arr[i];
		j++;
	}
	
	op(ans,sz_a);
	op(ans+sz_a,sz_b);
	op(ans+sz_a+sz_b,sz_c);
	

	for(int i=0;i<n;i++){
		arr[i]=ans[i];
	}
	
		return ;
	}
	
}
int main(){
	int n;
	cin>>n;
	int *d;
	d=(int* ) malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		cin>>d[i];
	}

	op(d,n);
	
	int sum[n];
	sum[0]=d[0];
	if(d[0]>1000001||d[0]<-1000001){
		sum[0]=0;
	}
	for(int i=1;i<n;i++){
		if(d[i]>=-1000001&&d[i]<=1000001)
		sum[i]=sum[i-1]+d[i];
		else{
			sum[i]=sum[i-1];
		}
	}
	int q;
	cin>>q;
	int i,j,l,r,res=0;
	for(int k=0;k<q;k++){
		cin>>i>>j>>l>>r;
		if(i!=0)
		 res=sum[j]-sum[i-1];
		if(i==0)
			 res=sum[j];
		cout<<res<<endl;
	}
	return 0;
}