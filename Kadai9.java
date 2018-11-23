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
