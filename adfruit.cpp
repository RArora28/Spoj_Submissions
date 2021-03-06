#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

long long int dp[102][102];
char str[101];

long long int f(char str1[], long long int i, char str2[], long long int j)
{
  if(i == -1 || j == -1)
    return 0;
  
  else if(dp[i][j] != -1)
    return dp[i][j];
  
  else if(str1[i] == str2[j]) 
    return dp[i][j] = 1 + f(str1,i-1, str2, j-1);
      
  else
    return dp[i][j] = max( f(str1,i, str2, j-1), f(str1,i-1, str2, j));
}

int main()
{
  char str1[101], str2[101];
  long long int len1, len2, i, j, index = 0;
  
  while(1)
    {
      if(!(cin>>str1>>str2))
	break;
      
      len1 = strlen(str1)-1;
      len2 = strlen(str2)-1;

      for(i = 0; i <= len1; i++)
	  for(j = 0; j <= len2; j++)
	    dp[i][j] =  -1;

      long long int temp = f(str1,len1, str2, len2);
      
      i = len1;
      j = len2;
      
      while(i >=0 && j >= 0)
	{
	  if(str1[i] == str2[j])
	    {
	      str[index++] = str1[i--];
      	      j--;
	    }

	  else if(dp[i-1][j] > dp[i][j-1])
	      str[index++] = str1[i--];
	       
	  else
      	      str[index++] = str2[j--];
	 }
      
      while(i >= 0)
	str[index++] = str1[i--];
      
      while(j >= 0)
	str[index++] = str2[j--];

      for(i = index-1; i >= 0; i--)
	printf("%c", str[i]);
       
      printf("\n");
	  
      index = 0;
    }
  
  return 0;
}
