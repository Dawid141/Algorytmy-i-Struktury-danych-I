#include <iostream>
using namespace std;

const int maxlegth = 20;
typedef int elementtype;
typedef int position;

class Stos
{
    int S[maxlegth];
    position Top;

public:
    Stos();
    void Push(elementtype x);
    void Pop();
    bool Empty();
    elementtype TopElem();
    void Makenul();
};

Stos::Stos()
{
    Top = -1;
}

void Stos::Makenul()
{
    Top = -1;
}

void Stos::Push(elementtype x)
{
    if (Top < maxlegth - 1)
    {
        S[Top + 1] = x;
        Top++;
    }
}

void Stos::Pop()
{
    if (Top >= 0)
    {
        Top--;
    }
}

bool Stos::Empty()
{
    return Top == -1;
}

elementtype Stos::TopElem()
{
    if (!Empty())
    {
        return S[Top];
    }
    else {
        return -1;
    }
}



int main() {
    Stos stos;

    cout << stos.Empty() << endl;
    stos.Push(5);
    cout << stos.TopElem() << endl;
    cout << stos.Empty() << endl;
    stos.Pop();
    cout << stos.Empty() << endl;
    stos.Push(2);
    stos.Push(3);
    cout << stos.TopElem() << endl;
    stos.Makenul();
    cout << stos.Empty() << endl;;

    return 0;
}