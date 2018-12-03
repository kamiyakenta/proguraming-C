#include <stdio.h>
#include <string.h>

char A[10][6] = {
  {'0'},
  {'.', ',', '!', '?', ' '},
  {'a', 'b', 'c'},
  {'d', 'e', 'f'},
  {'g', 'h', 'i'},
  {'j', 'k', 'l'},
  {'m', 'n', 'o'},
  {'p', 'q', 'r', 's'},
  {'t', 'u', 'v'},
  {'w', 'x', 'y', 'z'}
};


int main(void) {
  int i, c;
  int n;
  char input[80];
  int index;
  char pre_c = 'a';

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%s", input);
    index = 0;

    for (c = 0; c < strlen(input); c++) {

      if (input[c] == pre_c) {
        index++;
      } else if (input[c] == '0') {
        printf("%c", A[pre_c - '0'][index % strlen(A[pre_c - '0'])]);
        index = 0;
        pre_c = '0';
      } else {
        pre_c = input[c];
      }
    }
    printf("\n");
  }

  return 0;
}
