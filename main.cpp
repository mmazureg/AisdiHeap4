#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename KeyType, typename ValueType>
class Heap4{
public:
using KeyValueType = std::pair<KeyType, ValueType>;

bool isEmpty() const
{return tab.empty();}


void insert(KeyType const& key, ValueType const& value)
{
	KeyValueType temp(key,value);
	tab.push_back(temp);

	int i = tab.size() - 1;

	while(tab[i].first > tab[parent(i)].first && i > 0)
	{
		swap(tab[i], tab[(i-1)/4]); // const key????
		i = (i-1)/4;
	}

}

void insert(KeyValueType const& key_value)
{
	tab.push_back(key_value);
	int i = tab.size() - 1;
	while(tab[i].first > tab[parent(i)].first && i > 0)
	{
		swap(tab[i], tab[(i-1)/4]);
		i = (i-1)/4;
	}


	}

KeyValueType const& peek() const //co w korzeniu bez usuwania
{return tab[0];}

KeyValueType pop()
{
    if(isEmpty())
        return make_pair(-1,-1);

    KeyValueType temp(tab[0]);

    tab[0] = tab[tab.size() - 1];
    tab.pop_back();

    int maxchild = 0;
    int j = 1; int i=0;

    while(j<5)
    {
        if(tab[4*i + j].first > tab[i].first)
            maxchild = 4*i + j;

        j++;
    }
    if(tab[i].first< tab[maxchild].first)
        {swap(tab[i], tab[maxchild]);}

    while(true)
    {
        int j = 1;
        int i = maxchild;

        while(j<5)
        {
            if(tab[4*i + j].first > tab[i].first)
                maxchild = 4*i + j;

            j++;
        }

        if(tab[i].first< tab[maxchild].first)
            {swap(tab[i], tab[maxchild]);}
         else
                break;

    }

    return temp;

}

size_t size() const
{
	return tab.size();
}

//void print(std::ostream& stream) const

int parent(int index)
{ return (index - 1)/4; }



private:

std::vector<KeyValueType> tab;

};

int main()
{
    Heap4<int,int>testHeap;
    for(int i = 9; i>0; i--)
    {
        testHeap.insert(i, 3*i);
        std::cout<<testHeap.peek().first<< endl;
    }

    cout << testHeap.pop().first << endl;
    cout << testHeap.peek().first  << endl;
    return 0;
}
