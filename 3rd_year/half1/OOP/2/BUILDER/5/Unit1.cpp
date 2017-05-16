#include <iostream.h>
#include <string>
#include <sstream.h>
int main()
{
        system("chcp 1251");
	string buf, largest;
        int buff;
	// для хранения статистики
	int curLen,   // длина текущего слова
	    max = -1, // максимальная длина слова
	    cnt = 0;  // счетчик прочитанных слов
	while ( cin >>buff )
	{
                ostringstream temp;
                temp<<buff;
                buf=temp.str();
 		curLen = buf.size();
 		++cnt;

 		// новое самое длинное слово? сохраним его
 		if ( curLen > max )
		{
                        max = curLen;
                        largest = buf;
 		}
	}

	cout << "Число прочитанных слов " << cnt << endl;
        cout << "Длина самого длинного слова " << max << endl;
	cout << "Самое длинное слово " << largest << endl;
        system("pause");
}

