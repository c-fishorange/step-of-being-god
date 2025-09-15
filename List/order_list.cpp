#include<iostream>
#include<memory>
#include <cstring>

#define MAXSIZE  10000
struct list_node
{
  char name[20];
  int number;
};

struct list
{
  std::unique_ptr<list_node[]> number_list; 
  int length;
};

list Init_list() //初始化列表这里用了智能指针
{
  list L;
  L.number_list = std::make_unique<list_node[]>(MAXSIZE);
  if(!L.number_list) exit(1);
  L.length = 0;
  return L;
}

void add_list(list &L,char name[20],int number)
{
  if(L.length >= MAXSIZE) exit(1);
  std::strcpy(L.number_list[L.length].name, name);
  L.number_list[L.length].number = number;
  L.length++;
}

void show_list(const list &L)
{
  if(L.length == 0) std::cout << "此表为空" << std::endl;
  for(int i = 0;i<L.length;i++)
  {
    std::cout << "姓名：" << L.number_list[i].name <<std::endl;
    std::cout << "学号：" << L.number_list[i].number <<std::endl;
  }
}
int main()
{
  char name[4] = "cyc"; 
  std::cout << "Hello world!" <<std::endl;
  list list1 = Init_list();
  add_list(list1,name,43);
  show_list(list1);
  return 0;
}


