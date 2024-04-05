#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    char items[10];
};
int isEmpty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *s)
{
    if (s->top == (s->size - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void printStack(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("The stack is empty!\n");
    }
    else

        for (int i = 0; i <= s->top; i++)
        {
            printf("Element %c\n", s->items[i]);
        }
}
void push(struct stack *s, char data)
{
    if (isFull(s))
    {
        printf("The stack is full.Cannot perform given operation\n");
    }
    else
    {
        s->top++;
        s->items[s->top] = data;
    }
}
char pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("The stack is empty.Cannot perform given operation.\n");
    }
    else
    {
        return s->items[s->top--];
    }
}
int main()
{
    struct stack s1;
    s1.size = 100;
    s1.top = -1;
    char input[100];
    printf("Enter the input string: ");
    gets(input);
    char output[100];
    int i = 0;
    while (input[i] != '\0')
    {
        push(&s1, input[i]);
        i++;
    }
    i = 0;
    while (!isEmpty(&s1))
    {
        output[i] = pop(&s1);
        i++;
    }
    output[i] = '\0';
    puts(output);
    return 0;
}
