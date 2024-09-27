#include <stdio.h>

int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

int main() {
  int n;

  printf("Enter a non-negative integer: ");
  scanf("%d", &n);

  if (n < 0) {
    printf("Error! Factorial of a negative number doesn't exist.\n");
  } else {
    printf("Factorial of %d = %d\n", n, factorial(n));
  }

  return 0;
}