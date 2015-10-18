#include<iostream>
#include<string.h>
using namespace std;
     static void kmp_table(const char *W, int * T, int len);
     /**
     * S -> the text to be searched
     * W -> the word to search
     * return the position where W is found S
     */
     static int kmp_search(const char * S, const char * W) {
          int LEN_S = strlen(S);
          int LEN_W = strlen(W);

          int m = 0;
          int i = 0;
          int T[LEN_W];

          kmp_table(W,T, LEN_W);

          for (int k;k< LEN_W;k++) {
              std::cout<<" "<<T[k];
              }
          while (m+i < LEN_S) {
               if (W[i] == S[m+i]) {
                    if (i == LEN_W -1) {
                         return m;
                    }
                    i++;
               } else {
                    m = m+i-T[i];    // m 是新的锚点，此时已经在新的比较队列的T[j]格上
                    if (T[i] > -1) {
                         i = T[i];
                    } else {
                         i = 0;
                    }
               }
          }
          return -1;
     }

     /**
     * build a table for the word to be searched 
     * eg:
     * i          0      1      2      3      4      5      6
     * W[i]      A      B      C      D      A      B      D
     * T[i]      -1      0      0      0      0      1      2
     */
     static void kmp_table(const char *W, int * T, int len) {
          int pos = 2; // the current position we are computing in T
          int cnd = 0; // the next character of the current candidate substring
          T[0] = -1;
          T[1] = 0;

          while (pos < len) {
               // first case: the substring continues
               if (W[pos-1] == W[cnd]) {
                    cnd++;
                    cout<<"stage 1 pos " << pos << " cnd " <<cnd<<endl;
                    T[pos] = cnd;
                    pos++;
               } else if (cnd >0) { // second case: it doesn't, but we can fall back
                 cout<<"stage 2 pos is "<< pos <<" cnd is " << cnd <<" T[cnd] "<<T[cnd]<<" len is "<<len<<endl;
                    cnd = T[cnd];
               } else { // third case: we have run out of candidates.  Note cnd = 0
                    cout<<"stage 3 pos " << pos<< "set this to 0"<<endl;
                    T[pos] = 0;
                    pos++;
               }
          }
     }
    int main(void) {
        char inp[]="BBC ABCDAB ABCDABCDABDE";
        char tar[]="ABABCABAB";
        //char tar[]="ABCDABD";
        int v = kmp_search(inp,tar);
        std::cout<<"v is "<<v<<std::endl;
        return 0;
    }
