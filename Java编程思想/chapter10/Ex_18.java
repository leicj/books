interface A {
  String toString();
}
public class C {
  public static class B implements A {
    public String toString() {
      return getClass().getName();
    }
  }
  public static void main(String[] args) {
    A a = new C.B();
    System.out.println(a);
  }
}
