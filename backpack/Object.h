#ifndef OBJECT_H
#define OBJECT_H

class Object
{
private:
    int weigth;
    int value;
public:
    Object () {}
    Object (int weigth, int value)
    {
        this->weigth = weigth;
        this->value = value;
    }
    ~Object() {}
    int getWeigth()
    {
        return weigth;
    }
    void setWeigth(int weigth)
    {
        this->weigth = weigth;
    }
    int getValue()
    {
        return value;
    }
    void setValue(int value)
    {
        this->value = value;
    }
};

#endif // OBJECT_H
