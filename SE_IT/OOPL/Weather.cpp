#include<iostream>
//#include<conio.h>
using namespace std;
class weather
{
int day,ht,lt,ar,as;
public:
weather()
	{
	ht=999;
	lt=999;
	as=999;
	ar=999;

	}
	int rday()
	{
	    return day;
	}
	void getdata(int);
	void display();
	int dispspeci(int);
	int del(int);
	void average(int,int);
	int modify(int);
};

void weather::getdata(int d)
{     int i,r;
      day=d;
	  again:
	  {
	  cout<<"\nEnter High Temperature: ";
	  cin>>ht;
	  cout<<"\nEnter Low temprature: ";
	  cin>>lt;
	  }
	  if(lt>ht)
	  {
	  	cout<<"Low temperature can't be greater than High temperature!!\nTry again!";
	  	goto again;
	  }
	  cout<<"\nEnter Amount of rain: ";
	  cin>>ar;
	  cout<<"\nEnter Amount of snow: ";
	  cin>>as;
}

int weather:: dispspeci(int r)
{
  int flag=0;
  if(day==r)
  {  cout<<"DAY"<<"\t"<<"HT"<<"\t"<<"LT"<<"\t"<<"RAIN"<<"\t"<<"SNOW"<<"\t"<<"\n";
     cout<<day<<"\t"<<ht<<"\t"<<lt<<"\t"<<ar<<"\t"<<as;
     flag=1;
  }
   return flag;
}
void weather::display()
{
cout<<day<<"\t"<<ht<<"\t"<<lt<<"\t"<<ar<<"\t"<<as;
}
int weather::modify(int r)
{
    int flag=0;
    if(r==day)
    {  flag=1;
       getdata(r);
    }

    return flag;

}
void weather::average(int n,int r)
{  static float avg_hight,avg_lowt,avg_rain,avg_snow,count;


 if(ht!=999&&lt!=999&&ar!=999&&as!=999)
  {
  avg_hight+=ht;
  avg_lowt+=lt;
  avg_rain+=ar;
  avg_snow+=as;
  count++;
  }

if(n-1==r)
{
   cout<<"Average HighTemperature"<<"\t"<<"Average LowTemperature"<<"\t"<<"AverageRainfall"<<"\t"<<"AverageSnowfall"<<"\t"<<"\n";
    cout<<"\t"<<avg_hight/count<<"\t\t"<<avg_lowt/count<<"\t\t"<<avg_rain/count<<"\t\t"<<avg_snow/count;
    avg_hight=0;avg_lowt=0;avg_rain=0;avg_snow=0;count=0;
}

}
int weather::del(int r)
{
    int flag=0;
    if(r==day)
    {
     day=0;
     ht=0;
	lt=0;
	as=0;
	ar=0;
	flag=1;
	}
	return flag;
}

int main()
{
	weather w[10];
	int i,m,t,j,day,r,k=0,f=0,n=0,ch;
	char c;
	 	do
	   {
	    cout<<"\nWeather Portal";
		cout<<"\n1.Accept Record\n";
		cout<<"2.Display Record \n";
		cout<<"3.Specific Day Weather Report\n";
		cout<<"4.Modify Day Report\n";
		cout<<"5.Delete Report\n";
		cout<<"6.Average Of Report\n";
		cout<<"7.Exit\n";
		cout<<"Enter your Choice(1-6): ";
		cin>>ch;
		switch(ch)
		{
			case 1:
        do
         {
            for(i=n;i<n+1;i++,k++)
			{ f=0;c='n';
		     cout<<"\nEnter the data  "<<"\n";
		     cout<<"\nday of month: ";
		     cin>>day;
		     if(i==0)
			 w[i].getdata(day);
			 else
             {
                 for(j=0;j<i;j++)
                 {
                    r=w[j].rday();
                    if(r==day)
                    {
                        cout<<"\nday already exist ";
                        cout<<"\nTry again(y/n)?";
                        cin>>c;
                        k--;
                        f=1;
                        break;
                    }
                 }
              if(f==0)
               w[i].getdata(day);
             }

			}
			n=k;
         }while(c=='y'||c=='Y');


			break;

			case 2:
            cout<<"Display the data\n";
			cout<<"DAY"<<"\t"<<"HT"<<"\t"<<"LT"<<"\t"<<"RAIN"<<"\t"<<"SNOW"<<"\t"<<"\n";
			for(i=0;i<n;i++)
			{
				w[i].display();
				cout<<"\n";
			}
			break;

			case 3:
            do
            {
            cout<<"Enter the day to display: ";
			cin>>m;

			for(i=0;i<n;i++)
			 {
			    r=w[i].dispspeci(m);
			    if(r==1)
                    break;
			 }
			if(r==0)
               {
                cout<<"\nDay not found";
                cout<<"\nTry again?(y/n): ";
                cin>>c;
               }
			cout<<"\n";
            }while(c=='y'||c=='Y');
           break;
			case 4:
			   do
               {
                  cout<<"enter the data to modify: ";
			     cin>>m;
			     for(i=0;i<n;i++)
			     {
			    r=w[i].modify(m);
			    if(r==1)
                    {   cout<<"\nDay Modified\n";
                        break;
                    }
			     }
			    if(r==0)
                {
                    cout<<"\nDay not found";
                   cout<<"\nWant to try agan(y/n):: ";
                   cin>>c;
                }

               }while(c=='y'||c=='Y');
            break;

			case 5:
            do
            { f=0;
              cout<<"\nEnter the day to delete the data: ";
            cin>>m;
            for(i=0;i<n;i++)
            {
                r=w[i].del(m);
                if(r==1)
                   {
                      cout<<"\nDeleted\n";
                      f=1;
                     break;
                   }
            }
            if(r==0)
              {
                cout<<"\nDay not Found";
                   cout<<"\nWant to try agan(y/n): ";
                   cin>>c;

              }
              if(f==1)
                break;

            }while(c=='y'||c=='Y');

            break;

            case 6:
            cout<<"\nAverage of Weather report\n";
            for(i=0;i<n;i++)
                w[i].average(n,i);
            case 7:
            return 0;
		}

	}while(ch>=1&&ch<=6);
	return 0;

}
