#include<iostream>
using namespace std;
class hello
{
    public:
        int a,b,c;
        hello(int a0,int b0,int c0)
        {
            this->a=a0;
            this->b=b0;
        }
};
int main()
{
    hello* nihao=new hello(1,2,3); //（声明hello类的对象指针变量nihao指向动态的内存分配得到的内存地址）属于动态的创建对象 有参数 调用有形参的构造函数 使用构造函数来初始化 如果直接用hello nihao 使用默认的构造函数进行初始化
    cout<<nihao->a<<endl;  //使用对象指针变量nihao可以方便的访问对象成员
    cout<<nihao->b<<endl;
    cout<<nihao->c<<endl; //对该对象的某个成员c没有用户自定义的值 那么系统会为基本的数据类型和指针类型的成员用0赋初值 
    delete nihao;
    cout<<nihao->a<<endl;//对象一旦删除则指向该对象的指针变量仍旧会保存这个对象的地址值 这样的指针“悬摆指针” Qt提供了Qpointer 如果删除指向的Qobject对象 自动把其设置成0 
    return 0;

}
