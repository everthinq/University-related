#include "third.h"


void Third::t_example()
{
  int arr[4] = {1, 2, 3, 4};

  // Инициализирование вектора с использованием массива
  vector<int> numbers(arr, arr+4);

  // Добавляем числа в вектор
  numbers.push_back(5);
  numbers.push_back(6);
  numbers.push_back(7);
  numbers.push_back(8);
  // Теперь вектор выглядит так: {1, 2, 3, 4, 5, 6, 7, 8}


  // Произвольно перемешиваем элементы
  random_shuffle(numbers.begin(), numbers.end());


  // Получаем максимальный элемент, сложность O(n)
  vector<int>::const_iterator largest = max_element( numbers.begin(), numbers.end() );
  cout << "Max elem is: " << *largest << endl;
  cout << "Index max elem is: " << largest - numbers.begin() << endl;


  // Сортируем элементы, сложность O(n log n)
  sort(numbers.begin(), numbers.end());


  // Находим позицию цифры 5 в векторе, сложность O(log n)
  vector<int>::const_iterator five = lower_bound(numbers.begin(), numbers.end(), 5);
  cout << "Index of value 5 is:  " << five - numbers.begin() << endl;


  // Удаляем все элементы больше 4-х
  numbers.erase(remove_if(numbers.begin(), numbers.end(),
    bind2nd(greater<int>(), 4)), numbers.end() );

  // Печатаем оставшиеся
  for (vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
    cout << *it << ' ';
  }
}
