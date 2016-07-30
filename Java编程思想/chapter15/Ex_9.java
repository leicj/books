public class GenericMethods {
  public <T, T1, T2> void f(T x, T1 y, T2 z) {
    System.out.println(x.getClass().getName());
    System.out.println(y.getClass().getName());
    System.out.println(z.getClass().getName());
  }
  public static void main(String[] args) {
    GenericMethods gm = new GenericMethods();
    gm.f("", 1, 1.234);
  }
}
