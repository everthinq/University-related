#include "second.h"

void Second::s_example()
{
  const char arr[] = "1234567890";

  // Создадим вектор с 11-ю '\0'
  vector <char> vec(sizeof arr);

  // Скопируем 11 элементов типа 'char' в вектор
  memcpy(&vec[0], arr, sizeof arr);

  // Напечатает "1234567890"
  printf("%s", &vec[0]);
}
