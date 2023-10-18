#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

template <typename T>
class Polynomial {
    T *coeff; //wspolczynniki
    int power; //najwyzsza potega
public:

    Polynomial(int _power) : power(_power) {
        coeff = new T[power + 1];
        for (int i = 0; i < power + 1; ++i) {
            coeff[i] = T();
        }
    }

    Polynomial(T *_coeff, int _power) : power(_power) {
        coeff = new T[power + 1];
        for (int i = 0; i < power + 1; ++i) {
            coeff[i] = _coeff[i];
        }
    }

    //desktruktor
    ~Polynomial() {
        power = 0;
        delete[] coeff;
    }

    //operator dodawania
    Polynomial<T> operator+(const Polynomial<T> &other) {
        int n1 = this->power;
        int n2 = other.power;
        int higher = max(n1, n2);
        Polynomial<T> result(higher);

        for (int i = 0; i <= higher; ++i) {
            T coef1;
            T coef2;
            if (i <= n1) {
                coef1 = this->coeff[i];
            } else {
                coef1 = T();
            }
            if (i <= n2) {
                coef2 = other.coeff[i];
            } else {
                coef2 = T();
            }
            result.coeff[i] = coef1 + coef2;
        }
        return result;
    }

    //operator odejmowania
    Polynomial operator-(const Polynomial &other) {
        int n1 = this->power;
        int n2 = other.power;
        int higher = max(n1, n2);
        T coef[higher + 1];
        Polynomial<T> result(coef, higher);

        for (int i = 0; i <= higher; i++) {
            T c1;
            T c2;
            if (i <= n1) {
                c1 = this->coeff[i];
            } else {
                c1 = 0;
            }
            if (i <= n2) {
                c2 = other.coeff[i];
            } else {
                c2 = 0;
            }
            result.coeff[i] = c1 - c2;
        }
        return result;
    }

    //operator mnozenia
    Polynomial operator*(const Polynomial &other) {
        int n1 = this -> power;
        int n2 = other.power;
        int result_n = n1 + n2;

        Polynomial<T> result(result_n);

        for (int i = 0; i < n1 + 1; ++i) {
            for (int j = 0; j < n2 + 1; ++j) {
                result.coeff[i + j] += this -> coeff[i] * other.coeff[j];
            }
        }
        return result;
    }

    //fragment do zwracania wartosci wielomianu
    T horner(T x){
        T result = 0;
        for (int i = power; i >= 0; --i) {
            result = result * x + coeff[i];
        }
        return result;
    }

    //fragment do wypisywania wielomianu na ekran
    void display() {
        bool t = true;
        for (int i = power; i >= 0; --i) {
            if (coeff[i] != 0) {
                if (!t) {
                    if (coeff[i] > 0) {
                        cout << " + ";
                    } else {
                        cout << " - ";
                    }
                }
                t = false;
                cout << abs(coeff[i]);
                if (i > 1) {
                    cout << "x^" << i;
                } else if (i == 1) {
                    cout << "x";
                }
            }
        }
        if (t) {
            cout << 0;
        }
        cout << endl;
    }

};

int main() {
    //tablice z wartosciami jakie chcemy nadac wielomianom (wspolczynniki od najnizszego do najwyzszego)
    int coef1[] = {0, 2, -3,4};
    int coef2[] = {-2, 3, 0, 0,0,2};

    //Tworzenie wielomianow, podajemy tablice z ich wspolczynnikami oraz "power" czyli potege do ktorej beda dochodzic
    Polynomial<int> p1(coef1, 3);
    Polynomial<int> p2(coef2, 5);

    cout << "Dwa przykladowe wielomiany :" << endl;

    cout << "W1(x) = ";
    p1.display();

    cout << "W2(x) = ";
    p2.display();
    cout << endl;

    cout << "Dodawanie wielomianow: " << endl;

    Polynomial<int> p_sum = p1 + p2;
    cout << "W1(x) + W2(x) = ";
    p_sum.display();

    cout << "Odejmowanie wielomianow: " << endl;

    Polynomial<int> p_sub = p1 - p2;
    cout << "W1(x) - W2(x) = ";
    p_sub.display();

    cout << "Mnozenie wielomianow: " << endl;

    Polynomial<int> p_mul = p1 * p2;
    cout << "W1(x) * W2(x) = ";
    p_mul.display();

    cout << endl;

    cout << "Wartosc wielomianu schematem hornera: " << endl;
    cout << "Wartosc wielomianu W1(x) dla x = 7: " << p1.horner(-3) << "\n";
    cout << "Wartosc wielomianu W2(x) dla x = 5: " << p2.horner(-3) << "\n";
}