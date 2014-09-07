#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>//for exit()
#include <algorithm>//for sort()
#include "grocerylist.h"//interface file

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

void menu(vector<Items>&groceries);
//main menu function that either adds item, removes item, displays list, or exits function
void subMenu(vector<Items>&groceries);
//menu used when adding new item to list
int main()
{
    vector<Items>groceries;
    cout << "Welcome to Your Virtual Grocery List!\n";

    menu(groceries);

    return 0;
}
int Items::setLocation(int zone)
{
    location = zone;
    return location;
}
string Items::setName(string name)
{
    item = name;
    return item;
}
double Items::setPrice(double cost)
{
    price = cost;
    return price;
}
//overloads the less-than operator in order to use sort()
bool Items::operator <(const Items& product) const//reference:http://stackoverflow.com/questions/1380463/sorting-a-vector-of-custom-objects
{
    return (location < product.location);
}
void Items::display(vector<Items>groceries)
{
    for(int i=0;i<groceries.size();i++)
    {
        cout << groceries.at(i).item << "\t\t" << "$" << groceries.at(i).price << endl;
    }
}
void Items::altdisplay(vector<Items>groceries)
{
    cout << item << endl;
}
void menu(vector<Items>&groceries)
{
    int choice, num;
    string name;
    Items product;

    cout << "\nPlease select from the following options:\n";
    cout << "1. Add item to grocery list\n";
    cout << "2. Remove item from grocery list\n";
    cout << "3. Display items in grocery list based on their location in the store\n";
    cout << "4. Exit\n";
    do
    {
        cin >> choice;
        while(cin.fail() || isalpha(choice))
        {
            cout << "Invalid entry!\n";
            cin.clear();
            cin.ignore(255, '\n');
            cin >> choice;
        }
        switch(choice)
        {
        case 1:
            subMenu(groceries);
            menu(groceries);
            break;
        case 2:
            if(groceries.size() == 0)//if no items in list goes right back to menu
            {
                cout << "There are no items in the list to delete!\n";
                menu(groceries);
            }
            for(int i=0;i<groceries.size();i++)
            {
                cout << i+1 << ". ";
                groceries[i].altdisplay(groceries);
            }
            cout << "Enter the number of the item you'd like to delete or 0 to go back to Main Menu\n";
            cin >> num;
            while(cin.fail() || num > groceries.size() || num < 0)
            {
                cout << "Invalid Entry!\n";
                cin.clear();
                cin.ignore(255, '\n');
                cin >> num;
            }
            if(num == 0)
            {
                menu(groceries);
            }
            else
            {
                groceries.erase(groceries.begin()+(num-1));//erases item that is num-1 indices away from the beginning of the vector
                menu(groceries);                           //num-1 is needed to make-up for the fact that the first index starts at 0
            }
            break;
        case 3:
            std::sort(groceries.begin(), groceries.end());//sorts vector from smallest to largest location before being displayed
            product.display(groceries);
            menu(groceries);
            break;
        case 4:
            exit(1);
            break;
        default:
            cout << "Invalid Entry!\n";
        }
    }while(choice != 4);
}
void subMenu(vector<Items>&groceries)
{
    string name;
    int zone;
    Items product;

    while(zone != -1)
    {
        cout << "\nEnter the zone for where that item is located based on the following:\n";
        cout << "Zone 1: Produce  Zone 2: Bakery  Zone 3: Freezer  Zone 4: Refrigerator\n";
        cout << "Zone 5: Butcher  Zone 6: Seafood  Zone 7: Deli  Zone 8: Aisle\n";
        cout << "Enter -1 to exit.\n";
        cin >> zone;
        product.setLocation(zone);
        while(cin.fail() || isalpha(zone) || zone < -1 || zone > 8)
        {
            cout << "Invalid entry!\n";
            cin.clear();
            cin.ignore(255, '\n');
            cin >> zone;
        }
        if(zone != -1)
        {
            cout << "\nEnter your grocery items one at a time.\n";
            cin >> name;
            product.setName(name);
            product.setPrice(9.99);
            groceries.push_back(product);//adds item to end of vector
        }
    }
}

