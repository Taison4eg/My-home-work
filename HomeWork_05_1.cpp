#include <iostream>
#include <assert.h>
#define SHOW(x) cout<<#x<<" = " <<x << endl;

using namespace std;

typedef long long ll;

// НОД - Наибольший общий делитель
ll GCD(ll a, ll b)
{
    return (b == 0) ? a : GCD(b, a % b);
}

// Рациональная дробь: p/q
class Rational
{
    ll p, q; // p - числитель, q - знаменатель
    // Сокращение дроби
    void normalize()
    {
        ll d = GCD(p, q); // Вычисляем наибольший общий делитель
        p /= d; // делим на него числитель
        q /= d; // делим на него знаменатель
    }
public:
    Rational(ll pi, ll qi) : p(pi) ,q(qi)
    {
        this->normalize();
    };

    // TODO: Ввод с клавиатуры
    Rational(const char* message)
    {
        cout << message << endl ;
        cin >> this->p ;
        cin >> this->q ;
        this->normalize();
    }

    // TODO: Показать дробь на экран (в консоль)
    void show()
    {
        cout << "МОя дробь " << this->p << "/" << this->q << endl;
    };

    // TODO: Сложение дробей
    // a + b
    Rational operator+(Rational& x)
    {
        // this - указатель на текущий объект
        // *this - текущий объект
        Rational res(0 , 1);
        res.q =(this->q)*(x.q) ;
        res.p =(this->p)*(x.q)+(this->q)*(x.p) ;
        res.normalize();
        return res;
    }

    // TODO: прибавить к дроби целое число
    Rational operator+(int right)
    {
        Rational res(0 , 1);
        res.p =(this->q)*right+this->p ;
        res.q = this->q;
        res.normalize();
        return res;
    }

    // TODO: прибавить к целому число дробь
    friend Rational
    operator+(long left, Rational& right)
    {
        Rational res(0 , 1);
        res.p =(right.q)*left+right.p ;
        res.q = right.q;
        res.normalize();
        return res;
    }

    // TODO: вычитание
    Rational operator-(Rational& x)
    {
        Rational res(0 , 1);
        res.q =(this->q)*(x.q) ;
        res.p =(this->p)*(x.q)-(this->q)*(x.p) ;
        res.normalize();
        return res;
    }


    // Конструктор копирования
    Rational(const Rational& r): p(r.p) , q(r.q) {}

    // cout - типа ostream
    friend ostream& operator << (ostream& os, Rational& r)
    {
        os << r.p << " / " << r.q << " ";
        return os;
    }
    // stream - поток
    // thread - поток/нить
};

int main()
{
    setlocale(LC_ALL , "Russian");
    char* mess = "Введите значение дроби вида 34/45 : " ;
    Rational r(mess);
    Rational a(4, 6), b(11, 2);
    r.show();
    Rational c = b + a;
    c.show();
    b.show();

     int i = 2, j = 3;
     int tt = i + j;
     Rational c1 = i + b;

     b.show();
     c1.show();

     Rational x(4,6), y(1,3);
     x.show();
     Rational yy("Vvedite:");
     yy.show();

    return 0;
}

