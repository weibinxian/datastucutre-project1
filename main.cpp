#include <iostream>
#include "LispList.h"
#include<functional>
#include<string>
using namespace std;

void print_num(int i) { cout << i << '\n'; }
std::function<void(int)> f_display = print_num;
int int_num(int x) {return x*x ;}
std::function<int(int)> xsquare=int_num;
int str_num(string x,int y){ return x.string::size();}
std::function<int(string,int)> strdis=str_num;
string str_cut(string x,int y){return x.substr(0,y);}
std::function<string(string,int)> subStr=str_cut;



int main() {

LispList<string> list1;
LispList<string> list2;
LispList<string> list3;
LispList<string> list6;
LispList<int> list4;
LispList<int> list5;
LispList<int> list7;
int stringsize1;
cout<<"plz enter a  number of your lines:  ";
cin>>stringsize1;
for(int stop=0;stop<stringsize1;stop++)
{
  string data;
  cout<<"plz enter a line of words : ";
  cin>>data;

  list1.add(data);
}
cout<<"Here the line that's being enter : ";
list1.print();
cout<<endl;
cout<<"Here are the size of the line that had enter : ";
list4=list1.map(strdis,list1,stringsize1);
list4.print();
cout<<endl;
cout<<"======================================================"<<endl;

//=====================================================================

int stringsize2;
cout<<"plz enter an other number for the second loop : ";
cin>>stringsize2;
for(int stop=0;stop<stringsize2;stop++)
{
  string data2;
  cout<<"plz enter a new word for second line : ";
  cin>>data2;
  list2.add(data2);

}
cout<<" Here are the size of the line that had enter : ";
list5=list2.map(strdis,list2,stringsize2);
list5.print();
cout<<endl;
cout<<"===================================================="<<endl;
//===============================================================
cout<<"Here's the new first set of elements : ";
list2=list1.map(subStr,list1,stringsize1);
list2.print();
cout<<endl;

list6=list1.append(list2);
list7=list6.map(strdis,list6,(stringsize1+stringsize2));
list7.print();

//===============================================================











  return 0;
}
