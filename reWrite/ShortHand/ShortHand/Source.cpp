//expansion of str
#define lenMax 25 //maximum length of the input string to expand
#include <iostream>
using namespace std;
void expand(char *, char *);
int checkInput(char *);
int sizetoExpand = 0;//updates on visiting a '-'
int main()
{
	char *source_Str1, *expandsTo_Str2 = NULL;
	source_Str1 = new char[lenMax];
	char ch = 'y';
	while (ch == 'y') {
		cout << "enter the string to expand" << endl;
		cin >> (source_Str1);

		int valid_Ret = checkInput(source_Str1);//input validation
		if (valid_Ret)
			expand(source_Str1, expandsTo_Str2);//call to expand 
		else
			cout << endl << "Invalid Input"<<endl;
		cout << "enter y to continue else someother"<<endl;
		cin >> ch;
	}

}
/*input validator*/
int checkInput(char *source_Str1)
{
	int source_Itr = 0, expandFrom, expandTill, flag = 0;
	while (source_Str1[source_Itr++] != '\0')
		sizetoExpand++;//inc sizetoExpand to length of source as it is min 
	source_Itr = 0;
	if (source_Str1[0] == '-' || source_Str1[strlen(source_Str1)-1] == '-')
		return 0;

	//checking if the source contains consecutive '-';
	while (*(source_Str1 + (source_Itr++)) != '\0')
	{
		if (*(source_Str1 + (source_Itr)) == '-')
		{
			flag = 1;//check for atleast one '-'
			if (*(source_Str1 + (source_Itr)+1) == '-')
				return 0;
		}
	}
	if (flag == 0)//check that no expansions req;
		return 1;
	source_Itr = 0;
	/*checking for correct input expansions*/
	while (*(source_Str1 + source_Itr++) != '\0')
	{
		if (*(source_Str1 + source_Itr) == '-')
		{

			expandFrom = *(source_Str1 + source_Itr - 1);
			expandTill = *(source_Str1 + source_Itr + 1);

			if (isalpha(expandFrom) && isalpha(expandTill))
			{
				if ((islower(expandFrom) && islower(expandTill)) || (isupper(expandFrom) && isupper(expandTill)))
				{
					if (expandFrom < expandTill)
					{
						sizetoExpand = sizetoExpand + expandTill - expandFrom;//calculating the size to expand by diff of ascii values
					//cout<<sizetoExpand;
						return 1;
					}
				}
			}
			else if (isdigit(expandFrom) && isdigit(expandTill))
			{
				if (expandFrom < expandTill)
					return 1;
			}
			else
				return 0;
		}
	}
}
//expansion function
void expand(char *source_Str1, char *expandsTo_Str2)
{
	char expandFrom, expandTill, expands_Itr = 0, source_Itr = 0;
	expandsTo_Str2 = new char[sizetoExpand];
	while (*(source_Str1 + source_Itr) != '\0')
	{
		if (*(source_Str1 + source_Itr + 1) != '-')
		{
			*(expandsTo_Str2 + expands_Itr) = *(source_Str1 + source_Itr);
			expands_Itr++;

		}
		if (*(source_Str1 + source_Itr) == '-')
		{
			expands_Itr--;
			expandFrom = *(source_Str1 + source_Itr - 1);
			expandTill = *(source_Str1 + source_Itr + 1);

			for (int for_Itr = expandFrom; for_Itr < expandTill; for_Itr++)
			{
				*(expandsTo_Str2 + expands_Itr) = (char)(for_Itr);
				expands_Itr++;

			}
		}
		source_Itr++;

	}
	expandsTo_Str2[expands_Itr] = '\0';
	cout << "on expansion " << expandsTo_Str2 << endl;
}