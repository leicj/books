/**
 * Created by lgt on 16/7/12.
 */
public class Ex_4 {
  int i;
  double d;
  boolean b;
  Ex_4(int aI, double aD, boolean aB) {
    i = aI;
    d = aD;
    b = aB;
  }
  public void show() {
    System.out.print("int:" + i);
    System.out.print(" double:" + d);
    System.out.print(" boolean:" + b);
  }

  public static void main(String[] args) {
    Ex_4 ex = new Ex_4(11, 123.456, false);
    // int:11 double:123.456 boolean:false
    ex.show();
  }
}
