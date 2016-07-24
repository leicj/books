interface A{}
interface B{}
interface M{}
class C {
  C() {}
  C(int i) {}
}
class D extends C implements A, B, M {
  D() { super(1); }

}
public class Test {
  public static void printInfo(Class c) {
    System.out.println("Class name: " + c.getName() + " is interface? [" + c.isInterface() + "]");
    System.out.println("Simple name:" + c.getSimpleName());
    System.out.println("Canonical name:" + c.getCanonicalName());
  }
  public static void main(String[] args) {
    Class c = null;
    try {
      c = Class.forName("D");
    } catch (ClassNotFoundException e) {
      e.printStackTrace();
    }
    printInfo(c);

    for (Class face: c.getInterfaces()) {
      printInfo(face);
    }

    Class up = c.getSuperclass();
    Object obj = null;
    try {
      obj = up.newInstance();
    } catch (InstantiationException e) {
      e.printStackTrace();
    } catch (IllegalAccessException e) {
      e.printStackTrace();
    }
    printInfo(obj.getClass());
  }
}
