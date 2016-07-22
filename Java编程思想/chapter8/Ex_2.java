import java.util.Random;

class Shape {
  public void draw() { }
}

class Circle extends Shape {
  @Override
  public void draw() {
    System.out.println("Circle draw");
  }
}

class Square extends Shape {
  @Override
  public void draw() {
    System.out.println("Square draw");
  }
}

class RandomShapeGenerator {
  private Random rand = new Random(47);
  public Shape next() {
    switch (rand.nextInt(2)) {
      default:
      case 0: return new Circle();
      case 1: return new Square();
    }
  }
}
public class Shapes {
  private static RandomShapeGenerator gen = new RandomShapeGenerator();
  public static void main(String[] args) {
    Shape[] s = new Shape[5];
    for (int i = 0; i < s.length; i++) {
      s[i] = gen.next();
    }
    for (Shape shp: s) {
      shp.draw();
    }
  }
}
