#ifndef STACK_H
#define STACK_H


class Stack
{
    public:
        Stack();
        ~Stack();
        void push(int elem);
        int pop();
        void setSize(int s);
        void print();
        void resizze();
    protected:
    private:
        int top;
        int* arr;
        int sizze;
};

#endif
