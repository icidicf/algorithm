#include <iostream>
#include <cstdlib>
#include <ctime>
#include "quicksort.h"

using namespace std;

int main(void)
{
    int array[15]  ;
    srand(time(NULL));
    for (int i = 0 ; i < 15; i ++)
        array[i] = rand()%100;

    using namespace alg;
    quicksort<int>(array, 0 , 14);


    for (int k = 0 ; k < 15; k++)
       cout<<"i is " <<array[k]<<endl;
    return 0;
}
