package se.juneday;

public class FromCWithLove {

  static {
    System.loadLibrary("love");
  }
  
  public native String getSome(String msg);
  
}
