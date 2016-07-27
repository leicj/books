class Candy {
  static {
    System.out.println("Loading Candy");
  }
}
class Gum {
  static {
    System.out.println("Loading Gum");
  }
}
class Cookie {
  static {
    System.out.println("Loading Cookie");
  }
}
public class SweetShop {
  public static void main(String[] args) {
    for (int i = 0; i < args.length; i++) {
      try {
        Class.forName(args[i]);
      } catch (ClassNotFoundException e) {
        e.printStackTrace();
      }
    }
  }
}
