#include <iostream>

using namespace std;

void solve();

int main(){
	solve();
	return 0;
}

void solve(){
	string line;
	while(getline(cin, line)){

		// replace non-alpha with whitespace
		for(int i=0; i<line.size(); i++){
			if(!isalpha(line[i])){ line[i] = ' '; }
		}

		// count
		int cnt = 0;
		for(int i=0; i<line.size(); i++){
			if(isalpha(line[i])){
				if(i==0 || line[i-1]==' '){ cnt++; }
			}
		}
		cout << cnt << endl;
	}
}
