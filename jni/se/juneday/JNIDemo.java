package se.juneday;

public class JNIDemo {

  public static void main(String[] args){

    FromCWithLove c = new FromCWithLove();

    String msg = c.getSome("Krega");

    System.out.println("In Java again: " + msg);
    
  }
  
}
