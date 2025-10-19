#include <stdio.h>
#include <ctype.h>
int stack[20];
int top = (-1);
void push(int x) {
    stack[++top] = x;
}
int pop() {
    return stack[top--];
}
void main() {
    char str[20];
    int n1, n2, n3, num, i = 0;
    printf("Enter the expression: ");
    scanf("%s", str);
    while(str[i]!='\0') {
        if(isdigit(str[i])) {
            num = str[i] - 48;
            push(num);
        }
        else {
            n1 = pop();
            n2 = pop();
            switch(str[i]) {
                case '+': n3 = n1 + n2; break;
                case '-': n3 = n2 - n1; break;
                case '*': n3 = n1 * n2; break;
                case '/': n3 = n2 / n1; break;
            }
            push(n3);
        }
        i++;
    }
    printf("The result of the expression %s = %d\n", str, pop());
}
