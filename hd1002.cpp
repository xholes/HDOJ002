#include <iostream>
#include <string>
using  namespace std;
void init();
void datainput();
void add();
void display();
const int max(1000);
const int Tmax(20);
int T,cnt;
char in[2 * Tmax][max], out[Tmax][max + 1];
int main()
{
	init();
	cin >> T;
	cnt = 2 * T;
	datainput();
	add();
	display();
	system("pause");
	
}
void init()
{
	int i, j;
	for (i = 0; i < 2 * Tmax; i++)
		for (j = 0; j < max; j++)
			in[i][j] = '\0';
	for (i = 0; i < Tmax; i++)
		for (j = 0; j < (max+1); j++)
		out[i][j] = '\0';
}
void datainput()
{
	int i=0,s=0;
	while (s<cnt)
	{
		cin >> in[i];
		s++; i++;
	}
}
void add()
{
	int m,n,i, j,len1,len2,ads,temp;
	char a[max]="", b[max]="", sum[max + 1]="";
	for (m = 0; m < T; m++)
	{   
		ads = 0;
		for ( i = 0; i <max+1 ; i++)
		{
			sum[i] = '\0';
		}
		for (n = 0; n < max; n++)
		{
			a[n] = in[2 * m][n]; 
			b[n] = in[2 * m + 1][n];
		}
		len1 = strlen(a) - 1;
		len2 = strlen(b) - 1;
		if (len1 <= len2)
		{
			for (i = len1, j = len2; i >= 0; i--, j--)
			{
				if ((temp = -96 + a[i] + b[j]) >= 10)
				{
					sum[j + 1] = char(48 + temp % 10 + ads);
					ads = 1;
				}
				else
				{
					sum[j + 1] = char(48 + temp % 10 + ads);
					ads = 0;
				}

			}
			for (; j >= 0; j--)
			{
				if ((temp = b[j] + ads - 48) >= 10)
				{
					sum[j + 1] = 48 + temp % 10; ads = 1;
				}
				else
				{
					sum[j + 1] = 48 + temp % 10; ads = 0;
				}

			}
			sum[0] = char(48 + ads);

		}
		else
		{
			for (i = len1, j = len2; j >= 0; i--, j--)
			{
				if ((temp = -96 + a[i] + b[j]) >= 10)
				{
					sum[i + 1] = 48 + temp % 10 + ads; ads = 1;
				}
				else
				{
					sum[i + 1] = 48 + temp % 10 + ads; ads = 0;
				}

			}
			for (; i >= 0; i--)
			{

				if ((temp = a[i] + ads - 48) >= 10)
				{
					sum[i + 1] = 48 + temp % 10; ads = 1;
				}
				else
				{
					sum[i + 1] = 48 + temp % 10; ads = 0;
				}


			}
			sum[0] = char(48 + ads);
		}
		for (i = 0; i < max + 1;i++)
		{
			out[m][i] = sum[i];
		}

	}

}
void display()
{
	int i, j,k;
	for ( i = 0; i < T; i++)
	{
		j = k = 0;
		cout << "case" << i << ":" << endl;
		while (in[2 * i][j] != '\0')
		{
			cout << in[2 * i][j];
			j++;
		}
		cout << " + ";
		j = 0;
		while (in[2 * i+1][j] != '\0')
		{
			cout << in[2 * i+1][j];
			j++;
		}
		cout << " = ";
		j = 0;
		if (out[i][j]=='0')
		{
			if (out[i][j+1] == '\0')
			{
				cout << 0;
			}
			else
				while (out[i][j + 1] != '\0')
				{
					cout << out[i][j + 1]; j++;
				}
		}
		else
			while (out[i][j] != '\0')
			{
				cout << out[i][j]; j++;
			}
		cout << endl << endl;

	}
}