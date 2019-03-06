#define lenMax 25
#include <iostream>
using namespace std;
void expand(char *s1, char *s2);
int checkInput(char *s);
int sizetoExpand = 0;
int main() {
	char *s1, *s2=NULL;
	s1 = new char[lenMax];
     	    cout << "enter the string to expand"<<endl;
		   cin>>(s1);

	int valid = checkInput(s1);
	if (valid)
		expand(s1, s2);
	else
		cout << endl << "Invalid Input";
	getchar();
	getchar();
	}
int checkInput(char *s1)
{
	int i = 0,len=0, j, l, h;
	while (s1[i++] != '\0')
		len++;
	j = len;
	i = 0;
	while (*(s1 + i++) != '\0')
	{
		if (*(s1 + i) == '-')
		{
			j--;
			l = *(s1 + i - 1);
			h = *(s1 + i + 1);

			if (isalpha(l) && isalpha(h))
			{
				if ((islower(l) && islower(h)) || (isupper(l) && isupper(h)))
				{
					if (l < h)
					{
						sizetoExpand =  h-l;
						return 1;
					}
				}
			}
			else if (isdigit(l) && isdigit(h))
			{
				if (l < h)
					return 1;
			}
			else
				return 0;
		}
	}
}
void expand(char *s1, char *s2)
{
	char l, h, j = 0, i = 0;
	s2 = new char[sizetoExpand];
	while (*(s1 + i) != '\0')
	{
		if (*(s1 + i + 1) != '-')
		{
			*(s2 + j) = *(s1 + i);
			j++;

		}
		if (*(s1 + i) == '-')
		{
			j--;
			l = *(s1 + i - 1);
			h = *(s1 + i + 1);
		
			for (int i1 = l; i1 < h; i1++)
			{
				*(s2 + j) = (char)(i1);
				j++;

			}
		}
		i++;

	}
	s2[i+1] = '\0';
	cout << "on expansion "<<s2<<endl;
}