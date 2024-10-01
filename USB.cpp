#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream ofsLPT1("COM7");
	if (ofsLPT1)
	{
		ofsLPT1 << "Ola mundo na primeira linha." << endl;
		ofsLPT1 << "Ola mundo na segunda linha\n." << endl;

		ofsLPT1 << "\f";
		ofsLPT1.flush();

		ofsLPT1 << "Ola mundo na outra pagina2." << endl;
		ofsLPT1.close();

	}
	return 1;
}

