/**
 * Created by lgt on 16/7/13.
 */
class StaticTest {
  static int i = 47;
}
public class Ex_7 {
  static void increment() {
    StaticTest.i++;
  }
  public static void main(String[] args) {
    Ex_7.increment();
    Ex_7.increment();
    Ex_7.increment();
    // 50
    System.out.println(StaticTest.i);
  }
}
