/*Problem Statement

A carry is a digit that is transferred to left if sum of digits exceeds 9 while adding two numbers from right-to-left one digit at a time

You are required to implement the following function.

Int NumberOfCarries(int num1 , int num2);

The functions accepts two numbers ‘num1’ and ‘num2’ as its arguments. 
You are required to calculate and return  the total number of carries generated while adding digits of two numbers ‘num1’ and ‘ num2’.

Assumption: num1, num2>=0

Example:

Input
Num 1: 451
Num 2: 349
Output
2
Explanation:

Adding ‘num 1’ and ‘num 2’ right-to-left results in 2 carries since ( 1+9) is 10. 
1 is carried and (5+4=1) is 10, again 1 is carried. Hence 2 is returned.*/
#include <iostream>
using namespace std;

int numberOfCarries(int num1, int num2) {
    int carry = 0, count = 0;
    
    while (num1 != 0 || num2 != 0) {
        int p = num1 % 10;
        int q = num2 % 10;
        int sum = carry + p + q;
        
        if (sum > 9) {
            carry = 1;
            count++;
        } else {
            carry = 0;
        }
        
        num1 = num1 / 10;
        num2 = num2 / 10;
    }
    
    // If there's still a carry left after the loop
    if (carry > 0) {
        count++;
    }

    return count;
}

int main() {
    int x, y;
    cin >> x >> y;
    int a = numberOfCarries(x, y);
    cout << a;
    return 0;
}
