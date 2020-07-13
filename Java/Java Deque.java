import java.util.*;
public class test {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        ArrayDeque<Integer> deque = new ArrayDeque();
        Map<Integer,Integer> mp = new HashMap();
        int n = in.nextInt();
        int m = in.nextInt();

        int ans = -1 ;

        for (int i = 0; i < n; i++) {
            int num = in.nextInt();
            deque.addLast(num);
            int count = mp.containsKey(num) ? mp.get(num) : 0;
            mp.put(num, count + 1);

            if(i >= m - 1)
            {
                ans = Math.max(ans, mp.size());
                int rem = deque.removeFirst();
                int cnt = mp.get(rem);
                if(cnt == 1)
                    mp.remove(rem);
                else
                    mp.put(rem, cnt - 1);
            }
        }
        System.out.println(ans);
    }
}



