#include <iostream>
using namespace std;

const int maxlength = 4;
typedef int elementtype;
typedef int position;

class Kolejka
{
protected:
    elementtype Queue[maxlength]{};
    position Front; // Indeks elementu czołowego
    position Rear; // Indeks ostatniego elementu
public:
    Kolejka() = default;;
    ~Kolejka() = default;;
    int AddOne(int i);
    void Init();
    void Enqueue(elementtype x);
    void Dequeue();
    elementtype FrontElem();
    void Makenull();
    bool Empty();
};

int Kolejka::AddOne(int i) { //zwieksza o 1 zgodnie z relacja modulo
    return ((i + 1) % maxlength);
}

void Kolejka::Init() { //tworzy obiekt i iniciuje zmienne front i rear tak zeby kolejka byla pusta
    Front = 0;
    Rear = maxlength - 1;
}

void Kolejka::Enqueue(elementtype x) {
    if (AddOne(AddOne(Rear)) != Front) // sprawdza czy jest miejsce w kolejce, jak tak to wstawia element do kolejki (na koniec)
    {
        Rear = AddOne(Rear);
        Queue[Rear] = x;
    }
}

void Kolejka::Dequeue() { //sprawdzamy czy kolejka nie jest pusta, jesli nie to modyfikujemy front element
    if (!Empty())
    {
        Front = AddOne(Front);
    }
}

elementtype Kolejka::FrontElem() { //zwraca pierwszy element z kolejki
    if (!Empty())
        return Queue[Front];
    return -1;
}

void Kolejka::Makenull() { //"oproznia" kolejke
    Front = 0;
    Rear = maxlength - 1;
}

bool Kolejka::Empty() { // sprawdzamy czy kolejka jest pusta
    return AddOne(Rear) == Front;
}

int main() {
    Kolejka kolejka;

    kolejka.Init();
    cout << "Empty: ";
    if (kolejka.Empty() == 1) { cout<< "tak" << endl; } else cout << "nie" << endl;
    kolejka.Enqueue(5);
    cout << "Empty: ";
    if (kolejka.Empty() == 1) { cout<< "tak" << endl; } else cout << "nie" << endl;
    cout << kolejka.FrontElem() << endl;
    kolejka.Dequeue();
    cout << "Empty: ";
    if (kolejka.Empty() == 1) { cout<< "tak" << endl; } else cout << "nie" << endl;
    kolejka.Enqueue(4);
    kolejka.Enqueue(3);
    kolejka.Enqueue(2);
    cout << kolejka.FrontElem() << endl;
    kolejka.Enqueue(1);
    cout << kolejka.FrontElem() << endl;
    kolejka.Dequeue();
    cout << kolejka.FrontElem() << endl;
    kolejka.Enqueue(6);
    cout << kolejka.FrontElem() << endl;;
    kolejka.Dequeue();
    kolejka.Dequeue();
    cout << kolejka.FrontElem() << endl;
    kolejka.Makenull();
    cout << "Empty: ";
    if (kolejka.Empty() == 1) { cout<< "tak" << endl; } else cout << "nie" << endl;

    return 0;
}