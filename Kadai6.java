// 以下の命令を受け付ける双方向連結リストを実装しなさい。

// insertFirst x 先頭に要素の継ぎ足し
// insertLast x 末尾に要素の継ぎ足し
// delete x キーxを持つ最初の要素を削除
// deleteFirst 先頭の要素を削除
// deleteLast 末尾の要素を削除
// deleteAll 全要素の削除

// 入力: 最初の行に命令数n、続くn行においてそれぞれ命令。
// 出力: 全ての命令が修了した後の連結リスト内のキーの空白区切りによる連続した出力および改行。

import java.util.*;

public class Kadai6{
    public static void main(String[] args) {
        List<String> list = new ArrayList<>();

        Scanner scan = new Scanner(System.in);
        String c = scan.next();
        int count = Integer.parseInt(c);

        for (int i=0; i<count ; i++) {
            String str = scan.next();

            int insertFirst = str.indexOf("insertFirst");
            int insertLast = str.indexOf("insertLast");
            int delete = str.indexOf("delete");
            int deleteFirst = str.indexOf("deleteFirst");
            int deleteLast = str.indexOf("deleteLast");
            int deleteAll = str.indexOf("deleteAll");

            if (insertFirst != -1) {
                String str2 = scan.next();
                Collections.reverse(list);
                list.add(str2);
                Collections.reverse(list);//反転させて挿入して反転

            } else if (insertLast != -1) {
                String str2 = scan.next();
                list.add(str2);

            } else if (delete != -1) {
                String str2 = scan.next();
                int str3 = Integer.parseInt(str2);
                list.remove(str3);

            } else if (deleteFirst != -1) {
                list.remove(0);

            } else if (deleteLast != -1) {
                int length = list.size();
                list.remove(length-1);

            } else if (deleteAll != -1) {
                int length = list.size();
                for (int j=length-1; j>=0; j--) {
                    list.remove(j);
                }

            } else {
                String str2 = scan.next();
                int index = list.indexOf(str2);
                list.remove(str2);
            }
        }

        for (int k=0; k< list.size(); k++) {
            if (k == list.size()-1) {
                System.out.println(list.get(k));
            } else {
                System.out.print(list.get(k) + " ");
            }
        }
    }
}
