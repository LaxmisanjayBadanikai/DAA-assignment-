import java.util.*;

public class GCD {
    public static void main(String[] args) {
        System.out.println("Enter two numbers: ");

        Scanner sc = new Scanner(System.in);
       
        int a = sc.nextInt();
        int b = sc.nextInt();
        
        ArrayList<Integer> f1 = new ArrayList<>();
        ArrayList<Integer> f2 = new ArrayList<>();

        for(int i=2;i<=a;i++){
            while(a%i==0){
                f1.add(i);
                a/=i;
            }
        }

        for(int i=2;i<=b;i++){
            while(b%i==0){
                f2.add(i);
                b/=i;
            }
        }

        int gcd = 1;

        for(int i=0;i<f1.size();i++){
            for(int j=0;j<f2.size();j++){
                if(f1.get(i).equals(f2.get(j))){
                    gcd *= f1.get(i);
                    f2.remove(j);
                    break;
                }
            }
        }

        System.out.println("GCD = " + gcd);
    }
}
