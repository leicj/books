import java.util.*;

public class IterableFibonacci implements Iterable<Integer>{
  private int count = 0;
  private int size;

  public IterableFibonacci() {}
  public IterableFibonacci(int size) {
    this.size = size;
  }
  public Integer next() {
    return fib(count++);
  }
  private int fib(int n) {
    if (n < 2) return 1;
    return fib(n - 1) + fib(n - 2);
  }
  public Iterator<Integer> iterator() {
    return new Iterator<Integer>() {
      public boolean hasNext() {
        return size > 0;
      }

      public Integer next() {
        size--;
        return IterableFibonacci.this.next();
      }

      public void remove() {
        throw new UnsupportedOperationException();
      }
    };
  }

  public static void main(String[] args) {
    IterableFibonacci f = new IterableFibonacci();
    for (int i = 0; i < 18; i++) {
      System.out.print(f.next() + " ");
    }
    System.out.println();
    for (int i: new IterableFibonacci(18)) {
      System.out.print(i + " ");
    }
    System.out.println();
  }
}
