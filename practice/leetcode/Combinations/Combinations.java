import java.util.*;


class Solution {
    public void  helpCombine(List <List<Integer>> result, List<Integer> li , int n, int k , int currentLevel) {
        int init;
        if (currentLevel == k + 1) {
            result.add(new ArrayList<Integer>(li));
            System.out.println(li);
            return;
        }
        if (li.size() == 0)
             init = currentLevel;
        else 
            init = li.get(li.size()-1) + 1;

        for (int i = init; i <= n ; i++) {
                li.add(i);
                helpCombine(result, li, n,k, currentLevel + 1);
                li.remove(li.size() - 1);
        }
    }
    public List<List<Integer>> combine(int n , int k) {
        List <List<Integer>> result = new LinkedList <List<Integer>>() ;
        List<Integer> li = new ArrayList<Integer>();

        helpCombine(result,li,n,k,1);

        return result;
    }
}
public class Combinations {
    public static void main(String args[]) {
        Solution so = new Solution();
        so.combine(4,3);
        }
    }
