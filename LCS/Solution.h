#ifndef SOLUTION
#define SOLUTION

#include <set>
#include <string>

using namespace std;

class Solution {
	private:
		int longestSubsequenceLength;
		set<string> longestSubsequences;
		void initTable();
		void getSequences();
	public:
		Solution(string str1, string str2);
		void longestCommonSubsequence();
};

#endif
