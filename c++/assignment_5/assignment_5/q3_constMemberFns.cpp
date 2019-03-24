#include<iostream>
using namespace std;
class _test
{
	mutable int ele1;
	int ele2;
public:
	_test()
	{
		ele1 = 0; ele2 = 0;
	}
	void SetEle() const
	{
		ele1 = 12;
		//ele2 = 15;
	}
	void Display()
	{
		cout << "ele1=" << ele1 << endl << "ele2=" << ele2;

	}

};
int main()
{
	_test obj;
	obj.SetEle();
	obj.Display();
	cout << "Done";
	system("pause");
	return 0;
}