#include <iostream.h>
#include <string.h>
//---------------------------------------------------------------------------
class phone
{
public:
 virtual void dial(char *number) { cout << "Набор номера " << number << endl; }
 void answer(void) { cout << "Ожидание ответа" << endl; }
 void hangup(void) { cout << "Звонок выполнен - повесить трубку" << endl; }
 void ring(void) { cout << "Звонок, звонок, звонок" << endl; }
 phone(char *number) { strcpy(phone::number, number); };
protected:
 char number[13] ;
};
//---------------------------------------------------------------------------
class touch_tone : phone
{
 public:
  void dial(char * number) { cout << "Пик пик Набор номера " << number << endl; }
  touch_tone(char *number) : phone(number) { }
};
//---------------------------------------------------------------------------
class pay_phone: phone
{
 public:
  void dial(char *number) { cout << "Пожалуйста, оплатите " << amount << " центов."
                                 << " Набор номера " << number << endl;
                          }
  pay_phone(char *number, int amount) : phone(number) { pay_phone::amount = amount; }
private:
 int amount;
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void main(void)
{
        system("chcp 1251"); cout<<endl;

        pay_phone city_phone("702-555-1212", 25);
        touch_tone home_phone("555-1212");
        phone rotary("201-555-1212") ;

        // Сделать объект дисковым телефоном
        phone *poly_phone = &rotary;
        poly_phone->dial("818-555-1212");

        // Заменить форму объекта на кнопочный телефон
        poly_phone = (phone *) &home_phone;
        poly_phone->dial("303-555-1212");

        // Заменить форму объекта на платный телефон
        poly_phone = (phone *) &city_phone;
        poly_phone->dial("212-555-1212");

        cout<<endl;
        system("pause");
}

