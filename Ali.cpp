#include <iostream>
using namespace std;
//冒泡排序
void bubbleSort(int arr[], int n)
{
	for(int i = 0;i < n;i++){  
		//比较两个相邻的元素   
		for(int j = 0;j < n-i-1;j++){  
            if(arr[j] > arr[j+1]){  
                int t = arr[j];  
                arr[j] = arr[j+1];  
                arr[j+1] = t;  
            }  
        }  
    }       
}
//字典排序========================================================//
void swap(int *arr, int i, int j)  
{  
    int tmp = arr[i];  
    arr[i]  = arr[j];  
    arr[j]  = tmp;  
}    
void reverse(int *arr, int first, int last)  
{  
    while( first != last && first != --last)  
    {  
        swap(arr, first, last);  
        first++;  
    }  
}  
  
//true   数组元素顺序改变  
//false  数组元素顺序没有改变  
bool permutation(int *arr, int N)  
{  
    if(N == 0 || N == 1)  
        return false;  
  
    int last = N;  
    //ii代表i-1  
    int ii = last - 1;  
    int i  = ii - 1;  
  
    while(true)  
    {     
        if(arr[i] < arr[ii])  
        {  
            int j = last - 1;  
            while( !(arr[i] < arr[j]) )  
                j--;  
          
            swap(arr, i, j);  
            //i位置后（不包含i）元素逆序  
            reverse(arr, ii, last);  
            return true;  
        }  
        //已是递减排序，无下一个排序了。  
        if(i == 0)  
        {  
            //全部倒序，恢复最初状态  
            reverse(arr, i, last);  
            return false;  
        }  
        i--; ii--;  
    }  
}  
//=======================================================//

//判断是否是合法的时间，不合法返回1.
  bool notleagal(int *start)
  {
     if((((*start)*10)+*(start+1))>23||*(start+2)>5||*(start+4)>5)
         return 1;
      else return 0;
  }

int main()  
{  
    //初始化
    int arr[] = {1,1,1,1,1,1};  
    int arrr[720*6];//计算得到的极限容量
    int illeagal=0;
    int no=0;
    int max=0;
    int min=0;
    int size  = 6;
    //用户输入
    cin>>size;
    for(int i = 0; i < size; i++)  
    cin>>*(arr+i);
    //冒泡排序处理用户输入
    bubbleSort(arr,size);    
    //数组赋初值
    for(int i = 0; i < size; i++)  
         *(arrr+i)=arr[i]; 
    no=1;//arrr里放第一个数字（即输入数字升序排列）序号是1    
    
    while(permutation(arr, size))  //产生后面所有的数字
    {  
        for(int i = 0; i < size; i++)  
            {*(arrr+6*no+i)=arr[i];} 
        no++;      
    }    
    
    max=no;//统计字典排序的数量
    //搜索最小的时间
    while (notleagal(arrr+(min)*6)&&min<max)
        {min++;}
    if(min<max)
    {
        for(int i = 0; i < size; i++)  
            cout<< *(arrr+6*min+i);
            cout<<",";
            
        while ( notleagal(arrr+(max-1)*6))//搜索最大的时间
            {max--;}
        for(int i = 0; i < size; i++)  
        {cout<< *(arrr+6*max-6+i);}
    }
    else {cout<<"N/A";}//找不到，报错
 
    return 0;  
}  