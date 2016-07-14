/*
1. 在定义时初始化, 是在编译器间完成的.
2. 通过构造器初始化, 则为运行期间完成的.
*/

public class Ex_2 {
  private String s1 = "hello";
  private String s2;
  Ex_2(String str) {
    s2 = str;
  }
  public void show() {
    System.out.println(s1);
    System.out.println(s2);
  }
  public static void main(String[] args) {
    Ex_2 ex = new Ex_2("world");
    ex.show();
  }
}
