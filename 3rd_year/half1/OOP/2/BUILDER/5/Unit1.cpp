#include <iostream.h>
#include <string>
#include <sstream.h>
int main()
{
        system("chcp 1251");
	string buf, largest;
        int buff;
	// ��� �������� ����������
	int curLen,   // ����� �������� �����
	    max = -1, // ������������ ����� �����
	    cnt = 0;  // ������� ����������� ����
	while ( cin >>buff )
	{
                ostringstream temp;
                temp<<buff;
                buf=temp.str();
 		curLen = buf.size();
 		++cnt;

 		// ����� ����� ������� �����? �������� ���
 		if ( curLen > max )
		{
                        max = curLen;
                        largest = buf;
 		}
	}

	cout << "����� ����������� ���� " << cnt << endl;
        cout << "����� ������ �������� ����� " << max << endl;
	cout << "����� ������� ����� " << largest << endl;
        system("pause");
}

