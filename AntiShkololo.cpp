#include "Answer.h"
#include <windows.h>
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	AutoAnsw a;
	string temp;
	getline(cin, temp);
	cout << a.getAnswer(temp, StrHelper::isToYou(temp)) << endl;
	getline(cin, temp);
	cout << a.getAnswer(temp, StrHelper::isToYou(temp)) << endl;
}