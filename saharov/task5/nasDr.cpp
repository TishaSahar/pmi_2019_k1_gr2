#include "class.hpp"

Drob1::Drob1()//����������� ��-���������
{
    ch = 0;
    zn = 1;
}

Drob1::Drob1(int a, int b)//����������� ��-��������
{
    if (b == 0)
    {
        std::cout << "���� � �����������";
        return;
    }
    ch = a;
    zn = b;
}

void Drob1::reduct1(Drob1 &d)
{
    int n = nod(d.ch, d.zn);
    d.ch = d.ch / n;
    d.zn = d.zn / n;
}

Drob1 Drob1::operator +(const Drob1 &a)//��������
{
    ch = zn*a.ch + ch*a.zn;
    zn = zn * a.zn;
    reduct1(*this);
    return *this;
}

Drob1 Drob1::operator -(const Drob1 &a)//���������
{
    Drob1 c;
    c.ch = ch*a.zn - zn*a.ch;
    c.zn = zn*a.zn;
    reduct1(c);
    return c;
}

Drob1 Drob1::operator *(const Drob1 &a)//���������
{
    Drob1 c;
    c.ch = ch*a.ch;
    c.zn = zn*a.zn;
    reduct1(c);
    return c;
}

Drob1 Drob1::operator /(const Drob1 &a)//�������
{
    Drob1 c;
    c.ch = ch * a.zn;
    c.zn = zn * a.ch;
    reduct1(c);
    return c;
}

void Drob1::Print()
{
    std::cout << ch << '/' << zn << std::endl;
}


Drob1 Drob1::operator ++(int)
{
    Drob1 a = *this;
    ++*this;
    reduct1(*this);
    return a;
}

Drob1 &Drob1::operator ++()
{
    ch += zn;
    reduct1(*this);
    return *this;
}
