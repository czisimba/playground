public class Main{
    public static void main(String[] args) {
        System.out.println(Main.class);
        Main m = new Main();
        Class mainClass = m.getClass();
        System.out.println(mainClass);
        System.out.println(Main.class==mainClass);
    }
}

