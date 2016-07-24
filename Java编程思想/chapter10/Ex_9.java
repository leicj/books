interface A {
  String toString();
}
public class C {
  public A show() {
    class B implements A {
      public String toString() {
        return getClass().getName();
      }
    }
    return new B();
  }
  public static void main(String[] args) {
    C c = new C();
    System.out.println(c.show());
  }
}
