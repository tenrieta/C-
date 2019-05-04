#ifndef QUEUE_H
#define QUEUE_H


class Queue
{
    public:
        Queue();
        ~Queue();
        void enqueue(int elem);
        int dequeue();
        void resizze();
        void print();
        void setSize(int s);
        int getSizze()const;
        int countElem();
    protected:
    private:
        int head;
        int tail;
        int* arr;
        int sizze;
        bool flag;
};

#endif // QUEUE_H
