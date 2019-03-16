#include<bits/stdc++.h>

using namespace std;

template<typename T>
class Graph{

	map<T,list<pair<T,int>>> adjList;

public:
	Graph()
	{
		
	}

	void addEdge(T u, T v, int weight, bool bidir=true)
	{
		pair<T,int> p;
		p = make_pair(v,weight);

		adjList[u].push_back(p);
		if(bidir==true)
			{	
				p = make_pair(u,weight);
				adjList[v].push_back(p);
			}
	}

	void printAdjList()
	{
		for(auto i : adjList)
		{
			cout<<i.first<<"->";
			for(auto vertex : i.second)
				{
					cout<<"("<<vertex.first<<","<<vertex.second<<")";
				}
			cout<<endl;
		}
	}

	void dijkstraSSSP(T src)
	{
		unordered_map<T,int> dist;

		for(auto i : adjList)
			dist[i.first] = INT_MAX;

		dist[src] = 0;

		set<pair<int,T>> set;
		set.insert(make_pair(dist[src],src));

		while(!set.empty())
		{
			auto p = *(set.begin());
			T node = p.second;
			// int nodeDist = p.first;

			set.erase(set.begin());

			for(auto i : adjList[node])
			{
				auto child = i.first;
				auto childDist = i.second;

				if(dist[child] > dist[node] + childDist)
				{
					auto ptr = set.find(make_pair(dist[child],child));
					if(ptr!=set.end())
					{
						set.erase(ptr);
					}
					dist[child] = dist[node] + childDist;
					set.insert(make_pair(dist[child],child));
				}
			}

		}

		cout<<endl;

		for(auto i : dist)
		{
			cout<<"Distance of "<<i.first<<" from "<<src<<" = "<<i.second<<endl;
		}

	}


};

int main()
{
	#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);

  freopen("output.txt","w",stdout);
  #endif
  // Graph<int> g;

  // g.addEdge(0,1);
  // g.addEdge(1,2);
  // g.addEdge(0,4);
  // g.addEdge(2,4);
  // g.addEdge(2,3);
  // g.addEdge(3,5);
  // g.addEdge(3,4);

  // g.addEdge(0,1);
  // g.addEdge(1,2);
  // g.addEdge(2,3);
  // g.addEdge(3,4);
  // g.addEdge(4,0);

  // g.addEdge("P","Q");
  // g.addEdge("Q","R");
  // g.addEdge("R","S");
  // g.addEdge("S","Q");

  // g.addEdge("K","O");
  Graph<string> india;
  india.addEdge("Amritsar","Delhi",1);
  india.addEdge("Amritsar","Jaipur",4);
  india.addEdge("Jaipur","Delhi",2);
  india.addEdge("Jaipur","Mumbai",8);
  india.addEdge("Bhopal","Agra",2);
  india.addEdge("Mumbai","Bhopal",3);
  india.addEdge("Agra","Delhi",1);

  india.printAdjList();
  india.dijkstraSSSP("Amritsar");
// g. addEdge( "English" , "Programming Logic" , false);
// g.addEdge( "Maths" , "Programming Logic " , false); 
// g. addEdge( "Programming Logic " , "HTML " , false); 
// g.addEdge( "Programming Logic " , "Python" , false); 
// g.addEdge( "Programming Logic " , "Java " , false); 
// g. addEdge( "Programming Logic", "JS",false);
// g.addEdge( "Python" , "Web Dev" , false) ; 
// g. addEdge( "HTML " , "CSS" , false); 
// g. addEdge( "CSS" , "JS", false);
//  g.addEdge(" JS" , "Web Dev" , false); 
// g. addEdge( "Java", "web Dev" , false); 
// g. addEdge( "Python", "Web Dev" , false);


  // cout<<endl;
  // g.printAdjList();


}