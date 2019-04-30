#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main ()
{	
	int n;
	cin >> n;
	int i,x,y;
	for(i=0;i<n;i++){
		x = rand()%1000000;
		y = rand()%1000000;
		cout << x << "	" << y << endl;
	}

	return 0;
}