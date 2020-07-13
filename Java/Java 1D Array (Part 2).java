import java.util.*;

public class Solution {

    public static boolean DFS(int i, int leap, int[] game, boolean[] vis)
    {
        if (i >= game.length) return true;
        if (i < 0 || game[i] == 1 ) return false;
        if( vis[i]) return false;

        vis[i] = true;

        return DFS(i+1,leap,game,vis) || DFS(i-1,leap,game,vis) || DFS(i+leap, leap,game,vis);

    }

    public static boolean canWin(int leap, int[] game) {
        // Return true if you can win the game; otherwise, return false.
        int n = game.length;
        boolean[] vis = new boolean[n];
        return DFS(0,leap,game,vis);
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int q = scan.nextInt();
        while (q-- > 0) {
            int n = scan.nextInt();
            int leap = scan.nextInt();
            
            int[] game = new int[n];
            for (int i = 0; i < n; i++) {
                game[i] = scan.nextInt();
            }

            System.out.println( (canWin(leap, game)) ? "YES" : "NO" );
        }
        scan.close();
    }
}
