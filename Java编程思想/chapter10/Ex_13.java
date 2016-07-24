interface A {
  String toString();
}
public class C {
  public A show() {
    return new A() {
      public String toString() {
        return getClass().getName();
      }
    };
  }
  public static void main(String[] args) {
    C c = new C();
    System.out.println(c.show());
  }
}
