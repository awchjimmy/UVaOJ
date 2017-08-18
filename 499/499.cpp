#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

void solve();

int main(){
	solve();
	return 0;
}

void solve(){
	string line;

	while(getline(cin, line)){
		int max_freq = 0;
		map<char, int> mci;

		// calc freq
		for(int i=0; i<line.size(); i++){
			if(isalpha(line[i])){
				int f = 0;
				mci[line[i]]++;
				max_freq = max_freq > mci[line[i]] ? max_freq : mci[line[i]];
			}
		}

		// output
		string ans = "";
		for(map<char, int>::iterator it=mci.begin(); it!=mci.end(); it++){
			if(it->second == max_freq) ans += it->first;
		}
		cout << ans << " " << max_freq << endl;
	}
}
