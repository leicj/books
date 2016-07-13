/**
 * Created by lgt on 16/7/13.
 */
public class Ex_6 {
  int storage(String s) {
    return s.length() * 2;
  }
  public static void main(String[] args) {
    Ex_6 ex = new Ex_6();
    // 22
    System.out.println(ex.storage("hello world"));
  }
}
