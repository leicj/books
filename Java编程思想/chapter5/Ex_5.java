public class Ex_5 {
  public void bark(char c) {
    System.out.println("barking1:" + c);
  }
  public void bark(int i) {
    System.out.println("barking2:" + i);
  }
  public void bark(float f) {
    System.out.println("howling1:" + f);
  }
  public void bark(double d) {
    System.out.println("howling2:" + d);
  }
  public static void main(String[] args) {
    Ex_5 ex = new Ex_5();
    ex.bark('c');
    ex.bark(1);
    ex.bark(1.23f);
    ex.bark(12.345);
  }
}
