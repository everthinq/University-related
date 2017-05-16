#ifndef EX2
#define EX2

class I
{
   public:
      virtual void f() = 0;
      virtual void g() = 0;
};


class A : public I
{
   public:
      void f() { std::cout << "A: method f() executed. // f()" << std::endl; }
      void g() { std::cout << "A: method g() executed. // g()" << std::endl; }
};


class B : public I
{
   public:
      void f() { std::cout << "B: method f() executed. // f()" << std::endl; }
      void g() { std::cout << "B: method g() executed. // g())" << std::endl; }
};


class C : public I
{
   public:
      C() : m_i ( new A() ) { }     // Конструктор
      virtual ~C() { delete m_i; }  // Деструктор

      void f() { m_i->f(); }
      void g() { m_i->g(); }

  // Этими методами меняем поле-объект, чьи методы будем делегировать/*
      void toA()
      {
         delete m_i;
         m_i = new A();
      }

      void toB()
      {
         delete m_i;
         m_i = new B();
      }
  // Этими методами меняем поле-объект, чьи методы будем делегировать*/

   private:
      I * m_i; // Объявляем объект, методы которого будем делегировать
};

#endif // EX2

