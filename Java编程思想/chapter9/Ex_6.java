import java.lang.reflect.*;

interface A {
  void fun1();
  void fun2();
}
class B implements A{
  public void fun1() {
    System.out.println("fun1");
  }
  public void fun2() {
    System.out.println("fun2");
  }
}
public class C {
  public static void main(String[] args) {
    try {
      // output:
      // public abstract void fun2()
      // public abstract void fun1()
      Class c1 = Class.forName("A");
      Method[] methods = c1.getDeclaredMethods();
      for (Method m: methods) {
        Class retType = m.getReturnType();
        String name = m.getName();
        String modifiers = Modifier.toString(m.getModifiers());
        if (modifiers.length() > 0)
          System.out.print(modifiers + " ");
        System.out.print(retType.getName() + " " + name + "(");
        Class[] paramTypes = m.getParameterTypes();
        for (int j = 0; j < paramTypes.length; j++) {
          if (j > 0) System.out.print(",");
          System.out.print(paramTypes[j].getName());
        }
        System.out.println(")");
      }
    } catch (ClassNotFoundException e) {
      e.printStackTrace();
    }
  }
}
