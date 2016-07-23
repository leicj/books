// p1/A.java
package p1;

public interface A {
  void show();
}

// p2/B.java
package p2;
import p1.A;

public class B {
  protected class C implements A {
    public C() {}
    public void show() {
      System.out.println("B-->A-->C.show");
    }
  }
  public static void main(String[] args) {
    B b = new B();
    A a = b.new C();
    a.show();
  }
}

// p3/D.java
package p3;
import p1.A;
import p2.B;

public class D extends B{
  public A c() {
    return D.this.new C();
  }
  public static void main(String[] args) {
    D d = new D();
    d.c().show();
  }
}
