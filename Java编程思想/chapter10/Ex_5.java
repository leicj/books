class B {
  class A {
    void show() {
      System.out.println("B->A.show()");
    }
  }
}
public class C {
  public static void main(String[] args) {
    B b = new B();
    B.A a = b.new A();
    a.show();
  }
}
