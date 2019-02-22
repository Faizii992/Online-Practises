
// THIS CODE TESTS WHICH COMPONENT AN ELEMENT BELONGS TO AND SHOWS THE ELEMENTS THAT BELONG IN EACH COMPONENT,MARKS THE NUMBER OF STRONGLY CONNECTED COMPONENTS AND SHOWS THE TOPOLOGICAL SORT TRAVERSAL
#include<bits/stdc++.h>
#define V 10
#define white 1
#define grey 2
#define black 3
#define false 0
#define true 1

using namespace std;
stack<int > stck;
stack<int > stck1;
vector< int > marking[V];
int node,edge;
int flag=0;
vector< int > adj[V];
vector <int > vec;
vector< int > visited;
int mark=-1;
vector < int > reversedadj[V];

int color[V];
void creategraph(int edge)
{
    int a,b;

    for(int i=0;i<edge;i++)
    { cin>>a>>b;
        adj[a].push_back(b);
        reversedadj[b].push_back(a);
    }
}
void DFS(int source)
{
    color[source]=grey;
    for(int i=0;i<adj[source].size();i++)
    {
        if(color[adj[source][i]]==white)
        {
            DFS(adj[source][i]);
        }
    }
    stck.push(source);
    stck1.push(source);
    color[source]=black;

}
void DFS2visit(int source)
{
  visited[source]=true;
  cout<<source<<" "<<endl;
marking[mark].push_back(source);
    for(int i=0;i<reversedadj[source].size();i++)
    {
        if(visited[reversedadj[source][i]]==false)
        {//cout<<source<<" "<<endl;
            DFS2visit(reversedadj[source][i]);
        }
    }




}
int main()
{

    cout<<"Enter node and edges: "<<endl;
    cin>>node>>edge;
    puts("");

    for(int i=0;i<node;i++)
    {
        adj[i].clear();
        reversedadj[i].clear();
        color[i]=white;
    }

visited.assign(node,false);

    cout<<"Enter two vertexes: "<<endl;
    puts("");
    creategraph(edge);


for(int i=0;i<node;i++)
{
    if(color[i]==white)
    {
        DFS(i);

    }

}

cout<<"The Topological sorted result: "<<endl;
puts("");
int flag=0;
while(!stck1.empty())
{
    int v=stck1.top();
    stck1.pop();
    cout<<v<<endl;
}

while(!stck.empty())
{
    int u=stck.top();
    stck.pop();
   // cout<<u<<endl;


if(visited[u]==false)
{
    mark++;
    cout<<"Component number :"<<mark<<" has the following elements: "<<endl;
    DFS2visit(u);
}

}
int find;
cout<<"Total number of connected components :"<<mark;
puts("");

cout<<"Enter number of tries : "<<endl;
int tries;
cin>>tries;
for(int k=1;k<=tries;k++)
{



cout<<"Enter the element to figure out which component it belongs to "<<endl;
cin>>find;
for(int i=0;i<=mark;i++)
{
    for(int j=0;j<marking[i].size();j++)
    {
        if(marking[i][j]==find)
        {
            cout<<" It belongs to the component number : "<<i+1<<endl;
            puts("");

        }
    }
}
//DFS(start);
}


puts("");
for(int i=0;i<=mark;i++)
{
    cout<<"Component "<<i+1<<" has the elements: "<<endl;
    for(int j=0;j<marking[i].size();j++)
    {
        cout<<"Element "<<j+1<<" : "<<marking[i][j];
        puts("");

    }
}
}
