#include <iostream>

using namespace std;

void solve();

int main(){
	solve();
	return 0;
}

void solve(){
	string line;
	while(cin >> line){
		for(int i=0; i<line.size(); i++){
			cout << (char)((int)line[i]-7);
		}
		cout << endl;
	}
}
