public class Outer {
  public String s;
  Outer(String s) {
    this.s = s;
  }
  class Inner {
    public void show() {
      System.out.println(s);
      System.out.println("Inner show");
    }
  }
  public Inner inner() {
    return new Inner();
  }
  public static void main(String[] args) {
    Outer o = new Outer("???");
    Outer.Inner i = o.inner();
    i.show();
    System.out.println(o.s);
    // ERROR
//    Outer.Inner i1 = new Outer.Inner();
  }
}
