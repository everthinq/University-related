#include <iostream.h>
#include <string.h>

 class employee
 { 
 public: 
    char name[64]; 
    long employee_id; 
    float salary; 
    void show_employee(void);  //  Прототип функции 
 };
 
 void employee:: show_employee (void) //Имя класса 
 { 
    cout << "Name: " << name << endl;// Имя элемента
    cout << "Number_ID: " << employee_id << endl;
    cout << "Salary: " << salary << endl;
    cout<<endl;
 };

 void main(void)
 {
    employee worker, boss;

    strcpy(worker.name, "John Doe");
    worker.employee_id = 12345;
    worker.salary = 25000;

    strcpy(boss.name, "Happy Jamsa");
    boss.employee_id = 101;
    boss.salary = 101101.00;

    worker.show_employee();
    boss.show_employee();

    system("pause");
 }


