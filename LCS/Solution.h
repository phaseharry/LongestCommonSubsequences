#ifndef SOLUTION
#define SOLUTION

#include <set>
#include <string>

using namespace std;

class Solution {
	private:
		int longestSubsequenceLength;
		set<string> longestSubsequences;
		int **lcsTable;
		string word1, word2;
		void initTable();
		void clearTable();
		void getSequences(int w1, int w2, string str);
		void printResults();
		void printLcsTable();
	public:
		Solution();
		void longestCommonSubsequence();
		void run(string str1, string str2);
};

#endif
