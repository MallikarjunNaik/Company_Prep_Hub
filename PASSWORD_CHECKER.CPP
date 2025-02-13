/*You are given a function.
int CheckPassword(char str[], int n);
The function accepts string str of size n as an argument. Implement the function which returns 1 if given string str is valid password else 0.
str is a valid password if it satisfies the below conditions.

– At least 4 characters
– At least one numeric digit
– At Least one Capital Letter
– Must not have space or slash (/)
– Starting character must not be a number
Assumption:
Input string will not be empty.

Example:

Input 1:
aA1_67
Input 2:
a987 abC012

Output 1:
1
Output 2:
0
*/

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
