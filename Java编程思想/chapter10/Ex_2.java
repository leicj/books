interface Selector {
  boolean end();
  Object current();
  void next();
}

class A {
  private String s;
  A(String s) {
    this.s = s;
  }
  public String toString() {
    return s;
  }
}
public class Sequence {
  private A[] items;
  private int next = 0;
  public Sequence(int size) { items = new A[size]; }
  public void add(A x) {
    if (next < items.length)
      items[next++] = x;
  }
  private class SequenceSelector implements Selector {
    private int i = 0;
    public boolean end() { return i == items.length; }
    public Object current() { return items[i]; }
    public void next() { if (i < items.length) i++; }
  }
  public Selector selector() {
    return new SequenceSelector();
  }
  public static void main(String[] args) {
    Sequence sequence = new Sequence(10);
    for (int i = 0; i < 10; i++)
      sequence.add(new A(Integer.toString(i)));
    Selector selector = sequence.selector();
    while (!selector.end()) {
      System.out.print(selector.current() + " ");
      selector.next();
    }
  }
}
