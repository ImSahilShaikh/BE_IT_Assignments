#include<iostream>
#include<vector>
using namespace std;

int findXi(int N,int ni)
{
    int i=1;
    while((N*i) % ni != 1)
    {
        i++;
    }
    return i;
}

void print(vector<int> disp)
{
    for(auto &element : disp)
    {
        cout<<element<<"\t";
    }
    cout<<endl<<endl;
}

int main()
{
    vector<int> b{2,3,1};
    vector<int> n{3,4,5};

    cout<<"Values of bi:"<<endl;
    print(b);

    cout<<"Values of ni:"<<endl;
    print(n);

    cout<<"Value Of N:"<<endl;
    int N = 1;
    for(int i:n)
    {
        N*=i;
    }
    cout<<N<<endl<<endl;

    cout<<"Values of Ni:"<<endl;
    vector<int> N_i;
    for(int i:n)
    {
        int temp = N/i;
        N_i.push_back(temp);
    }
    print(N_i);

    vector<int> Xi;
    for(int i=0;i<N_i.size();i++)
    {
        int xi = findXi(N_i.at(i),n.at(i));
        Xi.push_back(xi);
    }

    cout<<"Values of Xi:"<<endl;
    print(Xi);

    vector<int> bnx;
    for(int i=0;i<b.size();i++)
    {
        int temp = b.at(i) * N_i.at(i) * Xi.at(i);
        bnx.push_back(temp);
    }

    cout<<"Values of biNixi:"<<endl;
    print(bnx);

    int total_bnx=0;
    for(int i: bnx)
    {
        total_bnx += i;
    }
    cout<<"Values of sum(biNixi):"<<endl;
    cout<<total_bnx<<endl<<endl;

    int x = total_bnx % N;
    cout<<"X = sum(biNixi) % N"<<endl<<"= "<<total_bnx<<" % "<<N<<endl<<"= "<<x;

    return 0;
}
