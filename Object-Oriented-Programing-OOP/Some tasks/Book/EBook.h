#ifndef EBOOK_H
#define EBOOK_H


class EBook: public Book
{
    public:
        EBook();
        ~EBook();
    protected:
    private:
        int sizze;
        int opens;
};

#endif // EBOOK_H
