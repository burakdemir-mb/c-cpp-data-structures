#ifndef stack_arr
#define stack_arr
struct s {
	int size;
	int top;
	int * array;
};
typedef s stack;
stack * definition();
int pop(stack *);
void push(int,stack *);
void print(stack*);
#endif
