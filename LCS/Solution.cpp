#include "Solution.h"
#include <string>

using namespace std;

int main() {
	string words[10][2] = {
		{ "abbababa", "babaabaab" },
		{ "hello", "hi" },
		{ "byebye", "bye" },
		{ "Superman", "Batman" },
		{ "Boomer", "Zoomer" },
		{ "AHHHHHHHH", "N0" },
		{ "pen", "shen" },
		{ "content", "tentcon" },
		{ "banger", "ranger" },
		{ "pewpew", "kawai" },
	};
	Solution lcs = Solution();
	for (int i = 0; i < 10; i++) {
		string word1 = words[i][0];
		string word2 = words[i][1];
		lcs.run(word1, word2);
	}
	return 0;
}