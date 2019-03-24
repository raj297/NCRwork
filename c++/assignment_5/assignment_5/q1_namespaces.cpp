#include<iostream>
#include "Namespace1.h"
#include "Namespace2.h"
using namespace std;
using namespace Operation;
using namespace AbsOperation;
int main()
{
	cout << "using namespace Operation::Add   " << Operation::Add(11, 12) << endl;
	cout << "using namespace Operation::Sub   " << Operation::Sub(51, 18) << endl;
	cout << "using namespace AbsOperation::Add   " << AbsOperation::Add(-11, -2) << endl;
	cout << "using namespace AbsOperation::Sub   " << AbsOperation::Sub(-11, -22) << endl;
	system("pause");
	return 0;
}
