#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

struct Point{
	double x; double y;
};

struct Rect{
	double x1, y1;
	double x2, y2;
};

void solve();
bool isIn(Point p, Rect r);

int main(){
	solve();
	return 0;
}

void solve(){
	Point p;
	vector<Point> vp;

	Rect r;
	vector<Rect> vr;
	
	// input rectangles
	string line;
	while(cin >> line && line[0] != '*'){
		cin >> r.x1 >> r.y1 >> r.x2 >> r.y2;
		vr.push_back(r);
	}
	
	// input points
	while(cin >> p.x >> p.y && !(p.x==9999.9 && p.y==9999.9)){
		vp.push_back(p);
	}

	// output
	for(int i=0; i<vp.size(); i++){
		bool notContained = true;
		for(int j=0; j<vr.size(); j++){
			if(isIn(vp[i], vr[j])){
				notContained = false;
				printf("Point %d is contained in figure %d\n", i+1, j+1);
			}
		}
		if(notContained) printf("Point %d is not contained in any figure\n", i+1);
	}
}

bool isIn(Point p, Rect r){
	return (r.x1<p.x && p.x<r.x2) && (r.y2<p.y && p.y<r.y1);
}
