public class Outer {
  private String s;
  Outer(String s) {
    this.s = s;
  }
  class Inner {
    public String toString() {
      return s;
    }
  }
  public Inner inner() {
    return new Inner();
  }
  public static void main(String[] args) {
    Outer o = new Outer("???");
    Outer.Inner i = o.inner();
    System.out.println(i);
  }
}
