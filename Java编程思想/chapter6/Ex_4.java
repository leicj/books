// access/A.java
package access;
public class A {
  protected void show() {
    System.out.println("A:show()");
  }
}

// access/B.java
package access;
public class B extends A {
  public void show() {
    super.show();
  }
}


// Test.java
import access.A;
import access.B;
public class Test {
  public static void  main(String[] args) {
    A a = new A();
    B b = new B();
//    a.show(); //ERROR
    b.show();
  }
}
