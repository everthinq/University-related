#include <iostream.h>

enum error {bounds, heap, other};

class vect_error
{	private:
	        error  e_type;

	        int ub, index, size;

	public:
	        vect_error(error, int, int){}	//����� ��� �������� ��������
	        vect_error(error, int){}		//����� ��� ������
};

void main ()
{
        try{
        throw vect_error(bounds, 0, 0);  }
        catch( vect_error & e)
        {
          cerr<<"err";
        }

        system("pause");
}
