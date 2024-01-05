#include <criterion/criterion.h>
#include "../inc/stack.h"

Test(stack_test, create)
{
    stack *s = stack_create(sizeof(int)); 
    cr_expect(s != NULL, "");
    cr_expect(s->nelems == 0, "");
    cr_expect(s->top == NULL, "");
    cr_expect(s->width == sizeof(int), "");
}
