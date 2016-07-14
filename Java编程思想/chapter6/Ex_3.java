// debug/Print.java
package debug;
public class Print {
  public static void debug(String str) {
    System.out.println(str);
  }
}

// debugoff/Print.java
package debugoff;
public class Print {
  public static void debug() {

  }
}

// Test.java
import static debug.Print.*;
import static debugoff.Print.*;
public class Test {
  public static void  main(String[] args) {
    debug("hello");
    debug();
  }
}
