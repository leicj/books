// simple1/Vector.java
package simple1;
public class Vector {
  public Vector() {
    System.out.println("simple1 constructor!");
  }
}

// simple2/Vector.java
package simple2;
public class Vector {
  public Vector() {
    System.out.println("simple2 constructor!");
  }
}

// Test.java
import simple1.*;
import simple2.*;
public class Test {
  public static void  main(String[] args) {
//    Vector v = new Vector(); //ERROR
    simple1.Vector v1 = new simple1.Vector();
    simple2.Vector v2 = new simple2.Vector();
  }
}
