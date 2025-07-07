#include<iostream>
#include<vector>

using namespace std;

class DSU
{
    private:
    vector<int> parent;
    vector<int> rank;

    public:

    DSU(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1,1);

        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
        }
    }

    int find(int node)
    {
        if(parent[node]==node) return node;
        //path compression
        return parent[node]=find(parent[node]);
    }


    void union_set(int a,int b)
    {
        int leaderA = find(a);
        int leaderB = find(b);

        if(leaderA!=leaderB)
        {
            if(rank[leaderA]<rank[leaderB])
            {
                parent[leaderA]=leaderB;
                rank[leaderB]+=rank[leaderA];
            }
            else
            {
                parent[leaderB]=leaderA;
                rank[leaderA]+=rank[leaderB];
            }
        }
    }


    void display()
    {
        cout << "Parent Array: ";
        for(int i=1; i<parent.size(); i++)
        {
            cout << parent[i] << " ";
        }
        cout << endl;

        cout << "Rank Array: ";
        for(int i=1; i<rank.size(); i++)
        {
            cout << rank[i] << " ";
        }
        cout << endl;
    }

};

int main()
{

    vector<vector<int>> edges{
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5},
        {1, 5}
        };
        DSU dsu(5);

        for(int i=0;i<edges.size();i++)
        {
            int a,b;
            a=edges[i][0];
            b=edges[i][1];
            cout << "Union of " << a << " and " << b << endl;


            int parentA = dsu.find(a);
            int parentB = dsu.find(b);

            if(parentA != parentB) {
                dsu.union_set(a, b);
                cout << "Union successful: " << parentA << " and " << parentB << " are now connected." << endl;
            } else {
                cout << "Already connected: " << parentA << " and " << parentB << "." << endl;
                cout<<"CYCLE DETECTED FOR NODES "<<a<<" & "<<b<<endl;
            }
        }



    return 0;
}