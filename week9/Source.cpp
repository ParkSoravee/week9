#include<stdio.h>

void getStr(char*);
void check(char*);
void makeAllZero(int*);
int max(int*);

int main()
{
	char str[1000];
	char* pStr = str;
	getStr(pStr);
	check(pStr);
	return 0;
}
void getStr(char* pStr)
{
	scanf_s("%[^\n]s", pStr, 999);
}
void check(char* pStr)
{
	int ch[26];
	int* pCh = ch;
	int i = 0;
	makeAllZero(pCh);

	while(*(pStr+i) != '\0')
	{
		if (*(pStr + i) >= 'a' and *(pStr + i) <= 'z') ch[*(pStr+i) - 97]++;
		else if (*(pStr + i) >= 'A' and *(pStr + i) <= 'Z') ch[*(pStr+i) - 'A' + 'a' - 97]++;
		i++;
	}

	int theMost = max(pCh);
	for (int i=0;i<26;i++) if (ch[i] == theMost) printf("%c ", i + 97);
	printf("\n%d ", theMost);
}

void makeAllZero(int* pCh)
{
	for(int i=0;i<26;i++) *(pCh + i) = 0;
}

int max(int* pCh)
{
	int maxVal=0;
	for(int i=0;i<26;i++) if (*(pCh + i) > maxVal) maxVal = *(pCh + i);
	return maxVal;
}
