#ifndef __LYP_GENERIC__
#define __LYP_GENERIC__

#include <cstdlib>
#define RAMDOM(L, R) (L + (rand()%(R - L + 1)))

namespace alg  {
    

    template <typename T>
     void  swap(T &a, T &b)
        {
            T temp;
            temp = a;
            a = b ;
            b = temp;
        }

}

#endif
