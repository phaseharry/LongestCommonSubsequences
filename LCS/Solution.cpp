#include "Solution.h"
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

Solution::Solution() {}

/* 
initializes the tabulation table where rows represent the length of word1 
and cols represents the length of col 
*/
void Solution::initTable() {
	int rows = word1.length() + 1;
	int cols = word2.length() + 1;
	int **table = new int*[rows];
	for (int i = 0; i < rows; i++) {
		table[i] = new int[cols];
		for (int j = 0; j < cols; j++) {
			table[i][j] = 0;
		}
	}
	lcsTable = table;
}

/*
clears the tabulation table after each word pairs run so its cleared for the 
next pair of words
*/
void Solution::clearTable() {
	int rows = word1.length();
	int cols = word2.length();
	for (int i = 0; i < rows; i++) {
		delete[] lcsTable[i];
	}
	delete[] lcsTable;
}

/*
Generates the list of longest subsequences based on the table
*/
void Solution::getSequences(int w1, int w2, string str) {
	if (w1 < 0 || w2 < 0) return; // if either pointers are out of bounds, just stop.
	if (lcsTable[w1][w2] == 0) { // if we reach a 0 in the table, we know we have a subsequence, so add it to the set
		longestSubsequences.insert(str);
		return;
	}
	// if the characters are each, then we know that they are part of a common subsequence so move both pointers and increment it with the current character
	if (word1[w1 - 1] == word2[w2 - 1]) getSequences(w1 - 1, w2 - 1, word1[w1 - 1] + str); 
	// check both cases where 1 pointer goes down and the other stays the same
	if (lcsTable[w1][w2] == lcsTable[w1][w2 - 1]) getSequences(w1, w2 - 1, str);
	if (lcsTable[w1][w2] == lcsTable[w1 - 1][w2]) getSequences(w1 - 1, w2, str);
}

/*
Computes the longest subsequence of both words.
*/
void Solution::longestCommonSubsequence() {
	initTable();
	for (int row = 1; row <= word1.length(); row++) {
		int *prevRow = lcsTable[row - 1];
		int *currentRow = lcsTable[row];
		for (int col = 1; col <= word2.length(); col++) {
			if (word1[row - 1] == word2[col - 1]) {
				lcsTable[row][col] = 1 + prevRow[col - 1];
			}
			else {
				lcsTable[row][col] = max(prevRow[col], currentRow[col - 1]);
			}
		}
	}
	getSequences(word1.length(), word2.length(), "");
	longestSubsequenceLength = lcsTable[word1.length()][word2.length()];
	printResults();
}

void Solution::printLcsTable() {
	for (int row = 0; row <= word1.length(); row++) {
		for (int col = 1; col <= word2.length(); col++) {
			cout << lcsTable[row][col] << " ";
		}
		cout << endl;
	}
}

void Solution::printResults() {
	cout << "Longest subsequences of " << word1 << " & " << word2 <<
		" are of length " << longestSubsequenceLength << endl;
	cout << "Subsequences: " << endl;
	set<string>::iterator itr;
	for (itr = longestSubsequences.begin(); itr != longestSubsequences.end(); itr++) {
		cout << *itr << endl;
	}
}

void Solution::run(string str1, string str2) {
	longestSubsequenceLength = 0;
	longestSubsequences.clear();
	clearTable();
	word1 = str1;
	word2 = str2;
	longestCommonSubsequence();
}