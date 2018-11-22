#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


#define N 200

int stack[N];
int sp = 0;

int pop() {
  return stack[--sp];
}

void push(int a) {
  stack[sp++] =a;
}

int empty() {
  return sp;
}

int main() {
  char str[N];
  int a, b;
  while(scanf("%s", str) != EOF) {
    if(isdigit(str[0])) {
      push(atoi(str));
    } else {
      b = pop();
      a = pop();
      printf("%d ", a);
      printf("%d\n", b);
      switch(str[0]) {
      case '+':
        push(a+b);
        break;
      case '-':
        push(a-b);
        break;
      case '*':
        push(a*b);
        break;
      case '=':
        break;
      }
    }
  }
  printf("%d\n", pop());
  return 0;
}
