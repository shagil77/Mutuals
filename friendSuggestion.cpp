#include<bits/stdc++.h>
using namespace std;

class WeightedUndirectedGraph
{
    int N;
    vector<pair<int,int>> *adj;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    public:
    int *distTo;
    WeightedUndirectedGraph(int n)
    {
        N = n;
        adj = new vector<pair<int,int>>[N+1];
        distTo = new int[N+1];
        for(int i = 0; i<=N; i++)
        {
            distTo[i] = INT_MAX;
        }
    }
    void addEdge(int u, int v, int wt)
    {
        adj[u].push_back(make_pair(v, wt));
        adj[v].push_back(make_pair(u, wt));
    }
    void DijkstraShortestPath(int s)
    {
        distTo[s] = 0;
        pq.push(make_pair(0, s));

        while(!pq.empty())
        {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            for(auto it: adj[node])
            {
                int nextNode = it.first;
                int nextDist = it.second;
                if(distTo[nextNode]>dist + nextDist)
                {
                    distTo[nextNode] = dist + nextDist;
                    pq.push(make_pair(distTo[nextNode], nextNode));
                }
            }
        }
    }
    void BFS(int s, string name[])
    {
        int friends = adj[s].size();
        bool *visited = new bool[N+1];
        for(int i = 0; i <= N; i++)
            visited[i] = false;

        queue<int> q;

        // Mark the current node as visited and enqueue it
        visited[s] = true;
        q.push(s);

        // 'i' will be used to get all adjacent
        // vertices of a vertex
        vector<pair<int,int>>::iterator i;

        while(!q.empty())
        {
            // Dequeue a vertex from queue and print it
            int node = q.front();
            q.pop();
            if(friends<0)
            {
                cout << name[node] << " ";
            }
            else
            {
                friends--;
            }
            
            

            // Get all adjacent vertices of the dequeued
            // vertex s. If a adjacent has not been visited,
            // then mark it visited and enqueue it
            for (i = adj[node].begin(); i != adj[node].end(); i++)
            {
                if (!visited[i->first])
                {
                    visited[i->first] = true;
                    q.push(i->first);
                }
            }
        }
    }
    /*void DFS(int s)
    {
        bool *explored = new bool[N+1];
        for(int i = 0; i <= N; i++)
            explored[i] = false;

        stack<int> st;

        // Mark the current node as visited and push it into stack
        explored[s] = true;
        st.push(s);

        // 'i' will be used to get all adjacent
        // vertices of a vertex
        vector<int>::iterator i;

        while(!st.empty())
        {
            // Pop a vertex from stack and print it
            int node = st.top();
            st.pop();
            cout << node << " ";

            // Get all adjacent vertices of the destacked
            // vertex s. If a adjacent has not been visited,
            // then mark it visited and enstack it
            for (i = adj[node].begin(); i != adj[node].end(); i++)
            {
                if (!explored[*i])
                {
                    explored[*i] = true;
                    st.push(*i);
                }
            }
        }
    }*/
};

int main()
{
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    cout<<endl;

    WeightedUndirectedGraph fb(n);
    string name[n+1];
    name[0]="";

    cout<<"Enter the name of the users: \n";
    cin.clear();
    cin.sync();

    for(int i=1; i<=n; i++)
    {
        getline(cin, name[i]);
    }
    cout<<endl;

    for(int i=1; i<=n; i++)
    {
        cout<<i<<": "<<name[i]<<endl;
    }

    cout<<"\nEnter the edges and edge weights(u,v,wt): \n";
    while(true)
    {
        int u, v, wt;
        cin>>u>>v>>wt;
        if(u==-1)
        {
            break;
        }
        else
        {
            fb.addEdge(u,v,wt);
        }
    }

    cout<<"\nNode of the person whose friend suggestion is required: ";
    int node;
    cin>>node;

    cout<<"\nFriend Suggestion:\n";
    fb.BFS(node, name);
    fb.DijkstraShortestPath(node);

    cout<<"\n\nShortest Distance to all other user's location:\n";
    for(int i=1; i<=n; i++)
    {
        if(i==node)
        {
            continue;
        }
        else
        {
            cout<<name[i]<<"\t"<<fb.distTo[i]<<endl;
        }
    }
    return 0;
}