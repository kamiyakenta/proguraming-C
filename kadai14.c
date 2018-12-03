// スマホからのメッセージ送信を考える。スマホの各数字ボタンには次の文字が割り当てられており、ボタン0を押すと確定する。ただし何もボタンが押されていない場合に確定すると文字は何ら出力されない。

// ボタン1: . , ! ? (スペース)
// ボタン2: a b c
// ボタン3: d e f
// ボタン4: g h i
// ボタン5: j k l
// ボタン6: m n o
// ボタン7: p q r s
// ボタン8: t u v
// ボタン9: w x y z
// ボタン0: 確定


#include <stdio.h>
#include <string.h>

char btn[10][6] = {
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
  int i, w;
  int n;
  char input[1000];
  int index;
  char pre_w = ' '; //とりあえず何か入れておく

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%s", input);
    index = 0;

    for (w = 0; w < strlen(input); w++) {

      if (input[w] == pre_w) {
        index++;
      } else if (input[w] == '0') {
        printf("%c", btn[pre_w - '0'][index % strlen(btn[pre_w - '0'])]);
        index = 0;
        pre_w = '0';
      } else {
        pre_w = input[w];
      }
    }
    printf("\n");
  }

  return 0;
}
