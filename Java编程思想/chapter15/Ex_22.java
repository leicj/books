class A {
  private String s;
  A() {
    this.s = "";
  }
  A(String s) {
    this.s = s;
  }
}
public class Test<T> {
  public T create(Class<T> kind, String s) {
    try {
      return kind.newInstance();
    } catch (Exception e) {
      return null;
    }
  }
  public static void main(String[] args) {
    Test<A> t = new Test();
    A a = t.create(A.class, "hello");
    System.out.println(a.getClass().getName());
  }
}
