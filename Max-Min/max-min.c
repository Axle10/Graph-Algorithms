#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct res
{
	int maximum;
	int minimum;
};
void generate(int arr[],int n)
{
	srand(time(0));
         for(int i=0;i<n;i++)
         {
           arr[i]=rand()%99;
         }
}
void display(int arr[],int n)
{
  printf("\n array elements\n");
   for(int i=0;i<n;i++)
     printf("%d\t",arr[i]);


}
		  int min1,max1;
		struct res ITERATIVE_MAXMIN(int arr[],int p,int r,int max,int min)
		{
		struct res result;
		  max=arr[p];
		  min=arr[p];

		 for(int i=p+1;i<r;i++)
		 {
			if(arr[i]>max)
				max=arr[i];
			if(arr[i]<min)
				min=arr[i];

		 }
		 result.maximum=max;
		 result.minimum=min;
		return result;
		}

		struct res DIVIDE_MAXMIN(int arr[],int p,int r)
		{
			struct res result,temp1,temp2;
		 if(p==r)
		{
		  result.maximum=arr[p];
		  result.minimum=arr[p];
		 }
		else if(p==r-1)
		{
		   if(arr[p]>arr[r])
		   {   result.maximum=arr[p];
			  result.minimum=arr[r];
				   }
		  else
		   {
			 result.maximum=arr[r];
			  result.minimum=arr[p];
		   }
		}
		else{
		  int q=(p+r)/2;

		 temp1=DIVIDE_MAXMIN( arr, p,q);
		temp2=DIVIDE_MAXMIN( arr, q+1,r);
		 if(temp1.maximum>temp2.maximum)
		{
					result.maximum=temp1.maximum;
		}
		else
		{
					result.maximum=temp2.maximum;
		}
		 if (temp1.minimum<temp2.minimum)
		 {
			result.minimum=temp1.minimum;
		 }
		 else
		 {
		 	result.minimum=temp2.minimum;
		 }
   }
   return result;
}
void tabularCase(int arr[],int max,int min)
{
	int n;
	printf("\nS.no.\tn\tIterative\tDivide and Conquer\n");
	for(int a=1;a<=10;a++)
	{
		printf("%d\t",a);
		scanf("%d",&n);
		printf("\t\t");
		int arr[n];
		generate(arr,n);
clock_t t;
		t=clock();
       struct res result=ITERATIVE_MAXMIN(arr,0,n-1,max,min);
        t=clock()-t;

		double time_taken=((double)t/CLOCKS_PER_SEC);
		printf("%f",time_taken);
		printf("\t");

		clock_t x=clock();
		result=DIVIDE_MAXMIN(arr,0,n-1);
       x=clock()-x;

		time_taken=((double)x/CLOCKS_PER_SEC);
		printf("%f\n",time_taken);
		printf("\n");
	}
}

void main()
{
   int n;
  int ch;
  printf("\n enter the no of terms\n");
         scanf("%d",&n);
int max=0;
int min=0;

      int arr[n];
   printf("\n\t options available\n\t 0.quit\n\t1.generate random numbers and store in an array\n\t2.display array\n\t3.max and min with iterative\n\t4.max and min with dnc\n\t5.compare");
  do{

      printf("\n enter your choice\n");
      scanf("%d",&ch);

   switch(ch)
   {

    case 0:
      {
        exit(0);
        break;
      }
  case 1:

      {  generate(arr,n);


        break;
      }
   case 2:
     {
       display(arr,n);
      break;
     }
    case 3:
      {
    	  struct res result=ITERATIVE_MAXMIN(arr,0,n-1,max,min);
    	  printf("\nMax is : %d",result.maximum);
       printf("\nMin is : %d",result.minimum);
        break;
      }
    case 4:
      {
      struct res result=DIVIDE_MAXMIN(arr,0,n-1);
       printf("\nMax is : %d",result.maximum);
       printf("\nMin is : %d",result.minimum);
        break;
      }
   case 5:
   		tabularCase(arr,max,min);
   break;

 default:
    printf("\noption not available\n");
  }

}while(ch!=0);

}
