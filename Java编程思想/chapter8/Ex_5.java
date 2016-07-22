class Cycle {
  public void ride() {
    System.out.println("Cycle ride");
  }
  public int wheels() {
    return 0;
  }
}
class Unicycle extends Cycle {
  public void ride() {
    System.out.println("Unicycle wheels:" + wheels());
  }
  @Override
  public int wheels() {
    return 1;
  }
}
class Bicycle extends Cycle {
  public void ride() {
    System.out.println("Bicycle wheels:" + wheels());
  }
  @Override
  public int wheels() {
    return 2;
  }
}
class Tricycle extends Cycle {
  public void ride() {
    System.out.println("Tricycle wheels:" + wheels());
  }
  @Override
  public int wheels() {
    return 4;
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
