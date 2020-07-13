import java.util.*;
class Solution{
	
	public static void main(String []argh)
	{
		Scanner sc = new Scanner(System.in);
		
		while (sc.hasNext()) {
			String input=sc.next();
            Map<Character,Character> mp = new HashMap();
            mp.put(')','(');
            mp.put(']','[');
            mp.put('}','{');

            Stack<Character> st = new Stack();

            boolean ans = true;

            for(int i = 0; i < input.length(); i++)
            {
                char ch = input.charAt(i);
                if(mp.containsKey(ch))
                {
                    if(st.empty() || st.peek() != mp.get(ch))
                    {
                        ans = false;
                        break;
                    }
                    else
                        st.pop();
                }
                else
                {
                    st.push(ch);
                }
            }

            if(!st.empty()) ans = false;
            System.out.println(ans);

		}
		
	}
}



