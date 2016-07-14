class Book {
  protected void finalize() {
    System.out.println("book: finalize");
  }
}
public class Ex_10 {
//  protected void finalize() {
//    System.out.println("finalize");
//  }
  public static void main(String[] args) {
    new Ex_10();
    new Book();
    System.gc();
  }
}
