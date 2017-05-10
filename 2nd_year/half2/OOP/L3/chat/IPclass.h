//---------------------------------------------------------------------------
#ifndef IPclassH
#define IPclassH
//---------------------------------------------------------------------------
#include "interface.h"
//---------------------------------------------------------------------------
class IPAdresses {

        public:
                IPAdresses();
                IPAdresses(TStringList* IPs);
                ~IPAdresses();
                bool Add(String&);
                bool IsAdress(String) const;
                bool Add_Array(TStringList*);
                String Print() const;
                bool Save() const;

        private:
                TStringList *list;

                String PathToFile;
               };
//---------------------------------------------------------------------------
#endif
 