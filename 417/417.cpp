#include <iostream>
#include <map>

using namespace std;

void solve();
void rec(string seq, int n, map<string, int>& msi);

int index = 0;

int main(){
	solve();
	return 0;
}

void solve(){
	// create table
	map<string, int> msi;
	for(int i=1; i<=5; i++){
		rec("", i, msi);
	}

	// query
	string line;
	while(cin >> line){
		cout << msi[line] << endl;
	}
}

void rec(string seq, int n, map<string, int>& msi){
	if(seq.size() == n){
		msi[seq] = ++index;
	}
	else{
		for(char ch='a'; ch<='z'; ch++){
			int preIndex = seq.size() - 1;
			if(seq.size() == 0  || preIndex>=0 && ch>seq[preIndex]){ // strictly ascending order
				rec(seq+ch, n, msi);
			}

		}
	}
}
