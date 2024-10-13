#include <iostream>

int proverka(int a[],int n)//функция которая проверяет на наличие одинаковых элементов 
{
  for (int i = 0; i < n; i++)
   {
    for (int j = i + 1; j < n; j++) 
    {
      if (a[i] == a[j])
      {
       std::cout << "put elements again" << '\n';
        return 0;
      }
      else {
        i++;
        if (i >= n&&j>=n)return 1;
      }
    }
  } 
} 
void intersection (int a[], int b[],int n,int m)
{ int c[100];
  for (int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if (a[i]==b[j])
      { for (int i=0;i<n;i++)
        c[i]=a[i];
        std::cout<<"YOUR RESULT OF INTERSECTION"<<'\n'<<c[i]<<' '<<'\n';
      }
    } 
  }
  
}
void merger(int a[], int b[],int n,int m)
{int c[200];
int W=n+m;
for (int i=0;i<n;i++)
c[i]=a[i];
for (int i=n;i<W;i++)
c[i]=b[i-n];
std::cout<<"YOUR RESULT OF MERGE"<<'\n';
for (int i=0;i<W;i++)
std::cout<<c[i]<<' '<<'\n';

}

int main()
{
  int n,m,input;      int a[100],b[100];
  std::cout<<"enter a power of plethora A (0;100] "<<'\n';
  do{  std::cin>>n; } while (n>100||n<=0);
 
  std::cout<<"enter a power of plethora B (0;100] "<<'\n';
  do{  std::cin>>m; } while (m>100||m<0);

  std::cout <<"choose method of specifying a set :(1.Enumerative method),(2.By statements)"<<'\n';
  std::cin>>input;
//даем выбор пользователюзадать множества
  switch(input)
  {
  case 1://если выбрал перечислительный способ
  std::cout<<"enter an elements of plethora A"<<'\n';
  do {
    for (int i = 0; i < n; i++ )
     std::cin >> a[i];
  } while (!proverka(a,n));
 std::cout<<"enter an elements of plethora B"<<'\n';
  do{
    for(int j=0;j<n;j++)
  std::cin>>b[j];
  }while(!proverka(b,m));
    break;
  case 2://если выбрал способ задания множества высказвыванием
  std::cout<<"enter a function ";
  default: 
  std::cout<<"you enter a wrong number";
  return 0;
    break;
  }

intersection(a,b,n,m);
merger(a,b,n,m);
}


