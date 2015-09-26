#include <stdlib.h>
#include "binarytree.h"

static link make_node(unsigned char elem)
{
    link p = malloc(sizeof(node_t));
    p->elem = elem;
    p->l = p->r = NULL; 
    return p;
}

static void free_node(link p)
{
    free(p);
}

link init(unsigned char VLR[], unsigned char LVR[], int n)
{
    link t;
    int k;

    if (n <= 0)  // stop point 
        return NULL ;
    for (k = 0 ; (LVR[k] != VLR[0]) && (k < n); k++)
    {}

    if (k >= n )
        return NULL;

    t = make_node(VLR[0]);
    t->l = init(VLR+1, LVR , k);  /*there k for left tree , and 1 for value , and n - k -1 for right value*/
    t->r = init(VLR + k +1, LVR + k +1, n - k-1);

    return t;
}

void pre_order(link t, void (*visit)(link))
{
    if (!t)
        return ;
    
    visit(t);
    pre_order(t->l, visit);
    pre_order(t->r, visit);
    return;
}

void in_order(link t, void (*visit)(link))
{

    if (!t)
        return ;
    
    in_order(t->l, visit);
    visit(t);
    in_order(t->r, visit);
    return;

}



void post_order(link t, void (*visit)(link))
{

    if (!t)
        return ;
    
    post_order(t->l, visit);
    post_order(t->r, visit);
    visit(t);

    return;
}

int count(link t)
{
    if (!t)
        return 0;
    return 1 + count(t->l) + count(t->r);

}

int depth(link t)
{
    int dl, dr;
    if (!t)
        return 0;

    dl = depth(t->l);
    dr = depth(t->r);
    return 1 + (dl > dr ? dl : dr);
}

void destory(link t)
{
    if (!t)
        return ;

    destory(t->l);
    destory(t->r);
    free(t);
}

