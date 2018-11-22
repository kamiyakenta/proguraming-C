#include <stdio.h>
#include <ctype.h>

#define N 100

void printstack(int *stack, int index);
int main(void);


void printstack(int *stack, int index) {
  int i;
  for (i = 0; i < index; i++) {
    printf("%d ", stack[i]);
  }
  printf("\n");
}

int main(void) {

  int stack[N];
  int index = 0;
  char c;
  int conti_flag = 0; // 数字が連続しているかどうか
  int i;

  while (1) {
    if ((c = getchar()) == '\n') break;
    //http://www.c-tipsref.com/reference/stdio/getchar.html
    if (isdigit(c)) { //正規表現で数字
      if(conti_flag) { //連続していたら
        stack[index] = stack[index] * 10 + (c - '0');
      } else {
        stack[index] = c - '0';
        conti_flag = 1;  //ここで立てる

      }
    } else if(isspace(c)) {  //空白か確認
      if(conti_flag) {
        index++;
        conti_flag = 0;
        printstack(stack, index);
      }
    } else if (c == '+') {
      if (index > 1) {
        index--;
      }
      stack[index-1] += stack[index];
      stack[index] = 0;
      printstack(stack, index);
    } else if (c == '-') {
      if( index > 1 ) {
        index--;
      }
      stack[index-1] -= stack[index];
      stack[index] = 0;
      printstack(stack, index);
    } else if (c == '*') {
      if( index > 1 ) {
        index--;
      }
      stack[index-1] *= stack[index];
      stack[index] = 0;
      printstack(stack, index);
    } else if (c == '/') {
      if( index > 1 ) {
        index--;
      }
      stack[index-1] /= stack[index];
      stack[index] = 0;
      printstack(stack, index);
    }
  }

  return 0;
}
