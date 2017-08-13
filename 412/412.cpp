#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>

using namespace std;

void solve();
int gcd(int a, int b);

int main(){
	solve();
	return 0;
}

void solve(){
	int n;
	while(cin >> n && n){

		int list[100];
		for(int i=0; i<n; i++){
			cin >> list[i];
		}

		// pairs have no common factor other than one
		int count = 0;
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				if(gcd(list[i], list[j]) == 1) {count++;}
			}
		}

		// total pairs
		int total = n * (n-1) / 2;

		// calc
		if(!count) printf("No estimate for this data set.\n");
		else{
			double ans = pow((6.0 * total / count), 0.5);
			printf("%.6f\n", ans);
		}
	}
}

int gcd(int a, int b){
	return b ? gcd(b, a%b) : a;
}
