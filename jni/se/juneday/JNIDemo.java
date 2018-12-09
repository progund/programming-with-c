package se.juneday;

public class JNIDemo {

  public static void main(String[] args){

    FromCWithLove c = new FromCWithLove();
    
    //    for (int i=0 ; i <10_000_000; i++) {
    //  System.out.print(" * " + i + ": ");
    String msg = c.getSome("Krega");
    System.out.println("In Java again: " + msg);
    //}
  }
  
}
