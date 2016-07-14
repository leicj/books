public class Ex_6 {
  public void bark(String s, int i) {
    System.out.println("string:" + s + ";int:" + i);
  }
  public void bark(int i, String s) {
    System.out.println("int:" + i + ";string:" + s);
  }
  public static void main(String[] args) {
    Ex_6 ex = new Ex_6();
    ex.bark("hello", 123);
    ex.bark(123, "hello");
  }
}
