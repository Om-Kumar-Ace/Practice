#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isPalindromeRecursive(const char* str, int start, int end) {

  if (start >= end) {
    return 1;
  }
  if (tolower(str[start]) != tolower(str[end])) {
    return 0;
  }

  return isPalindromeRecursive(str, start + 1, end - 1);
}

int main() {
  char str[100];
  printf("Enter a string: ");
  fgets(str, sizeof(str), stdin);
  str[strcspn(str, "\n")] = '\0';

  int length = strlen(str);
  if (length == 0) {
    printf("The string is a palindrome.\n");
    return 0;
  }

  if (isPalindromeRecursive(str, 0, length - 1)) {
    printf("The string is a palindrome.\n");
  } else {
    printf("The string is not a palindrome.\n");
  }

  return 0;
}
