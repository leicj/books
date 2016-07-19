class A {
  A() {
    System.out.println("A constructor!");
  }
}
class B {
  B() {
    System.out.println("B constructor!");
  }
}
public class C extends A{
  B b = new B();
  public static void main(String[] args) {
    C c = new C();
  }
}
