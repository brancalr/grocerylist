#ifndef GROCERYLIST_H_INCLUDED
#define GROCERYLIST_H_INCLUDED

using std::string;
using std::vector;

class Items
{
public:
    Items():itemType(){};//default constructor
    int setLocation(int zone);
    string setName(string name);
    double setPrice(double cost);
    double setSalePrice(double sale);
    bool operator <(const Items& product) const;//overloads less-than in order to use sort()
    void display(vector<Items>groceries);
    void altdisplay(vector<Items>groceries);
private:
    string itemType, item;
    int location;
    double price, salePrice;
};


#endif // GROCERYLIST_H_INCLUDED
