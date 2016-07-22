class Cycle {
  public void ride() {
    System.out.println("Cycle ride");
  }
}
class Unicycle extends Cycle {
  public void ride() {
    System.out.println("Unicycle ride");
  }
}
class Bicycle extends Cycle {
  public void ride() {
    System.out.println("Bicycle ride");
  }
}
class Tricycle extends Cycle {
  public void ride() {
    System.out.println("Tricycle ride");
  }
}
public class CycleTest {
  public static void func(Cycle c) {
    c.ride();
  }
  public static void main(String[] args) {
    Unicycle u = new Unicycle();
    Bicycle b = new Bicycle();
    Tricycle t = new Tricycle();
    func(u);
    func(b);
    func(t);
  }
}
