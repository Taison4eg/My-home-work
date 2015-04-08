#include <iostream>

using namespace std;

int* mass ;

void sum(int  pribligenie, int maxSlog , int iteration){
  //Вывод на экран если приближение равно ноль
   if (pribligenie==0){
    for(int i=0 ; i<iteration-1 ; i++)
        cout << mass[i] << "+" ;
    cout << mass[iteration-1] << endl ;
    return ;
  }
  /* рекурсивный цикл ,  
     значение iteration нарастает с каждым заходом в новый цикл
     значение приближения отдаеьт в функцию новое значение числа, которое
     необходимо разложить
  */
  for ( int k = min( pribligenie , maxSlog) ; k>=1 ; --k){
      mass[iteration]= k;
      sum(pribligenie - k , k , iteration+1 );
  }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int light;
    cout << "Введите число для разложения в ряд!" << endl;
    cin >> light ;
    mass = new int[light];
    cout << "Первым числом является само значение: "<< endl ;
    sum( light , light , 0);
    return 0;
}
