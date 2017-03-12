
#include"arraytemp_assign.h"
using namespace std;
int main()
{
	FileTemp Temp;
	float max=0, min=0;

	cout<<"Reading file\n";
	Temp.readfile();
	Temp.maxmin();
	Temp.averages();
	cout<<endl;
	cout<<"Writing information to file\n";
	Temp.histogram();
	cout<<endl;

	system("pause");
	return 0;
}
