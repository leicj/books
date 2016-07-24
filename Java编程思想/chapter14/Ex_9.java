import java.lang.reflect.Field;
import java.lang.reflect.Modifier;

class A {
  float f;
  String s = "hello";
  static String ss = "world";
}
public class Test {
  public static void printSuperClass(Class c) {
    Field[] fields = c.getDeclaredFields();
    for (Field f: fields) {
      Class type = f.getType();
      String name = f.getName();
      String modifiers = Modifier.toString(f.getModifiers());
      if (modifiers.length() > 0) {
        System.out.print(modifiers + " ");
      }
      System.out.println(type.getName() + " " + name + ";");
    }
  }
  public static void main(String[] args) {
    A a = new A();
    printSuperClass(a.getClass());
  }
}
