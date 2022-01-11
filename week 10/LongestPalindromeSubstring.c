#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100

void printSubStr(char string[MAX], int low, int high);

int longestPalSubstr(char string[MAX]);

int main()

{
	char string[MAX];

	printf("\nenter the input string: ");

	scanf("%[^\n]%*c", string);

	// Display length of resultant palindrome
	printf("\nLength is: %d", longestPalSubstr(string));

	return 0;

}

void printSubStr(char string[MAX], int low, int high)
{
	for (int i = low; i <= high; ++i)

		printf("%c", string[i]);

}

int longestPalSubstr(char string[MAX])
{
	// Get length of input string

	int n = strlen(string);

	if (n == 0)

	{
		// When string is empty
		return 0;

	}

	// table[i][j] will be true if substring
	// string[i.....j] is palindrome.
	// Else table[i][j] will be false
	bool table[n][n];

	// fill the table with value zero
	memset(table, 0, sizeof(table));

	// All substrings of length 1
	// are palindromes
	int maxLength = 1;

	//	// Set diagonal elements value is true
	for (int i = 0; i < n; ++i)

		table[i][i] = true;

	// check for sub-string of length 2.
	// Compare adjacent character
	int start = 0;

	for (int i = 0; i < n - 1; ++i)
	{
		if (string[i] == string[i + 1])

		{
			// When adjacent elements is similar
			table[i][i + 1] = true;

			// Change resultant length
			start = i;

			maxLength = 2;

		}
	}

	// Check for lengths greater than 2.
	// k is length of substring
	for (int k = 3; k <= n; ++k)
	{
		// Fix the starting index
		for (int i = 0; i < n - k + 1; ++i)
		{
			// Get the ending index of substring from
			// starting index i and length k
			int j = i + k - 1;

			// checking for sub-string from ith index to
			// jth index iff str[i+1] to str[j-1] is a
			// palindrome
			if (table[i + 1][j - 1] && string[i] == string[j])
			{
				table[i][j] = true;

				if (k > maxLength)
				{
					// Update resultant starting location
					start = i;

					// Change resultant length
					maxLength = k;

				}
			}
		}
	}

	// Display resultant palindrome
	printf("Longest palindrome substring is: ");

	printSubStr(string, start, start + maxLength - 1);

	// return length of resultant palindrome
	return maxLength;

}
