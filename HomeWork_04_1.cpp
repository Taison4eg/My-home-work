#include <iostream>

using namespace std;

// Базовый класс
struct Shape   // struct -> public:
{
    virtual void show() = 0; // Абстрактный метод, необходимо реализовать в каждом дочернем классе
};

struct Square : public Shape
{
    double side;
    Square () : side(1) {} // конструктор по умолчанию
    Square(double s) : side(s) { }
    void show()
    {
        for (int j=0 ; j<side+2 ; j++)
        {
            for (int i=0 ; i<side+2 ; i++)
            {
                if(j==0 || j==side+1)
                {
                    if(i==0 || i==side+1)
                    {
                        cout << "-" ;
                        cout << " " ;
                    }
                    else
                    {
                        cout << "-" ;
                        cout << " " ;
                    }
                }
                else
                {
                    if(i==0 || i==side+1)
                    {
                        cout << "|" ;
                        cout << " " ;
                    }
                    else
                    {
                        cout << " " ;
                        cout << " " ;
                    }
                }
            }
            cout << endl ;
        }
        cout << "Это квадрат !!! "<< endl ;
    }
};

struct Rectangle : public Shape
{
    double height, width;
    Rectangle(double h, double w) :
        height(h), width(w) { }
    void show()
    {
        int side_a=((int)height) , side_b=((int)width);
        for (int j=0 ; j<side_b+2 ; j++)
        {
            for (int i=0 ; i<side_a+2 ; i++)
            {
                if(j==0 || j==side_b+1)
                {
                    if(i==0 || i==side_a+1)
                    {
                        cout << "-" ;
                        cout << " " ;
                    }
                    else
                    {
                        cout << "-" ;
                        cout << " " ;
                    }
                }
                else
                {
                    if(i==0 || i==side_a+1)
                    {
                        cout << "|" ;
                        cout << " " ;
                    }
                    else
                    {
                        cout << " " ;
                        cout << " " ;
                    }
                }
            }
            cout << endl ;
        }
        cout << "Это прямоугольник!!! "<< endl ;
    }
};

int zapros( int number)
{
    int r ;
    cout << "Какая будет " << number << " фигура?" << endl ;
    cout << "Введите 1 если хотите создать квадрат,"<< "\n"<< "или любую другую для ввода прямоугольника" << endl ;
    cin >> r ;
    return r ;
}

int main()
{
    int N=0 ; // количество фигур
    setlocale(LC_ALL, "Russian");
    cout << "Программа для разных фигур" << endl;
    cout << "Сколько фигур вы хотите ввести?" << endl;
    cin >> N ;
    Shape* s[N];
    for(int i = 0; i < N ; ++i)
    {
        double side_a =1 ,  side_b=1 ;
        if (zapros(i+1)==1)
        {
            cout << "Введите сторону квадрата" << endl;
            cin >> side_a ;
            s[i]=new Square(side_a) ;
        }
        else
        {
            cout << "Введите длинну пряьоуголника" << endl;
            cin >> side_a ;
            cout << "Введите ширину пряьоуголника" << endl;
            cin >> side_b ;
            s[i]=new Rectangle( side_a , side_b);
        }
    }
    for(int i = 0; i < N ; ++i)
        s[i]->show(); // Вызываем у всех метод, который реализован по разному
    return 0;
}
