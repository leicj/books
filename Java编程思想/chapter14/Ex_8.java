class A { }
class B extends A{}
class C extends B {}

public class Test {
  public static void printSuperClass(Class c, String seq) {
    System.out.println(seq + c.getName());
    Class superC = c.getSuperclass();
    if (superC != null) {
      printSuperClass(superC, "-->");
    }
  }
  public static void main(String[] args) {
    C c = new C();
    printSuperClass(c.getClass(), "");
  }
}
