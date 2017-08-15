#include <iostream>
#include <stdio.h>

using namespace std;

void solve();

int main(){
	solve();
	return 0;
}

void solve(){
	int line_count = 0;
	string line, lines[150];
	int max_len = 0;

	// input
	while(getline(cin, line)){
		lines[line_count++] = line;
		if(line.size() > max_len) max_len = line.size();
	}

	// output
	for(int i=0; i<max_len; i++){
		for(int j=line_count-1; j>=0; j--){
			if(i >= lines[j].size()) printf(" ");
			else printf("%c", lines[j][i]);
		}
		printf("\n");
	}
}
