#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

void PrintInt(const int&nData)
{
    cout<<nData<<endl;
}

int main(int argc, char* argv[])
{

    vector<int> vecInt;
    for(int i=0; i<10;++i)
    {
       vecInt.push_back(i*10);
    }

    cout<<"向量中的内容为："<<endl;
    for_each(vecInt.begin(),vecInt.end(),PrintInt);
    cout<<"vector contains "<<vecInt.size()<<" elements"<<endl;

    vecInt.pop_back();//删除最后一个元素
    cout<<"删除最后一个元素后，vector contains "<<vecInt.size()<<" elements"<<endl;

    vector<int>::iterator k = vecInt.begin();
    vecInt.erase(k);//删除第一个元素
    //vecInt.erase(k); //迭代器k已经失效，会出错
    cout<<"删除第一个元素后，vector contains "<<vecInt.size()<<" elements"<<endl;

    //vecInt.erase(vecInt.begin(),vecInt.end()); //删除所有元素
    //cout<<"删除所有元素后，vector contains "<<vecInt.size()<<"elements"<<endl; //输出为0

    // vector<int>::iterator vecNewEnd =remove(vecInt.begin(),vecInt.end(),5); //删除元素
    vector<int>::iterator vecNewEnd =remove(vecInt.begin(),vecInt.end(),50); //删除元素，值为50
    cout<<"删除元素后，vector contains "<<vecInt.size()<<" elements"<<endl;
    cout<<"向量开始到新结束为止的元素："<<endl;
    for_each(vecInt.begin(),vecNewEnd,PrintInt);

    cout<<"向量中的元素："<<endl;
    for_each(vecInt.begin(),vecInt.end(),PrintInt);

    return 0;
}
