/*Problem Description :
The Binary number system only uses two digits, 0 and 1 and number system can be called binary string. 
You are required to implement the following function:

int OperationsBinaryString(char* str);

The function accepts a string str as its argument. The string str consists of binary digits eparated with an alphabet as follows:

– A denotes AND operation
– B denotes OR operation
– C denotes XOR Operation
You are required to calculate the result of the string str, scanning the string to right taking one opearation at a time, and return the same.

Note:

No order of priorities of operations is required
Length of str is odd
If str is NULL or None (in case of Python), return -1
Input:
str: 1C0C1C1A0B1

Output:
1

Explanation:
The alphabets in str when expanded becomes “1 XOR 0 XOR 1 XOR 1 AND 0 OR 1”, result of the expression becomes 1, hence 1 is returned.*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int CheckPassword(char str[], int n) {
    if (n < 4) return 0; // Condition 1: At least 4 characters

    int hasDigit = 0;
    int hasCapital = 0;

    for (int i = 0; i < n; i++) {
        if (isdigit(str[i])) {
            hasDigit = 1;
        }
        if (isupper(str[i])) {
            hasCapital = 1;
        }
        if (str[i] == ' ' || str[i] == '/') {
            return 0; // Condition 4: Must not have space or slash (/)
        }
    }

    if (!hasDigit || !hasCapital) {
        return 0; // Condition 2: At least one numeric digit and Condition 3: At least one Capital Letter
    }

    if (isdigit(str[0])) {
        return 0; // Condition 5: Starting character must not be a number
    }

    return 1; // All conditions are satisfied
}

int main() {
    char str[100];
    fgets(str, sizeof(str), stdin);
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0'; // Remove the newline character
        len--; // Decrement the length
    }
    int result = CheckPassword(str, len);
    printf("%d\n", result);
    return 0;
}
