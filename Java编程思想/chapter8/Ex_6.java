class Instrument {
  public void play() {
    System.out.println("Instrucment.play");
  }
  public String toString() {
    return "Instrument.";
  }
}

class Wind extends Instrument {
  public void play() {
    System.out.println("wind.play");
  }
  public String toString() {
    return "Wind.";
  }
}

class Percussion extends Instrument {
  public void play() {
    System.out.println("Percussion.play");
  }
  public String toString() {
    return "Percussion.";
  }
}

class Stringed extends Instrument {
  public void play() {
    System.out.println("Stringed.play");
  }
  public String toString() {
    return "Stringed.";
  }
}

class Brass extends Wind {
  public void play() {
    System.out.println("Brass.play");
  }
  public String toString() {
    return "Brass.";
  }
}

class Woodwind extends Wind {
  public void play() {
    System.out.println("Woodwind.play");
  }
  public String toString() {
    return "Woodwind.";
  }
}
public class Music3 {
  public static void tune(Instrument i) {
    i.play();
  }
  public static void tuneAll(Instrument[] e) {
    for (Instrument i: e) {
      tune(i);
    }
  }
  public static void main(String[] args) {
    Instrument[] orchestra = {
        new Wind(),
        new Percussion(),
        new Stringed(),
        new Brass(),
        new Woodwind()
    };
    tuneAll(orchestra);
    for (Instrument i: orchestra) {
      System.out.println(i);
    }
  }
}
