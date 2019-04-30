#include <iostream>
#include <LEDA/geo/circle.h>
#include <LEDA/geo/point.h>
#include <math.h>

using namespace std;
using leda::circle;
using leda::point;

circle threePointCircle(point b0, point b1, point b2){
	double a,b,c;

	circle final;
	
	a = sqrt((b2.xcoord()-b1.xcoord())*(b2.xcoord()-b1.xcoord()) + (b2.ycoord()-b1.ycoord())*(b2.ycoord()-b1.ycoord()));
	b = sqrt((b2.xcoord()-b0.xcoord())*(b2.xcoord()-b0.xcoord()) + (b2.ycoord()-b0.ycoord())*(b2.ycoord()-b0.ycoord()));
	c = sqrt((b0.xcoord()-b1.xcoord())*(b0.xcoord()-b1.xcoord()) + (b0.ycoord()-b1.ycoord())*(b0.ycoord()-b1.ycoord()));

	if(a*a+b*b>=c*c && c*c+b*b>=a*a && a*a+c*c>=b*b){
		//acute triangle
		circle c1(b0,b1,b2);
		final = c1;
	} else {
		//obtuse triangle
		if(a>b && a>c){
			point centerPoint((b1.xcoord()+b2.xcoord())/2,(b1.ycoord()+b2.ycoord())/2);
			circle c1(centerPoint,b1);
			final = c1;
		} else if(b>a && b>c){
			point centerPoint((b0.xcoord()+b2.xcoord())/2,(b0.ycoord()+b2.ycoord())/2);
			circle c1(centerPoint,b0);
			final = c1;
		} else if(c>a && c>b){
			point centerPoint((b0.xcoord()+b1.xcoord())/2,(b0.ycoord()+b1.ycoord())/2);
			circle c1(centerPoint,b0);
			final = c1;
		}
	}
	return final;
}

circle CircleWithTwoBoundaryPoints(point allPoints[],int k, point b_0, point b_1){
	
	circle allCircles[k+1];

	point centerPoint((b_1.xcoord()+b_0.xcoord())/2,(b_1.ycoord()+b_0.ycoord())/2);
	circle c(centerPoint,b_0);

	if(c.inside(allPoints[0]) || c.contains(allPoints[0])){
		allCircles[0] = c;
	} else {
		allCircles[0] = threePointCircle(b_0 , b_1 , allPoints[0]);
	}

	for(int i=1;i<=k;i++){
		if(allCircles[i-1].inside(allPoints[i]) || allCircles[i-1].contains(allPoints[i])){
			allCircles[i] = allCircles[i-1];
		} else {
			allCircles[i] = threePointCircle(b_0, b_1, allPoints[i]);
		}
	}
	if(k>0){
		return allCircles[k];
	}
	return allCircles[0];
}

circle CircleWithSingleBoundaryPoint(point allPoints[],int j, point b_0){
	
	circle allCircles[j+1];

	point centerPoint((allPoints[0].xcoord()+b_0.xcoord())/2,(allPoints[0].ycoord()+b_0.ycoord())/2);
	circle c0(centerPoint,b_0);
	allCircles[0] = c0;

	for(int i=1;i<=j;i++){
		if(allCircles[i-1].inside(allPoints[i]) || allCircles[i-1].contains(allPoints[i])){
			allCircles[i] = allCircles[i-1];
		} else {
			allCircles[i] = CircleWithTwoBoundaryPoints(allPoints, i-1, b_0, allPoints[i]);
		}
	}
	if(j>0){
		return allCircles[j];
	}
	return allCircles[0];
}

int main ()
{	
	int n;
	cin >> n;
	point allPoints[n];
	double x,y;
	int i;
	for(i=0;i<n;i++){
		cin >> x >> y;
		point p(x,y);
		allPoints[i] = p;
	}
	
	circle allCircles[n];
	point centerPoint((allPoints[0].xcoord()+allPoints[1].xcoord())/2,(allPoints[0].ycoord()+allPoints[1].ycoord())/2);
	circle c1(centerPoint,allPoints[1]);
	allCircles[1] = c1;

	for(i=2;i<n;i++){
		if(allCircles[i-1].inside(allPoints[i]) || allCircles[i-1].contains(allPoints[i])){
			allCircles[i] = allCircles[i-1];
		} else { 
			allCircles[i] = CircleWithSingleBoundaryPoint(allPoints, i-1, allPoints[i]);
		}
	}
	cout << "Center: " << allCircles[n-1].center() << endl;
	cout << "Radius: " << allCircles[n-1].radius() << endl;
	
	return 0;
}