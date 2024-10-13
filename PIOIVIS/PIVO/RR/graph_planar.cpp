#include <iostream>
#include <vector>
#define MAX 100
using namespace std;

class graph
{
public:
int V;
vector <int> adj[MAX];
 
  void rebra(int v,int w)//////////////////////////////////////
  { 
    adj[v].push_back(w);
    adj[w].push_back(v);
  }

    bool proverka_is_planar()//////////////////////////////////////
   {
    for(int vertex=0;vertex<V;vertex++)
    {
      if(adj[vertex].size()==5)
     {
      return false;
     }
     if()
    }
    if 
   }

/*
void make_planar()
  {
    while (!proverka_planar)
    {for(int v=0;v<V;++v)
    if(adj[v].size()>5)
    remove();
    break;
    }

  }

};
*/

};

int main()
{
graph graph;
int v,e;
cout<<"Vvedite kolichestvo vershin i reber neorientirovanogo grafa: "<<'\n';
cin>>v>>e;
graph.V=v;
cout<<"vvedite rebra grafa :"<<'\t';

for (int i=0;i<e;i++)
{ 
  int u,v;
  cin>>u>>v;
  graph.rebra(u,v);
}
graph.make_planar();
cout<<"min of vershiny to remove that do a graph planar"<<v-graph.V<<'\n';
return 0;
}