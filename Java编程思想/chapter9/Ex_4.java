abstract class A {
  public abstract void show();
}
class B extends A{
  public void show() {
    System.out.println("B show()");
  }
}
public class C {
  public static void func(A a) {
//    ((B)a).show();
    a.show();
  }
  public static void main(String[] args) {
    B b = new B();
    // B show()
    func(b);
  }
}
