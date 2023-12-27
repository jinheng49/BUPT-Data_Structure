// A-B
#include<stdio.h>
#include<string.h>
int main()
{
	char a[10005],b[10005];
	gets(a);
	gets(b);
	for(int i=0;i<strlen(a);i++)
	{
		if(strchr(b,a[i]))
		{
			continue;
		}
		else{
			printf("%c",a[i]);
		}
	}
	return 0;
 }  
