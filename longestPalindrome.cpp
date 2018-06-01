#include <iostream>
#include <stdio.h>
#include <string.h>

// Find the maximum of 2 numbers 

int max(int x , int y) { return (x > y) ? x : y; }

// Finding the longest palindromic subsequence from a string
int LongestPalindrome (std::string sequence, int start , int end)
{
	// If string is empty the end is negative
	if (end < 0) return 0;

	// If only one character 
	if (start == end) return 1;

	// If 2 characters check if they are equal and return 2 if so
	else if (sequence[start] == sequence[end] && start + 1 == end) return 2;
	
	// First and last elements match 
	else if (sequence[start] == sequence[end]) { return LongestPalindrome(sequence , start + 1 , end - 1) + 2; }
	
	// Find the max of this character being added to the result and it not being added to the result
	return max(LongestPalindrome(sequence , start , end - 1) , LongestPalindrome(sequence , start + 1 , end));	
}

int main()
{	
	// Testing 
	std::string string = "";
	std::cout << LongestPalindrome(string, 0, string.length() - 1) << std::endl;

	string = "1";
	std::cout << LongestPalindrome(string, 0 , string.length() - 1) << std::endl;
	
	string = "eeeeerreeeee";
	std::cout << LongestPalindrome(string, 0, string.length() - 1) << std::endl;
	
	string = "elelle";
	std::cout << LongestPalindrome(string, 0, string.length() - 1) << std::endl;
	
	string = "HELLOTHERE";
	std::cout << LongestPalindrome(string , 0 , string.length() - 1) << std::endl;

	return 0;
}
