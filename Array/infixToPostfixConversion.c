#include <stdio.h>
#include <string.h>
char st[50];
int top=0;
void push(char x) {
   top=top+1;
   st[top]=x;
}
char pop() {
    char item;
    if(top==-1) {
        printf("The stack is empty!\n");
    }
    else {
        item=st[top];
        top--;
    }
    return item;
}
int priority(char x) {
    if(x=='^') {
        return(5);
    }
    else if(x=='*' || x=='/') {
        return(4);
    } 
    else if(x=='+' || x=='-') {
        return(3);
    }
    else {
        return(2);
    }
}
void to_postfix(char q[]) {
    int i=0, j=0, n;
    char ch, temp, p[50];
    n=strlen(q);
    q[n] = ')';
    q[n+1] = '\0';
    st[0] = '(';
    while(i<n) {
        ch=q[i];
        switch(ch) {
            case '(': push(ch);
                      break;
            case ')': temp=pop();
                      while(temp!='(') {
                        p[j] = temp;
                        j++;
                        temp=pop();
                    }
                    break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^': while(priority(st[top])>=priority(ch)) {
                        temp=pop();
                        p[j]=temp;
                        j++;
                    }
                    push(ch);
                    break;
            default: p[j++] = ch;
        }
        i++;
    }
    while(top>0) {
        temp=pop();
        p[j++]=temp;
    }
    p[j++]='\0';
    printf("The postfix form is: %s\n", p);
    pop();
}
void main() {
    char q[50];
    printf("Enter the infix form: ");
    scanf("%s", q);
    to_postfix(q);
}
