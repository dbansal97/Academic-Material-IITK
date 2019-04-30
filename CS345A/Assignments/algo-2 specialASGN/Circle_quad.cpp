#include <iostream>
#include <LEDA/geo/circle.h>
#include <LEDA/geo/point.h>

using namespace std;
using leda::circle;
using leda::point;

int main ()
{
	int n;
	cin >> n;
	point allPoints[n];
	double x,y;
	int i,j,k,l;
	for(i=0;i<n;i++){
		cin >> x >> y;
		point p(x,y);
		allPoints[i] = p;
	}
	double r=1000007;
	point centerPoint;
	for(i=0;i<n;i++){
		double x,y;
		x=allPoints[i].xcoord();
		y=allPoints[i].ycoord();
		for(j=i+1;j<n;j++){
			double x1,y1;
			x1=allPoints[j].xcoord();
			y1=allPoints[j].ycoord();
			point p((x+x1)/2,(y+y1)/2);
			circle c(p,allPoints[i]);
			for(k=0;k<n;k++){
				if(c.outside(allPoints[k])){
					break;
				}			
			}
			if(k==n){
				if(c.radius()<r){
					centerPoint = c.center();
					r=c.radius();
				}
			}
		}
	}
	for(i=0;i<n;i++){
		point p1 = allPoints[i];
		for(j=i+1;j<n;j++){
			point p2 = allPoints[j];
			for(k=j+1;k<n;k++){
				point p3 = allPoints[k];
				circle c(p1,p2,p3);
				for(l=0;l<n;l++){
					if(c.outside(allPoints[l])){
						break;
					}
				}
				if(l==n){
					if(c.radius()<r){
						centerPoint = c.center();
						r=c.radius();
					}
				}
			}
		}
	}
	cout <<"Radius: "<< r << endl;
	cout <<"Center: "<<centerPoint.xcoord()<<" "<<centerPoint.ycoord() << endl;
	return 0;
}