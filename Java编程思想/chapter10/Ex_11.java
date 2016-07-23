public interface A {
  String toString();
}
public class C {
  public A show() {
    private class B implements A {
      public String toString() {
        return getClass().getName();
      }
    }
    // 私有的class是无法进行实例化的
    return new B();
  }
  public static void main(String[] args) {
    C c = new C();
    System.out.println(c.show());
  }
}
