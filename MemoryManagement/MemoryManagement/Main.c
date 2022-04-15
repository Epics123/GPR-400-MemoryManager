#include <stdlib.h>

typedef void* ptr_t;

typedef struct mynode_t
{
	unsigned short prevOffset;
	unsigned short nextOffset;
	unsigned short size;
	unsigned short sequence;
}mynode;

char* myinit(char* stack, unsigned short stackSize)
{
	mynode* node = (mynode*)stack;
	node->prevOffset = 0;
	node->nextOffset = 0;
	node->size = stackSize;
	node->sequence = 0;

	return stack;
}

char* myalloc(char* stack, unsigned short size)
{
	// search for empty space large enough
	// offset to node location
	// set node
	// return pointer right after node


}

void myfree(char* block)
{
	// clear node right before block
}

int main(int const argc, char const* argv[]) 
{
	typedef union scanner_t
	{
		void* ptr_t;
		size_t s;
	}scanner;

	typedef union malloc_node_t
	{
		ptr_t prev;
		ptr_t next;
		size_t pad[3];
		size_t size;
		size_t sequence;
		size_t pad1;
	}malloc_node;

	ptr_t a, b, c, d;
	scanner* scan_a, *scan_b, *scan_c, *scan_d;
	malloc_node* node_a, *node_b, *node_c, *node_d;

	a = malloc(1024);
	b = malloc(65535);
	c = malloc(1345);
	d = malloc(1000000);

	if(a) *(int*)a = 72;
	if(b) *(int*)b = 1234567;
	if(c) *(int*)c = -86;
	if(d) *(int*)d = 2000000000;

	scan_a = (scanner*)a;
	scan_b = (scanner*)b;
	scan_c = (scanner*)c;
	scan_d = (scanner*)d;

	node_a = (malloc_node*)a - 1;
	node_b = (malloc_node*)b - 1;
	node_c = (malloc_node*)c - 1;
	node_d = (malloc_node*)d - 1;

	//scan-1 = ???
	//scan-2 = allocaction sequence
	//scan-3 = ***alloc size
	//scan-4 = ??? (always 1?)
	//scan-5 = ??? (always 0?)
	//scan-6 = ??? (always 0?)
	//scan-7 = ***next scan-8 (last one is 0. others are close to each other)
	//scan-8 = ***previous scan-8 (pointers near previous)
	//scan-9 = ???
	//scan-10 = ???
	//scan-11 = ???
	//scan-12 = ???

	free(a);
	free(b);
	free(c);
	free(d);

	//write your own 16-bit memory manager:
	char stack[65536];
	myinit(stack, sizeof(stack));
}