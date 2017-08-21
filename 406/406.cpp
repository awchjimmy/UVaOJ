#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

void solve();
void create_table(vector<int> & p);

int main(){
	solve();
	return 0;
}

void solve(){
	// create prime table
	vector<int> p;
	create_table(p);

	int n, c;
	while(cin >> n >> c){
		printf("%d %d:", n, c);

		// total prime less than or equal to n
		int total = upper_bound(p.begin(), p.end(), n) - p.begin();

		// output
		int start = 0;
		int delta = 0;

		if(total%2==0){
			if(2*c > total){ start = 0; delta = total; }
			else{ start = total/2 - c; delta = 2*c; }
		}else{
			if(2*c+1 > total){ start = 0; delta = total; }
			else{ start = total/2 - c + 1; delta = 2*c-1; }
		}
		for(int i=start; i<start+delta; i++){ printf(" %d", p[i]); }
		printf("\n\n");
	}

}

void create_table(vector<int> & p){
	int n = 1000;
	bool notP[n+1] = {0};
	for(int i=2; i<=n; i++){
		if(notP[i]) continue;
		for(int j=2; i*j<=n; j++){
			notP[i*j] = true;

		}
	}
	
	for(int i=1; i<=n; i++){
		if(!notP[i]) p.push_back(i);
	}
}
