import java.util.Scanner;
public class B004 {
    public static void main(String[] args) {
        Scanner in =new Scanner(System.in);
        String fruit = in.next();
        switch (fruit) {
            case "Mango" -> System.out.println("King of fruits");
            case "Apple" -> System.out.println("Red fruit");
            case "Orange" -> System.out.println("Orange");
            case "Grape" -> System.out.println("Many in One");
            default -> {
                System.out.println("Please !! Enter a valid Fruit");
                throw new AssertionError();
            }
        }
    }
}
