//basics of Hashing & graphs

#include<bits/stdc++.h>
using namespace std;

// hashmap allows u to insert of type key & values
//hashmap basics

/*
int main(){
    map<string,int> hash_table;         //declaration
    string a,b,c;
    cin>>a>>b>>c;                       //input strings
    int aa,bb,cc;
    cin>>aa>>bb>>cc;                    //input their marks/anything
    hash_table[a]=aa;                    //assign values
    hash_table[b]=bb;
    hash_table[c]=cc;

    string w,y,x,z;
    cin>>w>>x>>y>>z;
    if(hash_table[w]){
        cout<<"Marks of : "<<w<<" "<<hash_table[w]<<endl;
    }
    else{
        cout<<"NO marks for "<<w<<endl;
    }
    
    if(hash_table[x]){
        cout<<"Marks of : "<<x<<" "<<hash_table[x]<<endl;
    }
    else{
        cout<<"NO marks for "<<x<<endl;
    }
    if(hash_table[y]){
        cout<<"Marks of : "<<y<<" "<<hash_table[y]<<endl;
    }
    else{
        cout<<"NO marks for "<<y<<endl;
    }

    if(hash_table[z]){
        cout<<"Marks of : "<<z<<" "<<hash_table[z]<<endl;
    }
    else{
        cout<<"NO marks for "<<z<<endl;
    }

}
*/

//GRAPH
//implementation of graphs 
//adjacency matrix=>2D matrix, with 1 & 0 on it
//adjacency list=> most efficeint=> 0->1,4 & 1->2,3,4,0
//Edge list=> {(a,b),(a,c),(a,d)}

//using adjacency list
//in adjacency list, we want list of array
/*
class Graph{
    int V;                          //private
    list<int> *l;                   //list
public:
    Graph(int v){
        V = v;
        //array of linkedlist
        l = new list<int>[V];
    }

    void AddEdge(int u, int v, bool bidir=true){       //edge u & v
        l[u].push_back(v);
        if(bidir){
            l[v].push_back(u);
        }
    }


    void printList(){
        for(int i=0; i<V ;i++){             //V is no of vertices
            cout<<i<<"->";
            //l[i] is linkedlist
            for(int vertex : l[i]){  
                cout<<vertex<<",";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g(5);                  //making object of graph, with 5 vertices
    g.AddEdge(0,1);
    g.AddEdge(0,4);
    g.AddEdge(4,3);
    g.AddEdge(1,4);
    g.AddEdge(1,2);
    g.AddEdge(2,3);
    g.AddEdge(1,3);

    g.printList();              //printing graph 
}
*/

//graph traversals => to discover all the nodes
//Graph implementation using hashmap

template<typename T>
class Graph{
    map<T, list<T> > adjlist;

public:
    Graph(){

    }
    void AddEdge(T u, T v, bool bidir=true){
        adjlist[u].push_back(v);
        if(bidir){
            adjlist[v].push_back(u);
        }
    }

    void print(){
        for(auto i:adjlist){                //auto will take automatically data type
            cout<<i.first<<"->";

            //i.second is LL
            for(auto entry:i.second){
                cout<<entry<<",";
            }
            cout<<endl;
        }

    }

    //shortest path bfs traversal
    void shortestPath(T src){           //T is template => SOURCE NODE
        queue<T> q;
        //take hashmap for visited 
        map<T, int> dist;
        map<T, T> parent;
        for(auto i:adjlist){
            dist[i.first] = INT_MAX;            //all distances are infinity at begening
        }
        
        q.push(src);
        dist[src] = 0;        
        parent[src] = src;

        while(!q.empty()){
            T node = q.front();             
            cout<<node<<" ";
            q.pop();

            for(int neighbour : adjlist[node]){
                if(dist[neighbour]==INT_MAX){
                    q.push(neighbour);
                    dist[neighbour] = dist[node] + 1;
                    parent[neighbour] = node;
                }
            }
        }
        //print the distances to all the nodes
        for(auto i:adjlist){
            T node = i.first;
            cout<<"Dist of "<<node<<" from "<<src<<" is "<<dist[node]<<endl;
        }
    }

void bfsTraversal(T src){           //T is template => SOURCE NODE
        queue<T> q;
        //take hashmap for visited 
        map<T, bool> visited;
        q.push(src);
        visited[src] = true;        //mark src node as visited 

        while(!q.empty()){
            T node = q.front();             //take a new variable, name as node, 
                                            //point karao usko to the front and then pop it
            cout<<node<<" ";
            q.pop();

            //for the neightbour of this node, find nodes(childrens) which are not visited
            for(int neighbour : adjlist[node]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }

};

int main(){
    // Graph<string> g1;                  //making object of graph of type string
    // g1.AddEdge("putin","trump",false);
    // g1.AddEdge("putin","modi",false);
    // g1.AddEdge("putin","pope",false);
    // g1.AddEdge("modi","trump",true);
    // g1.AddEdge("modi","rahul",true);
    // g1.AddEdge("rahul","prabhu",false);
    // g1.AddEdge("prabhu","modi",false);
    // g1.print();              //printing graph 
    
    // cout<<endl;

    Graph<int> g2;                      //making object of graph of type int
    g2.AddEdge(0,1);
    g2.AddEdge(1,2);
    g2.AddEdge(0,4);
    g2.AddEdge(2,4);
    g2.AddEdge(2,3);
    g2.AddEdge(3,5);
    g2.AddEdge(3,4);
    g2.print();
    cout<<endl;
    cout<<"BFS TRAVERSAL : ";
    g2.bfsTraversal(0);
    cout<<endl;
    
    g2.shortestPath(0);
    cout<<endl;
}

