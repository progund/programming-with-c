package se.juneday;

public class Stupid {

  public static String gimmeString() {
    return "Hi there, I am a stupid class!";
  }

  public static int gimmeSum(int a, int b) {
    return a+b;
  }

  public static void main(String[] args) {
    System.out.println(gimmeSum(1234,5678));
    System.out.println(gimmeString());
  }
  
}
