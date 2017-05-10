#include <iostream.h>

 class employee 
 { 
 public: 
    employee (char *, long, float);// Прототипы перегруженных 
    employee(char *, long);          //функций 
    void show_employee(void); 
    //int change_salary(float);
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

employee::employee(char *name, long employee_id)
 {
    strcpy(employee::name, name); 
    employee::employee_id = employee_id; 
    do 
    { 
       cout << "Введите оклад для  " << name << " меньше $50000: "; 
       cin >> employee::salary; 
    }
    while (salary >= 50000.0||salary<=0);
 }

 long employee::get_id()
  {
     return employee_id;
  }
 void main ()
 {
   system("chcp 1251");
   long id=12321;
   
   employee first("Alfred Uilson",id,12300);
   employee second("John Brown", id+1);

   cout<<first.get_id()<<" "<<second.get_id();

   printf("\n");
   system("pause");
 }
