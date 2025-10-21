#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdlib>
using namespace std;

/*This Program will have an array of names which we will use to store, edit and delete*/

void clearScreen()
{ // Function to clear the CLI everytime we finish an operation
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

class Names
{
public:
    void removeFromList(vector<string> &names, string &name)
    {
        auto found = find(names.begin(), names.end(), name);
        if (found != names.end())
        {
            names.erase(found);
        }
        else
        {
            cout << "Name not found" << endl;
        }
        return;
    }

    void addToList(vector<string> &names, string &name)
    {
        names.push_back(name);
        return;
    }

    void updateList(vector<string> &names, const string &nameOne, const string &nameTwo)
    {
        for (int i = 0; i < names.size(); i++)
        {
            if (nameOne == names[i])
            {
                names[i] = nameTwo;
            }
        }
        return;
    }
};

int main()
{
    Names listOfNames;
    vector<string> names = {};
    vector<string> ops = {"add", "remove", "update", "quit"};
    while (true)
    {
        string name = "";
        string name2 = "";
        string operation = "";

        if (!names.empty())
        {
            cout << "Current names: " << endl;
            for (int i = 0; i < names.size(); i++)
            {
                cout << names[i];
                if (i < names.size() - 1)
                    cout << ", ";
            }
            cout << endl;
        }

        cout << "Enter an operation (add, remove, update, quit): " << endl;
        cin >> operation;

        if (operation == "add" || operation == "remove")
        {
            cout << "Enter a name: " << endl;
            if (!(cin >> name))
            {
                break;
            }
            if (operation == "add")
            {
                listOfNames.addToList(names, name);
            }
            else if (operation == "remove")
            {
                listOfNames.removeFromList(names, name);
            }
        }

        else if (operation == "update")
        {
            cout << "Enter name to edit, then name to update: " << endl;
            if (!(cin >> name >> name2))
            {
                break;
            }
            listOfNames.updateList(names, name, name2);
        }

        else if (operation == "quit")
        {
            break;
        }

        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "invalid operation, try again" << endl;
        }

        for (int i = 0; i < ops.size(); i++)
        {
            if (operation == ops[i])
            {
                cout << "Current names: " << endl;
                for (const string &str : names)
                {
                    cout << " - " << str << endl;
                }
            }
        }

        cout << "Press ENTER twice to continue" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        clearScreen();
    }

    cout << "Program Terminated" << endl;
    return 0;
}
