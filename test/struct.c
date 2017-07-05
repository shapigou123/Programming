#include <stdio.h>

#define offsetof(TYPE, MEMBER)  ((size_t) &((TYPE *)0)->MEMBER)

typedef struct SELF_RESF3_TAG{
	int a;
	char c;
	struct SELF_RESF3_TAG *p;
}SELF_RESF3;

int main()
{
	int off = offsetof(SELF_RESF3, p);
	printf("%d\n",off);
	return 0;
}