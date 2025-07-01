#include<iostream>
#include<vector>
#include<string>
#include<ostream>

using namespace std;

class watch
{
private:
    string name;
    int cost;

public:
    string getName() const { return name; }
    int getCost() const { return cost; }
    void setName(string name) { this->name = name; }
    void setCost(int cost) { this->cost = cost; }
    watch(string name, int cost)
    {
        this->name = name;
        this->cost = cost;
    }

    bool operator==(const watch &w) const
    {
        return this->name==w.name;
    }
};

ostream& operator<<(ostream& COUT, watch& w)
{
    COUT << "Name = " << w.getName() << endl;
    COUT << "Cost = " << w.getCost() << endl;
    return COUT;
}

class WatchCollection
{
private:
    vector<watch> vtr;

public:
    WatchCollection() {}

    int getSize()
    {
        return vtr.size();
    }

    watch& getAt(int index)
    {
        return vtr[index];
    }

    void operator+=(watch& w)
    {
        vtr.push_back(w);
    }

    void operator-=(watch &w)
    {
        auto itr = find(vtr.begin(),vtr.end(),w);
        if(itr!=vtr.end()) vtr.erase(itr);
    }
};

ostream& operator<<(ostream& COUT, WatchCollection& wc)
{
    for (int i = 0; i < wc.getSize(); i++)
    {
        COUT << wc.getAt(i) << endl;
    }
    return COUT;
}

int main()
{
    watch w1("Rolex", 5000);
    watch w2("Omega", 3000);

    WatchCollection wc;
    cout<<endl;
    cout<<"Watch Collection :"<<endl;
    wc += w1;
    wc += w2;
    cout << wc << endl;


    wc -= w2;
    cout<<endl;
    cout<<"Watch Collection :"<<endl;
    cout<<"Updated List"<<endl;
    cout << wc << endl;

    return 0;
}






/*

Sample Excercise


#include<iostream>
#include<vector>
#include<string>
#include<ostream>

using namespace std;

class watch
{
    private:
    string name;
    int cost;

    public:

    watch(string watchName, int cost)
    {
        this->name = watchName;
        this->cost=cost;
    }

    void setName(string newWatchName)
    {
        this->name = newWatchName;
    }


    bool operator==(const watch &w) const
    {
        return this->name==w.name;
    }

    string getName(){return name;}
    int getCost(){return cost;}
    
};

ostream& operator<<(ostream& COUT, watch &w)
{
    COUT<<"Watch Name : "<<w.getName()<<endl;
    COUT<<"Watch Cost : $"<<w.getCost()<<endl;
    return COUT;
}

class watchCollection
{
    private:
    vector<watch> collection;

    public:

    watchCollection()
    {
        collection.clear();
    }

    watchCollection& operator+=(const watch &w)
    {
        collection.push_back(w);
        return (*this);
    }

    int getSize() const
    {
        return collection.size();
    }

    watch& getAt(int index)
    {
        return collection[index];
    }

    watchCollection& operator-=(watch &w)
    {
        auto itr = find(collection.begin(),collection.end(),w);

        if(itr!=collection.end())
        {
            collection.erase(itr);
        }

        return *this;
    }

  

};

ostream& operator<<(ostream& COUT, watchCollection& wc)
{
    COUT<<"Total Waltches in Collection : "<<wc.getSize()<<endl;
    if(wc.getSize() == 0)
    {
        COUT<<"No watches in the collection."<<endl;
        return COUT;
    }
    COUT<<"Watch Collection Details : "<<endl;
    for(int i=0;i<wc.getSize();i++)
    {
        COUT<<wc.getAt(i)<<endl;
    }

    return COUT;
}



int main()
{

    watch *w1 = new watch("ORIS",1000);
    cout<<(*w1)<<endl;
    
    watch w2("IWC",2000);

    watchCollection *wc = new watchCollection();

    ((*wc)+=(*w1))+=(w2);

    cout<<(*wc)<<endl;

    ((*wc)-=w2)-=(*w1);
    cout<<(*wc)<<endl;

    delete w1;
    delete wc;



    
};




*/