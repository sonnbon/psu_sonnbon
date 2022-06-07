

class list   //THIS IS THE place where upcasting takes place!!!!!
{
    public:
        list();
        virtual ~list();
        list(const list & from);
        virtual int display() const;
        virtual int insert(const movie & to_add);
        virtual int remove(const char * title_to_remove);
        virtual bool is_match(const char * match_title) const;
    protected:
        node * head;

};
class LLL: public list
{
    public:
        LLL();
        ~LLL();
        LLL(const LLL & from);
        int display() const;
        int insert(const movie & to_add);
        int remove(const char * title_to_remove);
        bool is_match(const char * match_title) const;
    protected:
        node * tail;
};
class CLL: public list
{
    public:
        CLL();
        ~CLL();
        CLL(const CLL & from);
        int display() const;
        int insert(const movie & to_add);
        int remove(const char * title_to_remove);
        bool is_match(const char * match_title) const;
    protected:
};
