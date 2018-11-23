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
