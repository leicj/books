import java.util.*;

interface Generator<T> {
  T next();
}

class IteratorGenerator<T> implements Generator<T> {
  private Class<T> type;
  public IteratorGenerator(Class<T> type) {
    this.type = type;
  }
  public T next() {
    try {
      return type.newInstance();
    } catch(Exception e) {
      throw new RuntimeException(e);
    }
  }
  public static <T> Generator<T> create(Class<T> type) {
    return new IteratorGenerator<T>(type);
  }
}

class CountedObject {
  private static long counter = 0;
  private final long id = counter++;
  public long id() { return id; }
  public String toString() {
    return "CountedObject " + id;
  }
}
public class Generators {
  public static void main(String[] args) {
//    Generator<CountedObject> gen = IteratorGenerator.create(CountedObject.class);
    Generator<CountedObject> gen = new IteratorGenerator<>(CountedObject.class);
    for (int i = 0; i < 5; i++) {
      System.out.println(gen.next());
    }
  }
}
