// util.Print.java
package util;
public class Print {
  public void show() {
    System.out.println("hello world");
  }
}

// Test.java
import util.Print;
public class Test {
  public static void  main(String[] args) {
    Print p = new Print();
    // hello world
    p.show();
  }
}

