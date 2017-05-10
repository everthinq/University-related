#include <iostream.h>
#pragma hdrstop
#pragma argsused
//---------------------------------------------------------------------------
class employee 
 { 
   public:
        employee(char *, long, float); //Конструктор
          ~employee();
          void show_employee(void);
          int change_salary(float);
           long get_id(void);
   private:
         char name [64];
         long employee_id;
          float salary;
 };

employee::employee(char *name, long employee_id, float salary)
 { 
    strcpy(employee::name, name);
    employee::employee_id = employee_id; 

    if (salary < 50000.0) employee::salary = salary;
    else employee::salary = 0.0; // Недопустимый оклад
 }

employee::~employee()
 {
   cout << "Уничтожение объекта для  " << name << endl;
 } 

int main(int argc, char* argv[])
{
 employee worker("Happy Jamsa", 101, 10101.0);
 employee secretary("John Doe", 57, 20000.0); 
 employee manager("Jane Doe", 1022, 30000.0);

        system("pause");
        return 0;
}
//---------------------------------------------------------------------------
