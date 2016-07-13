/**
 * Created by lgt on 16/7/12.
 */
public class Ex_5 {
  int i;
  double d;
  boolean b;
  public void show() {
    System.out.print("int:" + i);
    System.out.print(" double:" + d);
    System.out.print(" boolean:" + b);
  }

  public static void main(String[] args) {
    Ex_5 ex = new Ex_5();
    ex.i = 11;
    ex.d = 123.456;
    ex.b = false;
    // int:11 double:123.456 boolean:false
    ex.show();
  }
}
