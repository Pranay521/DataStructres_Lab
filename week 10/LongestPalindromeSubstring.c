#include <stdio.h>
#include <string.h>
#define MAX 100

void longestPalSubstr(char str[MAX])
{
	int startIndex, endIndex = 1;
	int n = strlen(str);
	int dp[n][n];
	int i, j, len;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			dp[i][j] = 0;

	for (i = 0; i < n; i++)
		dp[i][i] = 1;	//string with one char is palindrome

	for (i = 0; i < n - 1; i++)
	{
		if (str[i] == str[i + 1])	// string with length 2
		{
			dp[i][i + 1] = 1;
			startIndex = i;
			endIndex = 2;
		}
	}

	for (len = 3; len <= n; len++)
	{

		for (i = 0; i <= n - len ; i++)
		{
			j = i + len - 1;

			if (dp[i + 1][j - 1] == 1 && str[i] == str[j])
			{
				dp[i][j] = 1;
				if (len > endIndex)
				{
					startIndex = i;
					endIndex = len;
				}
			}
		}
	}

	printf("Longest palindrome substring is: ");
	for (i = startIndex; i <= startIndex + endIndex - 1; i++)
		printf("%c", str[i]);
	printf("\nLength is: %d", endIndex);

}

int main()
{

	char str[MAX];
	printf("\nenter the input string::");
	scanf("%[^\n]%*c", str);
	longestPalSubstr(str);
	return 0;

}
