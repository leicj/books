class Cleanser {
  private String s = "Cleanser";
  public void append(String a) {s += a;}
  public void dilute() {append(" dilute()");}
  public void apply() {append(" apply()");}
  public void scrub() {append(" scrub()");}
  public String toString() {return s;}
}

class Detergent extends Cleanser {
  public void scrub() {
    append(" Detergent scrub()");
    super.scrub();
  }
  public void foam() {append(" foam()");}
}

public class Test extends Detergent {
  public void scrub() {
    append(" Test scrub()");
    super.scrub();
  }
  public void sterillize() {
    append(" sterillize()");
  }
  public static void main(String[] args) {
    Test t = new Test();
    t.dilute();
    t.apply();
    t.scrub();
    t.foam();
    t.sterillize();
    System.out.println(t);
  }
}