#include<stdio.h>

void selectionSort(int a[],int n) {
  int i, j, min, temp ;
  
  for(i=0; i<n-1 ; i++) {
    min = i;
    for(j=i+1; j<n ; j++) {
      if(a[j] < a[min])
        min = j;
      //  delay  ...
      for(d = 9999 ; d>0 ; d--) {
        d++;
        d--;
      }
      
    }
    temp = a[min];
    a[min] = a[i];
    a[i] = temp;
  }
}
