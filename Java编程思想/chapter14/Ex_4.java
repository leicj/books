import java.util.*;

abstract class Shape {
  void draw() { System.out.println(this + ".draw()"); }
  abstract public String toString();
}

class Rhomboid extends Shape {
  public String toString() { return "Rhomboid"; }
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
  public static void main(String[] args) {
    List<Shape> l = Arrays.asList(new Circle(), new Square(), new Triangle());
    for (Shape shape: l) {
      shape.draw();
    }

    Shape s = new Rhomboid();
    if (s instanceof Rhomboid) {
      s.draw();
    }
    if (s instanceof Circle) {
      s.draw();
    }
  }
}
