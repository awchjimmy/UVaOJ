#include <iostream>
#include <stdio.h>

using namespace std;

void solve();
string game_res(string ans, string guess);

int main(){
	solve();
	return 0;
}

void solve(){
	int n;
	while(cin >> n && n != -1){
		string ans, guess;
		cin >> ans >> guess;

		cout << "Round " << n << endl;
		cout << game_res(ans, guess) << endl;

	}
}

string game_res(string ans, string guess){
	string msg_win = "You win.";
	string msg_lose = "You lose.";
	string msg_fail = "You chickened out.";

	// simulate hangman judge gameplay
	int chances = 7;
	bool guessed[26] = {0};
	for(int i=0; i<guess.size()&&chances; i++){
		// log unique guess, condition 3
		if(guessed[guess[i]-'a']) continue;
		else guessed[guess[i]-'a'] = true;

		bool correct_char = false;
		for(int j=0; j<ans.size(); j++){
			if(ans[j] == guess[i]){
				correct_char = true;
				ans[j]=' ';
			}
		}
		if(!correct_char) chances--;
	}


	// judge win / lose
	bool win = true;
	for(int i=0; i<ans.size(); i++){
		if(isalpha(ans[i])) win = false;
	}
	if(win) return msg_win;
	return chances ? msg_fail : msg_lose;
}
