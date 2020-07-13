import java.io.*;
import java.util.*;
import java.security.MessageDigest;
import java.nio.charset.StandardCharsets;
import java.math.BigInteger;

public class Solution {
    private static final Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        String str = scanner.nextLine();
        try
        {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] hash = md.digest(str.getBytes(StandardCharsets.UTF_8));
            BigInteger num = new BigInteger(1, hash);
            StringBuilder hex = new StringBuilder(num.toString(16));

            while(hex.length() < 64)
                hex.insert(0,'0');

            System.out.println(hex.toString());
        }
        catch(Exception ex){
            throw new RuntimeException(ex);
        }
        
    }
}
