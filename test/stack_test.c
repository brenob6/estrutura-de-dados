#include <criterion/criterion.h>
#include <criterion/internal/test.h>
#include "../inc/stack.h"

stack *s = NULL;

void setup()
{
    s = stack_create(sizeof(int));
}

void clean()
{
    free(s);
}

TestSuite(stack_test, .init=setup, .fini=clean);

Test(stack_test, create)
{
    cr_expect(s != NULL, "");
    cr_expect(s->nelems == 0, "");
    cr_expect(s->top == NULL, "");
    cr_expect(s->width == sizeof(int), "");
}
