#include <iostream>

using namespace std;

void solve();

int main(){
	solve();
	return 0;
}

void solve(){
	string line;
	while(getline(cin, line) && line != ""){

		// normalize, add whitespace at the end
		line += ' ';

		// reverse
		for(int i=0; i<line.size(); i++){
			if(line[i]==' '){
				for(int j=i-1; j>=0&&line[j]!=' '; j--){
					cout << line[j];
				}
				// denormalize, delete whitespace at the end
				if(i != line.size()-1){ cout << ' '; }
			}
		}
		cout << endl;
	}
}
