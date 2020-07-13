import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();

        BitSet[] b = new BitSet[]{new BitSet(n), new BitSet(n)};

        for(int i = 0 ; i < m; i++)
        {
            String op = in.next();
            int p = in.nextInt();
            int q = in.nextInt();

            if(op.equals("AND"))
            {
                b[p-1].and(b[q-1]); 
            }
            else if(op.equals("OR"))
            {
                b[p-1].or(b[q-1]); 
            }
            else if(op.equals("XOR"))
            {
                b[p-1].xor(b[q-1]); 
            }
            else if(op.equals("FLIP"))
            {
                b[p-1].flip(q); 
            }
            else if(op.equals("SET"))
            {
                b[p-1].set(q); 
            }

            System.out.println(b[0].cardinality() + " " + b[1].cardinality());

        }
        
    }
}