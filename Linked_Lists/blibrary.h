#ifndef blibrary
#define blibrary
struct n{
        int x;
        n * next;
};
typedef n node;
void print(node * r);
void add(node *r, int x);
node * addInOrder(node * ,int );
node * remove(node *r,int x);


#endif
