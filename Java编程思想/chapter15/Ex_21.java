import java.util.*;
class Building {}
class House extends Building {}
public class ClassTypeCapture<T> {
  Map<String, Class<?>> map1;
  public void addType(String typename, Class<?> kind) {
    map1.put(typename, kind);
  }
  public Object createNew(String typename) {
    try {
      return Class.forName(typename).newInstance();
    } catch (Exception e) {
      return "ERROR";
    }
  }
  public String f(Object arg) {
    return arg.getClass().getName();
  }
  public static void main(String[] args) {
    ClassTypeCapture<Building> ctt1 = new ClassTypeCapture();
    Building b = (Building) ctt1.createNew("Building");
    System.out.println(ctt1.f(b));
  }
}
