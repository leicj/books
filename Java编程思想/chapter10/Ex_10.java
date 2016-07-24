interface A {
  String toString();
}
public class C {
  public String show(boolean b) {
    if (b) {
      class B implements A {
        public String toString() {
          return getClass().getName();
        }
      }
      A a = new B();
      return a.toString();
    } else {
      return "error";
    }
  }
  public static void main(String[] args) {
    C c = new C();
    System.out.println(c.show(true));
    System.out.println(c.show(false));
  }
}
