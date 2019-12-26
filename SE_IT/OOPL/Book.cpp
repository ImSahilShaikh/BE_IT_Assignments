//Sahil A Shaikh
#include<iostream>
#include<string.h>
using namespace std;
class book
{
	char *title,*author,*publisher;
	int *stock;
	double *price;
	public:
	static int t,tr;
	book()
	{
		stock=new int;
		price=new double;
		title=new char[1];
		author=new char[1];
		publisher=new char[1];
	}
	~book()
	{
		delete(author);
		delete(title);
		delete(publisher);
		delete(stock);
		delete(price);
	}
	void add(char *);
	void display();
	void modify();
	void purchase();
	void no_transaction()
	{
		cout<<"\nNo. Of Total Transactions: "<<t+tr;
		cout<<"\nNo. Of Sucessful Transactions: "<<t;
		cout<<"\nNo. Of Unsucessful Transactions: "<<tr;
	}
	char* rtitle()
	{
		return title;
	}

};
int book::t;
int book::tr;
void book::display()
{
    cout<<title<<"\t"<<author<<"\t"<<publisher<<"\t\t"<<*price<<"\t"<<*stock<<"\n";
}
void book::add(char *b)
{
	char s[100];
	strcpy(title,b);
	cout<<"\nEnter author name: ";
	cin>>s;
	strcpy(author,s);
	cout<<"\nEnter Publisher name: ";
	cin>>s;
	strcpy(publisher,s);
	do
	{
		cout<<"\nEnter *price: ";
		cin>>*price;
		}while(*price<=0);
	do
	{
		cout<<"\nENter stock: ";
		cin>>*stock;
	}while(*stock<=0);


}

void book::modify()
{
	char s[100];
	int ch;
	/*cout<<"\n1.Book Name";
	cout<<"\n2.Author Name: ";
	cout<<"\n3.Publisher Name: ";*/

	cout<<"\nEnter your choice to modify: ";
	cout<<"\n1.*price: ";
	cout<<"\n2.*stock: ";
	cin>>ch;
	switch(ch)
	{
		/*case 1:
		cout<<"\nEnter Book Title: ";
		cin>>s;
		strcpy(title,s);
		break;
		case 2:
		cout<<"\nEnter Author Name: ";
		cin>>s;
		strcpy(author,s);
		break;
		case 3:
		cout<<"\nENter Publisher Name: ";
		cin>>s;
		strcpy(publisher,s);
		break;*/
		case 1:
		do
		{
			cout<<"\nEnter *price: ";
			cin>>*price;
		}while(*price<=0);
		break;
		case 2:
		do
		{
			cout<<"\nEnter *stock: ";
			cin>>*stock;
		}while(*stock<0);
		break;
		default: cout<<"\nWrong Choice!!";
		}
	cout<<"\nBook Data Updated";
}
void book::purchase()
{
	int no;
	float tpr;
	cout<<"\nEnter How many books";
	cin>>no;
	if(no<=*stock&&no>0)
	{
		*stock-=no;
		tpr=no*(*price);
		cout<<"\nBook Details To Purchase:\n ";
		cout<<"Title\t"<<"Author\t"<<"Publisher\t"<<"*price\t"<<"Quantity\t"<<"T_*price"<<"\n";
		cout<<title<<"\t"<<author<<"\t"<<publisher<<"\t\t"<<*price<<"\t"<<no<<"\t\t"<<tpr<<"\n";
		cout<<"\nProcessed Book Purchased";
		t++;
	}
	else
	{
		cout<<"\nCopies Of The book are not available";
		tr++;
	}
}

int main()
{
    book b[20];
    char str[100],c;
    int i=0,ch,k=1,j=0,f=0;
    //book b1=new book();
    cout<<"\nBook store";
    cout<<"\nEnter the title of the book: ";
	  cin>>str;
	  b[j].add(str);
	  j++;
	  k=j;
    do
    {
    cout<<"\nBook Store";
    cout<<"\n1.Add books \n2.Display Books\n3.Search Book \n4.Modify Details\n5.Purchase books \n6.No of transcation\n7.Exit";
    cout<<"\nEnter choice(1-6): ";
    cin>>ch;
    switch(ch)
    {
      case 1:
	  do
	  {
	   c='n';
	     f=0;
	  cout<<"\nEnter the title of book: ";
	  cin>>str;
	     for(int l=0;l<k;l++)
		{
		   if(strcmp(b[l].rtitle(),str)==0)
		    {
			f=1;
			break;
		    }
		}
		if(f==0)
		   {
		     b[k].add(str);
		     k++;
		     //k=j;
		   }
		else
		   {
		     cout<<"\nTry again book name already exist";
		     cout<<"\nTry again (Y/N)? ";
		     cin>>c;
		   }
	  }while(c=='Y'||c=='y');
	break;
	case 2:
		cout<<"TITLE\t"<<"AUTHOR\t"<<"PUBLISHER\t"<<"*price\t"<<"*stock\n";
		for(i=0;i<k;i++)
		b[i].display();
		break;
	case 3:
		f=0;
		cout<<"\nEnter Book Name to Search: ";
		cin>>str;
		for(i=0;i<k;i++)
		{
		if(strcmp(b[i].rtitle(),str)==0)
		{
			f=1;
			cout<<"\nBook found\n";
			cout<<"Title\t"<<"Author\t"<<"Publisher\t"<<"*price\t"<<"*stock\n";
			b[i].display();
			break;
		}
	}
	if(f==0)
	cout<<"\nIncorrect Book Name";
	break;
	case 4:
	f=0;
	cout<<"\nEnter Book Name to modify: ";
	cin>>str;
	for(i=0;i<k;i++)
	{
		if(strcmp(b[i].rtitle(),str)==0)
		{
			f=1;
			cout<<"\n Book found\n";
			b[i].modify();
			break;

		}
	}
	if(f==0)
	cout<<"\nIncorrect Book Name!!\n TRY AGAIN";
	break;
	case 5:
	f=0;
	cout<<"\nEnter Book Name to Purchase: ";
	cin>>str;
	for(i=0;i<k;i++)
	{
		if(strcmp(b[i].rtitle(),str)==0)
		{
			f=1;
			cout<<"\nBook found\n";
			b[i].purchase();
			break;
		}
	}
	if(f==0)
	{
		b[i].tr++;
		cout<<"\nIncorrect Book Name!!\n TRY AGAIN";
	}
	break;
	case 6:
	b[i].no_transaction();
	break;
	case 7:
	break;
	}
	}while(ch>=1&&ch<=6);
	return 0;
}
