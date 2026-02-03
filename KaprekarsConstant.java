import java.io.FileNotFoundException;
import java.io.File;

public class KaprekarsConstant{

  private static String directory = "";
  private static int[] lengths = {1,2,3,4,5,6,7};
  private static int[] bases = {10};
  
  public static void main(String[]args){
    for(int length:lengths) for(int base:bases) genKaprekarGraphFile(base,length);
  }

  private static void genKaprekarGraphFile(int base, int length){
    File file = new File(System.getProperty("user.dir")+directory);
  }

}
