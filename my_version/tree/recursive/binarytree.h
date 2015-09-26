#ifndef BINARYTREE_H
#define BINARYTREE_H

/*linux c program tutorail by son jing shang*/
typedef struct node *link;
typedef struct node {
    unsigned char elem;
    link l, r ;
} node_t;

link init(unsigned char VLR[], unsigned char LVR[], int n);
void pre_order(link t, void (*visit)(link));
void in_order(link t, void (*visit)(link));
void post_order(link t , void(*visit)(link));
int count(link t);
int depth(link t);
void destory(link t);

#endif
