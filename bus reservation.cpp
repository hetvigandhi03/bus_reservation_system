#include <conio.h>

#include <cstdio>

#include <iostream>

#include <string.h>

#include <cstdlib>

using namespace std;

static int p = 0;

class a

{

  char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];

public:

  void install();

  void allotment();

  void empty();

  void show();

  void avail();

  void position(int i);

}

bus[10];

void vline(char ch)

{

  for (int i=80;i>0;i--)

  cout<<ch;

}

void a::install()

{
  cout<<"----------------------------";
  cout<<"\n|Enter bus no:       |  ";
  cin>>bus[p].busn;
  cout<<"|Enter Driver's name:|  ";
  cin>>bus[p].driver;
  cout<<"|Arrival time:       |  ";
  cin>>bus[p].arrival;
  cout<<"|Departure:          |  ";
  cin>>bus[p].depart;
  cout<<"|From:               |  ";
  cin>>bus[p].from;
  cout<<"To:                  |  ";
  cin>>bus[p].to;
  cout<<"---------------------------";
  bus[p].empty();

  p++;

}

void a::allotment()

{

  int seat;

  char number[5];

  top:

  cout<<"\nEnter the bus number for which you want to make a reservation: ";

  cin>>number;

  int n;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busn, number)==0)

    break;

  }

  while(n<=p)

  {

    cout<<"\nEnter your choice of seat number: ";

    cin>>seat;

    if(seat>32)

    {

      cout<<"\n**THERE ARE ONLY 32 SEATS IN THE BUS**.";

    }

    else

    {

    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)

      {

        cout<<"Enter the passenger's name:  ";

        cin>>bus[n].seat[seat/4][(seat%4)-1];

        cout<<"RESERVATION DONE SUCCESSFULLY";


        break;

      }

    else

      cout<<"**SORRY THE SEAT IS ALREADY RESERVED**.\n";

      }

      }

    if(n>p)

    {
      cout<<"OOPS! THE BUS IS NOT AVAILABLE";
      cout<<"\nEnter the correct bus no.\n";

      goto top;

    }

  }


void a::empty()

{

  for(int i=0; i<8;i++)

  {

    for(int j=0;j<4;j++)

    {

      strcpy(bus[p].seat[i][j], "Empty");

    }

  }

}

void a::show()

{

  int n;

  char number[5];

  cout<<"\n Enter the bus number of which you want to see the details: ";

  cin>>number;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busn, number)==0)

    break;

  }

while(n<=p)

{

  vline('*');

  cout<<"Bus no: \t"<<bus[n].busn

  <<"\nDriver: \t"<<bus[n].driver<<"\t\tArrival time: \t"<<bus[n].arrival<<"\tDeparture time:"<<bus[n].depart<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"<<bus[n].to<<"\n";

  vline('*');

  bus[0].position(n);

  int a=1;

  for (int i=0; i<8; i++)

  {

    for(int j=0;j<4;j++)

    {

      a++;

      if(strcmp(bus[n].seat[i][j],"Empty")!=0)

      cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";

    }

  }

  break;

  }

  if(n>p)
    cout<<"OOPS!! THE BUS IS NOT AVAILABLE";
    cout<<"\nEnter the correct bus no: ";

}

void a::position(int l)

{

  int s=0;p=0;

  for (int i =0; i<8;i++)

  {

    cout<<"\n";

    for (int j = 0;j<4; j++)

    {

      s++;

      if(strcmp(bus[l].seat[i][j], "Empty")==0)

        {

          cout.width(5);

          cout.fill(' ');

          cout<<s<<".";

          cout.width(10);

          cout.fill(' ');

          cout<<bus[l].seat[i][j];

          p++;

        }

        else

        {

        cout.width(5);

        cout.fill(' ');

        cout<<s<<".";

        cout.width(10);

        cout.fill(' ');

        cout<<bus[l].seat[i][j];

        }

      }

    }

  cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bus[l].busn;

  }

void a::avail()

{


  for(int n=0;n<p;n++)

  {

    vline('*');

    cout<<"\nBus no: \t"<<bus[n].busn<<"\nDriver: \t"<<bus[n].driver

    <<"\t\tArrival time: \t"<<bus[n].arrival<<"\tDeparture Time: \t"

    <<bus[n].depart<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t"

    <<bus[n].to<<"\n";

    vline('*');



  }

}

int main()

{

system("cls");

int w;
cout<<"\n\t============================================"<<endl;
 cout<<"\t|WELCOME TO ESCORTS BUS RESERVATION SYSTEM|\n";
 cout<<"\t============================================="<<endl;


while(1)

{


  cout<<"\n\n";

  cout<<"\t1.Add Bus Details\n\t"

  <<"2.Reservation\n\t"

  <<"3.Show\n\t"

  <<"4.Buses Available. \n\t"

  <<"5.Exit";

  cout<<"\n\tEnter your choice:-> ";
    cin>>w;

  switch(w)

  {

    case 1:  bus[p].install();

      break;

    case 2:  bus[p].allotment();

      break;

    case 3:  bus[0].show();

      break;

    case 4:  bus[0].avail();

      break;

    case 5:  exit(0);

  }

}

return 0;

}
