#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__

#include "/git/algorithm/my_version/mylib/generic.h"
#include "iostream"

namespace alg{

    template <typename T>
    static int  __partition__(T list[], int begin, int end)
        {
            int i , j;
            int pivot = RAMDOM(begin , end);
            T value = list[pivot];
            swap(list[pivot], list[begin]);

            i = begin + 1;
            j = end;
            std::cout<<"begin is " << begin << "pivot is" << pivot<< "end is "<<end <<std::endl;
            while( i  <= j) {
                while (i <= end && list[i] <= value) // at least one == to avoid infinite loop
                    i++;

                while(j >=begin && list[j] > value)
                    j--;
                
                if (j >  i)
                swap(list[i], list[j]);
            } 

            swap(list[begin],list[j]);
            std::cout<<"retunr"<<j<<std::endl;
            return j;

        }

    template <typename T>
        void  quicksort(T list[], int begin , int end)
        {
            if (begin < end) {
                int pivot_idx = __partition__(list, begin, end);
                quicksort(list , begin , pivot_idx - 1);
                quicksort(list ,  pivot_idx + 1, end);
            }
        }

}
#endif
