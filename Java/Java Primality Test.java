import java.io.*;
import java.math.*;
import java.util.*;

public class Solution {



    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {

        BigInteger n = scanner.nextBigInteger();

        System.out.println(n.isProbablePrime(10) ? "prime" : "not prime");

        scanner.close();
    }
}
