#include <iostream>

using namespace std;

long long int base_mat[3][3] = {0};
long long int result[3][3] = {0};
long long int m ;

void mult(long long int mat1[3][3],long long int mat2[3][3],long long int mmatrix[3][3]){
	int i,j,k;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			mmatrix[i][j]=0 ;
			for(k=0;k<3;k++){
				mmatrix[i][j] = (mmatrix[i][j]%m + ((mat1[i][k]%m)*(mat2[k][j]%m)%m))%m;
			}
		}
	}
}

void f_mat(unsigned long long int n, long long int result[3][3]){
	int i,j ;
	if(n==1){
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				result[i][j] = base_mat[i][j] ;
			}
		}
		return ;
	}
	long long int half_matrix[3][3];
	f_mat(n/2,half_matrix);
	long long int sqhalf_matrix[3][3];
	if(n%2 == 0){
		mult(half_matrix,half_matrix,sqhalf_matrix) ;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				result[i][j] = sqhalf_matrix[i][j] ;
			}
		}
	}
	else {
		mult(half_matrix,half_matrix,sqhalf_matrix) ;
		mult(sqhalf_matrix,base_mat,result) ;
	}
}

long long int fib(unsigned long long int n,long long int m){
	if(n==1){return 1;}
	if(n==2){return 1;}
	else {
		f_mat(n-2,result) ;
		return (result[0][0]%m +result[0][1]%m + result[0][2]%m )%m ;
	}
}

int main(){

	unsigned long long int n ;
	long long int t,k,value,a,b,c;

	cin >> t ;

	long long int res[t];

	for(k=0;k<t;k++){
		cin >> a >> b >> c >> n >> m ;
		base_mat[0][0] = a ;
		base_mat[0][1] = b ;
		base_mat[0][2] = c ;
		base_mat[1][0] = 1 ;
		base_mat[2][2] = 1 ;
	
		value = fib(n,m) ;
		res[k] = value ;
	}
	for(k=0;k<t;k++){
		cout << res[k] << "\n";
	}

	return 0 ;
}
