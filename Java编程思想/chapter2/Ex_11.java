/**
 * Created by lgt on 16/7/13.
 */
public class Ex_11 {
  int anIntegerRepresentingColors;
  void changeTheHueOfTheColor(int newHue) {
    anIntegerRepresentingColors = newHue;
  }
  int getTheHueOfTheColor() {
    return anIntegerRepresentingColors;
  }
  public static void main(String[] args) {
    Ex_11 ex = new Ex_11();
    ex.changeTheHueOfTheColor(111);
    // 111
    System.out.println(ex.getTheHueOfTheColor());
  }
}
