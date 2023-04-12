#include<iostream>
using namespace std;
#define MAX 20
#define INFINITE 999

int G[MAX][MAX],cities,cost,i,j,flights,visited[MAX]={0};
string CITY[MAX];
class Graph{
    public:
    void readGraph();
    void printGraph();
    void DFS();
};

void Graph::readGraph(){
    cout<<"Enter the no. of cities: ";
    cin>>cities;
    for(int i=0;i<cities;i++){
        cout<<"Enter the cities: ";
        cin>>CITY[i];

    }
    char ch;
    for(int i=0;i<cities;i++){
        for(int j=0;j<cities;j++){
            cout<<"If there is a flight between "<<CITY[i]<<"to "<<CITY[j]<<"Enter Y: ";
            cin>>ch;
            if(ch=='Y'||ch=='y'){
                cout<<"Enter the cost: ";
                cin>>cost;
                G[i][j]=cost;
                G[j][i]=cost;
            }
            else{
                G[i][j]=0;
            }

        }
    }
}
void Graph::printGraph(){
    for(int i=0;i<cities;i++){
        cout<<"\t"<<CITY[i];
    }
    for(int i=0;i<cities;i++){
        cout<<"\n"<<CITY[i];
        for(int j=0;j<cities;j++){
            cout<<"\t"<<G[i][j];
        }
    cout<<endl;
    }
    cout<<endl;
}


void Graph::DFS(){
    for(int i=0;i<cities;i++){
        for(int j=0;j<cities;j++){
            if(G[i][j]!=0 && visited[i]==0){
                cout<<"There is a flight between "<<CITY[i]<<"to "<<CITY[j];

            }
        }
        visited[i]=1;
    }
    for(int i=0;i<cities;i++){
        if(visited[i]==0){
            cout<<"The graph is not connected";

        }

    }
    cout<<"The graph is connected";
}

int main(){
    Graph obj;
    obj.readGraph();
    cout<<"The Graph is:- "<<endl;
    obj.printGraph();
    obj.DFS();

}