#include <iostream.h>
class Person
{
    public:
        int age;
        Person(int age) {this->age=age;}
        Person(Person const& copy){
        this->age=copy.age+1;}
};
int main()
{
    Person timmy(10);
    Person sally(15);
    Person timmy_clone = timmy;
    cout << timmy.age << " " << sally.age << " " << timmy_clone.age << endl;
    timmy.age = 23;
    cout << timmy.age << " " << sally.age << " " << timmy_clone.age << endl;
    timmy = 25;
    cout << timmy.age << " " << sally.age << " " << timmy_clone.age << endl;
    system("PAUSE");
}

