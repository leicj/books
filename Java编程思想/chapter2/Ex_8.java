/**
 * Created by lgt on 16/7/13.
 */
public class Ex_8 {
  static int i = 47;
  public void increment() {
    i++;
  }
  public static void main(String[] args) {
    Ex_8 ex1 = new Ex_8();
    Ex_8 ex2 = new Ex_8();
    Ex_8 ex3 = new Ex_8();

    ex1.increment();
    ex2.increment();
    ex3.increment();
    // ex1:50; ex2:50; ex3:50
    System.out.println("ex1:" + ex1.i + "; ex2:" + ex2.i + "; ex3:" + ex3.i);
  }
}
