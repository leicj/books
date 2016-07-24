import java.util.*;

abstract class Shape {
  void draw() { System.out.println(this + ".draw()"); }
  abstract public String toString();
}

class Circle extends Shape {
  public String toString() { return "Circle"; }
}
class Square extends Shape {
  public String toString() { return "Square"; }
}
class Triangle extends Shape {
  public String toString() { return "Triangle"; }
}
public class Shapes {
  public static void rotate(Shape s) {
    if (s instanceof Circle) {
      return;
    }
    System.out.println(s.getClass().getName());
  }
  public static void main(String[] args) {
    List<Shape> l = Arrays.asList(new Circle(), new Square(), new Triangle());
    for (Shape shape: l) {
      rotate(shape);
    }
  }
}
