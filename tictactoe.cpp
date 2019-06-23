#include<iostream>
#include<conio.h>
using namespace std;

char numarray[3][3];

class tic
{
char a[3][3];
public:
void initiate();
void urturn();
void cturn();
int check();
void display();
};
tic b;
void tic::initiate()
{
int i,j;
for(i=0;i<3;i++)
for(j=0;j<3;j++)
a[i][j]=' ';
}
void tic::urturn()
{
int n,div,rem;
cout<<"\nits ur turn\n";
cout<<"enter the no. to enter 'X'\n";
cin>>n;
n--;
div=n/3;
rem=n%3;
if(a[div][rem]==' ')
{
a[div][rem]='X';
}
else
{
cout<<"invalid row no. and column no.\n";
b.urturn();
}
}
int tic::check()
{
int i,j,count=0;
for(i=0;i<3;i++)
{
if((a[i][0]=='X' && a[i][1]=='X' && a[i][2]=='X')||(a[0][i]=='X' && a[1][i]=='X' && a[2][i]=='X')||(a[0][0]=='X' && a[1][1]=='X' && a[2][2]=='X')||(a[0][2]=='X' && a[1][1]=='X' && a[2][0]=='X'))
{
    b.display();
cout<<"you won! congrats\n"; return 0;
}
if((a[i][0]=='O' && a[i][1]=='O' && a[i][2]=='O')||(a[0][i]=='O' && a[1][i]=='O' && a[2][i]=='O')||(a[0][0]=='O' && a[1][1]=='O' && a[2][2]=='O')||(a[0][2]=='O' && a[1][1]=='O' && a[2][0]=='O'))
{
    b.display();
cout<<"computer won! Do well next time\n"; return 0;
}
}
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
if(a[i][j]!=' ')
count++;
}
}
if(count==9)
return 1;
return 2;
}
void tic::display()
{
int i,j;
for(i=0;i<3;i++)
    for(j=0;j<3;j++)
    if(a[i][j]!=' ')
    numarray[i][j]=' ';
for(i=0;i<3;i++)
{
cout<<" "<<a[i][0]<<" | "<<a[i][1]<<" | "<<a[i][2]<<" "<<"           "<<" "<<numarray[i][0]<<" | "<<numarray[i][1]<<" | "<<numarray[i][2]<<" ";
if(i!=2)
cout<<"\n___________           ___________\n";
}
cout<<endl<<endl;
}
void tic::cturn()
{
int i,j;
for(i=0;i<3;i++)
{
if((a[i][0]!=' ' && a[i][1]!=' ') && (a[i][0]==a[i][1]) && (a[i][2]==' '))
{a[i][2]='O';return;}
else
if((a[i][1]!=' ' && a[i][2]!=' ') && (a[i][1]==a[i][2]) && (a[i][0]==' '))
{a[i][0]='O';return;}
else
if((a[i][0]!=' ' && a[i][2]!=' ') && (a[i][0]==a[i][2]) && (a[i][1]==' '))
{a[i][1]='O';return;}
else
if((a[0][i]!=' ' && a[1][i]!=' ') && (a[0][i]==a[1][i]) && (a[2][i]==' '))
{a[2][i]='O';return;}
else
if((a[1][i]!=' ' && a[2][i]!=' ') && (a[1][i]==a[2][i]) && (a[0][i]==' '))
{a[0][i]='O';return;}
else
if((a[0][i]!=' ' && a[2][i]!=' ') && (a[0][i]==a[2][i]) && (a[1][i]==' '))
{a[1][i]='O';return;}
}
if((a[0][0]!=' ' && a[1][1]!=' ') && (a[0][0]==a[1][1]) && (a[2][2]==' '))
{a[2][2]='O';return;}
else
if((a[1][1]!=' ' && a[2][2]!=' ') && (a[1][1]==a[2][2]) && (a[0][0]==' '))
{a[0][0]='O';return;}
else
if((a[0][0]!=' ' && a[2][2]!=' ') && (a[0][0]==a[2][2]) && (a[1][1]==' '))
{a[1][1]='O';return;}
else
if((a[0][2]!=' ' && a[1][1]!=' ') && (a[0][2]==a[1][1]) && (a[2][0]==' '))
{a[2][0]='O';return;}
else
if((a[1][1]!=' ' && a[2][0]!=' ') && (a[1][1]==a[2][0]) && (a[0][2]==' '))
{a[0][2]='O';return;}
else
if((a[0][2]!=' ' && a[2][0]!=' ') && (a[0][2]==a[2][0]) && (a[1][1]==' '))
{a[1][1]='O';return;}
else
{
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
if(a[i][j]==' ')
{a[i][j]='O';return;}
}
}
}
}
int main()
{
  int c,i,j;
  char count='1';
  for(i=0;i<3;i++)
    for(j=0;j<3;j++)
    numarray[i][j]=count++;
cout<<"welcome to tic tac toe game\n";
b.initiate();
for(i=1;i<=9;i++)
{
b.display();
b.urturn();
c=b.check();
if(c==0)
break;
else
if(c==1)
{
    b.display();
cout<<"\ndraw game\n";
break;
}
else
{
b.display();
b.cturn();
c=b.check();
if(c==0)
break;
else
if(c==1)
{
    b.display();
cout<<"\ndraw game\n";
break;
}
else
continue;
}
}
getche();
return 0;
}
