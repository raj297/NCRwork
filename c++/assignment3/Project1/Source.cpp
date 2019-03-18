#include<iostream>
#define max 5
using namespace std;
template <typename t,class test=char>
int  search(t arr[], t key)
{
	for (int idx = 0; idx < max; idx++)
	{
		if (arr[idx] == key)
			return idx;
	}
	return -1;
}

class test
{
public:
	int  search(char arr[], char key)
	{
		for (int idx = 0; idx < max; idx++)
		{
			if (arr[idx] == key)
				return idx;
		}
		return -1;
	}


};
void print(int idx)
{
	if (idx >= 0)
		cout << "elemenet found at  idx::" << idx << endl;
	else
		cout << "no sch element";
}

int main()
{
	int arrI[max] = { 1,2,3,4,5 };
	double arrF[max] = { 1.2,1.5,3.2,33.2,21.2 };
	char arrC[max] = { 'a','b' };
	int idx = search(arrI, 3);
	print(idx);
	idx = search(arrF, 3.000);
	print(idx);
	idx = search(arrC, 'a');
	print(idx);
	getchar();

}