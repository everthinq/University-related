#include <iostream.h>
#include <string.h>
//--------------------------------------------------------------
//--------------------------------------------------------------
class employee
{
  public:
     employee(char *, char *, float);
     void show_employee(void);
  private:
     char name [ 64 ];
     char position[64];
     float salary;
};
//--------------------------------------------------------------
employee::employee(char *name, char *position, float salary)
{
       strcpy(employee::name, name);
       strcpy(employee::position, position);
       employee::salary = salary;
}
//--------------------------------------------------------------
void employee::show_employee(void)
{
       cout << "Имя: " << name << endl;
       cout << "Должность: " << position << endl;
       cout << "Оклад: $" << salary << endl;
}
//--------------------------------------------------------------
//--------------------------------------------------------------
class manager : public employee
{
  public:
     manager(char*,char *, char *, float, float, int);
     void show_manager(void);
  private:
     float annual_bonus;
     char company_car[64];
     int stock_options;
};
//--------------------------------------------------------------
manager::manager
        (char *name, char *position, char *company_car, float salary, float bonus,
         int stock_options) : employee(name, position, salary)
{
       strcpy(manager::company_car, company_car);
       manager::annual_bonus = bonus ;
       manager::stock_options = stock_options;
}
//--------------------------------------------------------------
void manager::show_manager(void)
{
   show_employee();
   cout<<"Машина фирмы: "<<company_car<<endl;
   cout<<"Ежегодная премия: $"<<annual_bonus<<endl;
   cout<<"Фондовый опцион: "<<stock_options<<endl;
}
//--------------------------------------------------------------
void main(void)
{
    cout<<endl;

    employee worker("Джон Дой", "Программист", 35000);
    manager boss("Джейн Дой", "Вице-президент ", "Lexus", 50000.0, 5000, 1000);

    worker.show_employee();

    cout<<endl;

    boss.show_manager();

    cout<<endl;
    system("pause");
}

 
