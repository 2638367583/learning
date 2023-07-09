#include <iostream>
using namespace std;

void g_fPrintThePivotElements(int data[],int len)
{
    //从右往左，寻找每个位置及其之后的最小数
    int* rightMin = new int[len];
    int r_min = data[len-1];
    for (int i = len-1;i>=0;--i)
    {
        if(data[i]<r_min) {
            r_min = data[i];
//            printf("r_min = %d\n", r_min);
        }
        rightMin[i] = r_min;
//        printf("%d\n", r_min);
    }

    //从左往右，寻找比左边大且比右边小的数
    int l_max = data[0];
    for (int i=0;i<len;++i)
    {
        if(data[i]>=l_max)
        {
            l_max = data[i];
            if(data[i]<=rightMin[i])
                cout<<data[i]<<endl;
        }
    }
}

int main()
{
//    int dTestArray[]={1,8,6,9,10,15,12,20};
    //int dTestArray[]={0,2,1,6,7,8,5,9};
    int dTestArray[]={1,2,7,9,10,8,11};
    g_fPrintThePivotElements(dTestArray,sizeof(dTestArray)/sizeof(dTestArray[0]));
}