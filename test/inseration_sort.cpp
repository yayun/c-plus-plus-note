#include<iostream>
#include <string>
template <class T>
void insert_sort(T a[],int n)
{
    int i ,j;
    T temp;
    for (int i=1; i<n; i++)
    {
        int j=i;
        T temp=a[i];
        while(j>0&&temp<a[j-1])
        {
            a[j]=a[j-1];
            j--;
        }//temp 和前面的数逐个比较交换 直到j=0或者temp<a[j-1] 交换的过程中a[j-1] 还是原来的那个数 并没有换成temp
        a[j]=temp;
    }
    std::cout<<"the result:"<<std::endl;
    for(i=0;i<n;i++)
    {
        std::cout<<a[i]<<std::endl;
    }
}
int main()
{  
    using namespace std;
    //int n=sizeof(a)/sizeof(a[0]);
    cout<<"please input your data type 'int' 'char' or 'float'"<<endl;
    string str;
    cin>>str;
    if (str=="int")
    {
        cout<<"please input the number of your array"<<endl;
        int n;
        cin>>n;
        int a[n];
        cout<<"Please input the item of your array"<<endl;
        for (int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        insert_sort(a,n);
        main();
        return 0;
    }
    if (str=="char")
    {
        cout<<"please input the number of your array item"<<endl;
        int n;
        cin>>n;
        char a[n];
        cout<<"Please input the item of your array"<<endl;
        for (int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        insert_sort(a,n);
        main();
        return 0;
    }
    if (str=="float")
    {
        cout<<"please input the number of your array"<<endl;
        int n;
        cin>>n;
        float a[n];
        cout<<"Please input the item of your array"<<endl;
        for (int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        insert_sort(a,n);
        main();
        return 0;
    }
    else
    {
        cout<<"Please input the right data type"<<endl;
    }
    main();
    return 0;
}
