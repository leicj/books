public class Test<T> {
  private T o1, o2, o3;
  public void set(T o1, T o2, T o3) {
    this.o1 = o1;
    this.o2 = o2;
    this.o3 = o3;
  }
  public T get_o1() {
    return this.o1;
  }
  public T get_o2() {
    return this.o2;
  }
  public T get_o3() {
    return this.o3;
  }
  public static void main(String[] args) {
    Test<String> t = new Test<>();
    t.set("hello", "world", "java");
    System.out.println(t.get_o1());
    System.out.println(t.get_o2());
    System.out.println(t.get_o3());
  }
}
