import java.io.FileNotFoundException;
import java.io.File;
import java.util.PrintWriter;

// PYTHON GRAPH CENTRALITY MEASURES
  
public class KaprekarsConstant{

  private static int[] lengths = {1,2,3,4,5};
  private static int[] bases = {2,3,4,5,6,7,8,9,10};
  
  public static void main(String[]args){
    for(int length:lengths) for(int base:bases) genKaprekarGraphFile(base,length);
  }

  private static void genKaprekarGraphFile(int base, int length){
    
    File file = new File(System.getProperty("user.dir")+String.format("kaprekar_B%d_L%d",base,length));
    PrintWriter pw = new PrintWriter(file);
    int max = Math.pow(base,length);
    
    for(int n=0; n<max; n++){ // iter: each inital vertex
      int[] digits = new int[length]; // base power is determined by index in array, pow(base,index)
      
      pw.printf("%d %d",n,m);
    }
    
  }

}
