abstract class A {
  A() {
    print();
  }
  public abstract void print();
}
public class B extends A{
  private String s = "hello";
  public void print() {
    System.out.println(s);
  }
  public static void main(String[] args) {
    // null
    B b = new B();
  }
}
