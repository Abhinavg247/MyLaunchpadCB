
#include <iostream>
#include <limits.h>
using namespace std;

int main(int argc, char const *argv[])
{
	long int a[100];
	int n;
	cin>>n;
	int max=INT_MIN;

	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>=(-1000000000)&& a[i]<=1000000000)
		{
			if(a[i]>max)
			{
				max=a[i];
			}
		}
		else
		{
			break;
		}
	}
	cout<<max<<endl;
	return 0;
}
