class Implementation;

class Interface
{
    public:
    Interface(int);
    ~Interface();
    void setValue(int);
    int getValue() const;

    private:
    Implementation *ptr;
};