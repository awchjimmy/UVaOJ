#include <iostream>

using namespace std;

void solve();
int check(string s);

int main(){
	solve();
	return 0;
}

void solve(){
	int n;
	cin >> n;

	for(int i=0; i<n; i++){
		if(i) cout << endl;

		string line;
		cin >> line;
		cout << check(line) << endl;
	}

}

int check(string s){
	for(int len=1; len<=s.size(); len++){
		bool ok = !(s.size()%len);
		for(int i=0; i<s.size()&&ok; i++){
			if(s[i] != s[i%len]){ok = false;}
		}
		if(ok){return len;}
	}

}
