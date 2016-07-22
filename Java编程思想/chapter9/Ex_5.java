// package1/A.java
package package1;

public interface A {
  void fun1();
  void fun2();
  void fun3();
}

// package2/B.java
package package2;
import package1.*;

public class B implements A {
  public void fun1() {
    System.out.println("fun1");
  }
  public void fun2() {
    System.out.println("fun2");
  }
  public void fun3() {
    System.out.println("fun3");
  }
  public static void func(A a) {
    a.fun1();
    a.fun2();
    a.fun3();
  }
  public static void main(String[] args) {
    B b = new B();
    func(b);
  }
}
