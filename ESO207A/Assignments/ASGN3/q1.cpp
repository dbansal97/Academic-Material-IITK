#include <bits/stdc++.h>

using namespace std;
int quickcompare=0,mergecompare=0;
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {   mergecompare++;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    
    int i = (low - 1);  
 
    for (int j = low; j <= high- 1; j++)
    {   
        quickcompare++;
        if (arr[j] <= pivot)
        {
            i++;    
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main(){
    int t;
    cin>>t;
    int y=t;
    double total_quick=0,total_merge=0;
    double dif;
    int count=0;
    int n;
    cin>>n;
    double *d;
     d=(double *) malloc(t*sizeof(double));
    while(t--){
    int *a,*b,*c;
    a=(int *) malloc(n*sizeof(int));
    b=(int *) malloc(n*sizeof(int));
    c=(int *) malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        a[i]=rand();
        //cout<<a[i]<<" ";
        b[i]=a[i];
        c[i]=a[i];
    }
    clock_t begin = clock();

    quickSort(b,0,n-1);

  clock_t end = clock();
     dif = double(end - begin) / CLOCKS_PER_SEC;
     d[t-1]=dif;
  total_quick+=dif;
    //printf ("Elasped time for quicksort is %.5lf seconds.\n", dif );
    begin = clock();

    mergeSort(c,0,n-1);

    end = clock();
     dif = double(end - begin) / CLOCKS_PER_SEC;
     total_merge+=dif;
     int oldmerge=0,oldquick=0;
     if(mergecompare-oldmerge<quickcompare-oldquick){
        count++;
     }
     oldmerge=mergecompare;
     oldquick=quickcompare;

    //printf ("Elasped time for mergeSort is %.5lf seconds.\n", dif );
     free(a);
     free(b);
     free(c);
    }
    total_merge=total_merge/y;
    printf ("Average Elasped time for mergeSort is %.6lf seconds.\n", total_merge );
    total_quick=total_quick/y;
    printf ("Average Elasped time for quicksort is %.6lf seconds.\n", total_quick );
    quickcompare/=y;
    printf ("Average comparisons for quicksort is %d .\n", quickcompare );
    mergecompare/=y;
    printf ("Average comparisons for mergesort is %d .\n", mergecompare );
    printf ("No. of times MergeSort had lesser no. of comparisons than QuickSort %d . \n",count );
    int ans=0;
    double ans2;
    for(int i=0;i<y;i++){
        if(d[i]>1.05*total_quick){
            ans++;
        }
    }
    ans2=(ans*1.0/y)*100;
    printf("Percentage of cases when quicksort exceeds 5percent of average is %lf\n",ans2);
   
     ans=0;
     for(int i=0;i<y;i++){
        if(d[i]>1.1*total_quick){
            ans++;
        }
    }
    ans2=(ans*1.0/y)*100;
    printf("Percentage of cases when quicksort exceeds 10percent of average is %lf\n",ans2);
    ans=0;
 for(int i=0;i<y;i++){
        if(d[i]>1.2*total_quick){
            ans++;
        }
    }
    ans2=(ans*1.0/y)*100;
    printf("Percentage of cases when quicksort exceeds 20percent of average is %lf\n",ans2);
    ans=0;
 for(int i=0;i<y;i++){
        if(d[i]>1.3*total_quick){
            ans++;
        }
    }
    ans2=(ans*1.0/y)*100;
    printf("Percentage of cases when quicksort exceeds 30percent of average is %lf\n",ans2);
    ans=0;
 for(int i=0;i<y;i++){
        if(d[i]>1.4*total_quick){
            ans++;
        }
    }
    ans2=(ans*1.0/y)*100;
    printf("Percentage of cases when quicksort exceeds 40percent of average is %lf\n",ans2);
    
    ans=0;
 for(int i=0;i<y;i++){
        if(d[i]>2*total_quick){
            ans++;
        }
    }
    ans2=(ans*1.0/y)*100;
    printf("Percentage of cases when quicksort exceeds 100percent of average is %lf\n",ans2);
    

    return 0;
}
