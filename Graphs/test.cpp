#include<bits/stdc++.h>

using namespace std;

template<typename T>
class Graph{

	map<T,vector<T>> adjList;

public:
	Graph()
	{
		
	}

	void addEdge(T u, T v, bool bidir=true)
	{
		adjList[u].push_back(v);
		if(bidir==true)
			adjList[v].push_back(u);
	}

	void printAdjList()
	{
		for(auto i : adjList)
		{
			cout<<i.first<<"->";
			for(auto vertex : i.second)
				cout<<vertex<<",";
			cout<<endl;
		}
	}

	void bfsPrint(T src)
	{
		map<T,bool> visited;
		queue<int> q;

		//ENTER START ELEMENT
		q.push(src);
		visited[src] = true;

		while(!q.empty())
		{
			T node = q.front();
			cout<<node<<" ";
			q.pop();

			for(T i:adjList[node])
			{
				if(visited[i]==0)
					{
						q.push(i);
						visited[i] = true;
					}
			}
		}

	}

	int sssp(T src, T dest)
	{
		map<T,bool> visited;
		map<T,int> distance;
		queue<T> q;

		//ENTER START ELEMENT
		q.push(src);
		visited[src] = true;
		distance[src] = 0;

		while(q.front()!=dest)
		{
			T node = q.front();
			q.pop();

			for(T i:adjList[node])
			{
				if(visited[i]==0)
					{
						q.push(i);
						visited[i] = true;
						distance[i] = distance[node] + 1;
						cout<<"Distance of "<<i<<" from node "<<node<<" is "<<distance[i]<<endl;
					}
			}
		}

		return distance[dest];
	}

	void dfs(T src)
	{
		map<T,bool> visited;
		dfsPrint(src,visited);

		for(auto i : adjList)
		{
			if(visited[i.first] == false)
				{
					cout<<endl<<"Connected DFS"<<endl;
					visited[i.first] = true;
					dfsPrint(i.first,visited);
				}
		}

	}

	void dfsPrint(T src, map<T,bool> &visited)
	{
		visited[src] = true;
		cout<<src<<" ";

		for(T vertex:adjList[src])
		{
			if(!visited[vertex])
			{
				visited[vertex] = true;
				dfsPrint(vertex,visited);
			}
		}

	}

	void dfsTSHelper(T src, map<T,bool>& visited, stack<T>& stack)
	{
		visited[src] = true;
		for(T vertex:adjList[src])
		{
			if(!visited[vertex])
			{
				visited[vertex] = true;
				dfsTSHelper(vertex,visited,stack);			
			}
		}

		stack.push(src);
	}

	void dfsTopologicalSort()
	{
		map<T,bool> visited;
		stack<T> stack;

		for(auto i : adjList)
		{
			T node = i.first;
			if(!visited[node])
			{
					dfsTSHelper(node,visited,stack);
			}
		}

		while(!stack.empty())
		{
			cout<<stack.top()<<" ";
			stack.pop();
		}

	}

	bool bfsCycleDetection()
	{
		map<T,bool> visited;
		map<T,T> parent;


		for(auto i:adjList)
		{
			T node = i.first;
			for(auto vertex:adjList[node])
			{
				//Apne baap ko tag thodi karunga
				//Skip karke doosre ko tag karta hu
				if(vertex == parent[node])
				{
					continue;
				}
				if(!visited[vertex])
				{
					visited[vertex] = true;
					parent[vertex] = node;
				}
				else
				{
					cout<<"Cycle from "<<node<<" to "<<vertex;
					return true;
				}
			}
		}
		return false;
	}

	bool dfsDCDHelper(T src, map<T,bool>& visited, map<T,bool>& stack)
	{
		visited[src] = true;
		stack[src] = true;

		for(auto i : adjList[src])
		{
			if(!visited[i])
			{
				visited[i] = true;
				stack.push(i);
			}

			if(stack[i]==true)
				return false;
		}

		return true;
	}

	bool dfsDirectedCycleDetection()
	{
		map<T,bool> visited;
		map<T,bool> stack;

		for(auto i : adjList)
		{
			T node = i.first;
			for(auto vertex: adjList[i])
			{
				if(!visited[vertex])
					dfsDCDHelper(vertex,visited,stack);
			}
		}
	}

};

int main()
{
	#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);

  freopen("output.txt","w",stdout);
  #endif

  cout<<"YOLO"<<endl;

  Graph<int> g;

  // g.addEdge(0,1);
  // g.addEdge(1,2);
  // g.addEdge(0,4);
  // g.addEdge(2,4);
  // g.addEdge(2,3);
  // g.addEdge(3,5);
  // g.addEdge(3,4);

  g.addEdge(0,1);
  g.addEdge(1,2);
  g.addEdge(2,3);
  g.addEdge(3,4);
  g.addEdge(4,0);



  // g.addEdge("P","Q");
  // g.addEdge("Q","R");
  // g.addEdge("R","S");
  // g.addEdge("S","Q");

  // g.addEdge("K","O");

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
  // cout<<endl;
  // cout<<"BFS"<<endl;
  // g.bfsPrint(0);
  // cout<<"sssp"<<endl<<g.sssp(3,5);

  // g.dfsTopologicalSort();

  cout<<g.bfsCycleDetection();


}