class A {
  public String toString() {
    return (this.getClass().getName());
  }
}
public class Test {
  private A a;
  public String toString() {
    if (a == null) {
      a = new A();
    }
    return a.toString();
  }

  public static void main(String[] args) {
    Test t = new Test();
    // A
    System.out.println(t);
  }
}
