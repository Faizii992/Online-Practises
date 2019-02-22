

// THIS CODE SHOWS THE ELEMENTS OF A COMPONENT(WHICH IS GIVEN AS INPUT)
//IF NO SUCH COMP EXISTS THEN PRINT" NO COMP FOUND!"
// AND SHOWS THE ELEMENTS THAT BELONG IN EACH COMPONENT
//MARKS THE NUMBER OF STRONGLY CONNECTED COMPONENTS
// SHOWS THE TOPOLOGICAL SORT TRAVERSAL
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

cout<<"Enter the component number to show the elements of: "<<endl;
cin>>find;
if(find-1>mark)
{
    cout<<"No such element exists! "<<endl;
}
else
{
 cout<<"Elements of comp "<<find<<" is: "<<endl;
 int j=0;
for(int j=0;j<marking[find-1].size();j++)
{

   cout<<"Element "<<marking[find-1][j]<<endl;
   puts("");
}

}
}
