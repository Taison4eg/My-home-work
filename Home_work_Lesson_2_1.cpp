#include <iostream>
#include <cmath>

using namespace std;

// Структура данных, точка
struct Point {
  char name ; // поле для имени точки
  double x ; // поле для хранения координаты х
  double y ; // поле для хранения координаты у
};

// Расчет отрезка
double dist(Point a, Point b) {
  double LL = sqrt(pow((a.x - b.x),2) + pow((a.y - b.y),2));
  return  LL ; // Возвращаем расстояние между точками
}

// Сумма
Point sum(Point A, Point B) {
  Point result;
  result.x = A.x + B.x;
  result.y = A.y + B.y;
  return result;
}

// Разность
Point sub(Point A, Point B) {
  Point result;
  result.x = A.x - B.x;
  result.y = A.y - B.y;
  return result;
}

// Скалярное произведение
double product(Point A, Point B) {
   return A.x * B.x + A.y * B.y;
}
//
Point input_point( char a){
    Point res;
    res.name=a;
    cout << "Введите координату х для точки " << res.name << " : " ;
    cin >> res.x ;
    cout << "Введите координату y для точки " << res.name << " : " ;
    cin >> res.y ;
    return res;
}

int main()
{
    int kol;     // Количество точек 
    Point* mass; // Массив для хранения  точек
    setlocale(LC_ALL, "Russian");
    cout << "Программа для работы с точками!" << endl;
    do {
        cout << "Какое количество точек вы хотите ввести (не менее 2!)? " << endl;
        cin>>kol;
       } while(kol<2);
    mass=new Point[kol];
    // Создание точек
    for(int i =0 ; i<kol ; i++){
       mass[i]= input_point((char)(97+i));
    }
    
    double l; // Переменная для хранения временных результатов
    // Далее высчитываем значения по всем точкам в цикле
    for(int j=0 ; j<kol-1 ; j++)
    {
        l=dist(mass[j],mass[j-1]) ;
    }
    cout << "Cуммарное расстояние между точками " << l << endl;
    Point r; // Переменная для хранения временных результатов
    
    for(int j=0 ; j<kol-1 ; j++)
    {
        r = sum(mass[j] , mass[j-1]);
    }
    cout << "Суммой всех точек является точка " << r.x << ";" << r.y << endl; // результирующая точка
    
    for(int j=0 ; j<kol-1 ; j++)
    {
        r = sub(mass[j] , mass[j-1]);
    }
    
    cout << "Разность всех точек " << r.x << ";" << r.y  << endl;  // результирующая точка
    
    for(int j=0 ; j<kol-1 ; j++)
    {
        l = product(mass[j] ,mass[j-1]);
    }
    
    cout << "Произведение всех точек " << l << endl;
    return 0;
}
