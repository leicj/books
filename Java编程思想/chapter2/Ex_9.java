/**
 * Created by lgt on 16/7/13.
 */
public class Ex_9 {
  public static void main(String[] args) {
    boolean b = false;
    char c = 'c';
    byte t = 1;
    short s = 12;
    int i = 23;
    long l = 65;
    float f = 12.3435f;
    double d = 0.234;
    // true
    System.out.println(new Boolean(b).equals(b));
    System.out.println(new Character(c).equals(c));
    System.out.println(new Byte(t).equals(t));
    System.out.println(new Short(s).equals(s));
    System.out.println(new Integer(i).equals(i));
    System.out.println(new Long(l).equals(l));
    System.out.println(new Float(f).equals(f));
    System.out.println(new Double(d).equals(d));
  }
}
