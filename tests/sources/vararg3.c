#include <assert.h>
#include <stdarg.h>

void setv(int num, ...)
{
	va_list l;
	void (*f)(void);

	(void) num;

	/* in this test we have only one var arg */
	va_start(l, num);
	f = va_arg(l, void *);
	f();
	va_end(l);
}

void foo(void)
{
	assert(0 && "OK, reached assert");
}

int main(void)
{
	int a;
	setv(1, foo);
	return 0;
}
