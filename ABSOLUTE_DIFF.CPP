/*Implement the following Function 

def differenceofSum(n. m)

The function accepts two integers n, m as arguments Find the sum of all numbers in range from 1 to m(both inclusive) that are not divisible by n. Return difference between sum of integers not divisible by n with sum of numbers divisible by n.

Assumption:

n>0 and m>0
Sum lies between integral range
Example

Input
n:4
m:20
Output
90

Explanation

Sum of numbers divisible by 4 are 4 + 8 + 12 + 16 + 20 = 60
Sum of numbers not divisible by 4 are 1 +2 + 3 + 5 + 6 + 7 + 9 + 10 + 11 + 13 + 14 + 15 + 17 + 18 + 19 = 150
Difference 150 – 60 = 90 */


#include<bits/stdc++.h>
using namespace std;
int findCount (int n, int arr[], int num, int diff)
{
  int count = 0;
  for (int i = 0; i < n; ++i)
    {
      if (abs (arr[i] - num) <= diff)
	{
	  count++;
	}
    }
  return count > 0 ? count : -1;
}
int main ()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; ++i)
    {
      cin >> arr[i];
    }
  int num;
  cin >> num;
  int diff;
  cin >> diff;
  cout << findCount (n, arr, num, diff);
}
