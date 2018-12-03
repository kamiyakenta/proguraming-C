// 以下の命令を実行する簡易的な入れ物を実装しなさい。
// add str : 文字列 strを登録
// remove str: 文字列 strが登録済みの場合は登録削除
// find str : 文字列 strが登録済みの場合は yes 、さもなくば no と出力

// 入力: 最初の行に命令の数 nが与えられる。続くn行にn件の命令。
// 出力: 各find命令の実行結果として yes または no を1行に出力して改行。

import java.util.*;

public class Kadai9 {

    public static void main(String[] args) {
        List<String> list = new ArrayList<>();

        Scanner scan = new Scanner(System.in);
        String num = scan.next();
        int count = Integer.parseInt(num);

        for (int i = 0; i < count; i++) {
            String command = scan.next();
            String word = scan.next();

            switch (command) {
                case "add":
                    list.add(word);
                    break;
                case "remove":
                    if (list.contains(word)) {
                        int number = list.indexOf(word);
                        list.remove(number);
                    }
                    break;
                case "find":
                     if (list.contains(word)) {
                        System.out.println("yes");
                    } else {
                        System.out.println("no");
                    }
                    break;
                default:
            }
        }
    }
}
