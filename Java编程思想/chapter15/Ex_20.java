interface A {
  void func1();
  void func2();
}
class B implements A{
  public void func1() {
    System.out.println("func1");
  }
  public void func2() {
    System.out.println("func2");
  }
  public void func3() {
    System.out.println("func3");
  }
}
class C {
  public <T extends A> void func(T t) {
    t.func1();
    t.func2();
  }
}
public class Test {
  public static void main(String[] args) {
    B b = new B();
    C c = new C();
    c.func(b);
  }
}
