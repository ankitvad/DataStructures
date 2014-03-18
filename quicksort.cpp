//Quick-Sort->Recursion.
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

void quickSort(int arr[], int left, int right)
 {int z;
  int i = left, j = right;
  int tmp;
  int pivot = arr[(left + right) / 2];

  /* partition */
  while (i <= j) 
   {
        while (arr[i] < pivot)
              i++;
        while (arr[j] > pivot)
              j--;
        if (i <= j) 
        {
              tmp = arr[i];
              arr[i] = arr[j];
              arr[j] = tmp;
              i++;
              j--;
        }
    }
/* recursion */
if (left < j)
    quickSort(arr, left, j);
if (i < right)
        quickSort(arr, i, right);
}


int main(){
    int arr[7]= {2,3,8,7,4,9,1};
        for(int i=0;i<7;i++)
    cout<<arr[i]<<" " ;
    quickSort(arr,0,6);
    cout<<endl;
    for(int i=0;i<7;i++)
    cout<<arr[i]<<" " ;
int wait;
cin>>wait;
return 0;
}

/*
int main()
{
	int a[30];
	int num;
	cout<<"\nPlease insert the number in the array.";
	cin>>num;
	int i;
	cout<<"\nPlease insert the elements :\n";
	for(i=0;i<num;i++)
	{
		cin>>a[i];
	}
	quickSort(a,a[0],a[num-1]);

	return 0;

}
*/