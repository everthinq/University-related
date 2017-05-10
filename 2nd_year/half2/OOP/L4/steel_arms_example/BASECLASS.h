//---------------------------------------------------------------------------

#ifndef BASECLASSH
#define BASECLASSH
#include <iostream.h>
//---------------------------------------------------------------------------
class BASESTEEL
{
         public:
                BASESTEEL();
                BASESTEEL(short, long, int, std::string);

                virtual ~BASESTEEL();

                virtual short GetLevel() = 0;
                virtual void Move(int To) = 0;
                virtual void SLICEandDICE() = 0;
             //   virtual void block() = 0;


                short _level;
                long _status;
                int _x;

                std::string _type;

};
#endif

