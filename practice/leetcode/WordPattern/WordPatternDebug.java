import java.util.*;


class Solution {
    public boolean wordPattern(String pattern, String str) {
        String[] words = str.split(" ");
        if (words.length != pattern.length())
            return false;
        Map patMap = new HashMap();
        Map strMap = new HashMap();
        for (int i = 0 ; i < words.length;i++) {
            if(!patMap.containsKey(pattern.charAt(i))) {
                patMap.put(pattern.charAt(i),i);
            }
            
            if(!strMap.containsKey(words[i])) {
                strMap.put(words[i],i);
            }

            if (!patMap.get(pattern.charAt(i)).equals(strMap.get(words[i])))
                return false;
        }
         return true;
    }
    public boolean wordPattern2(String pattern, String str) {
        String[] words = str.split(" ");
        if (words.length != pattern.length())
            return false;
        Map patMap = new HashMap();
        Map strMap = new HashMap();
        for (int i = 0 ; i < words.length;i++) {

            if (!Objects.equals(patMap.put(pattern.charAt(i),i),strMap.put(words[i],i)))
                return false;
        }
        return true;

    }
}
public class WordPatternDebug {
    public static void main(String args[]) {
            String pat1 = "abba";
            String pat2 = "aaaa";
            String str1 = "dog cat cat dog";
            String str2 = "dog cat cat fish";
            String str3 = "dog cat cat dog";
            String str4 = "dog dog dog dog";

            Solution so = new Solution();

            if (so.wordPattern(pat1, str1) == true) {
                System.out.println("pattern match");
                } else {
                System.out.println("pattern not match");
                    }

        }
    }
