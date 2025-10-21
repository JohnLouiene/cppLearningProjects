#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*This Program will have an array of names which we will use to store, edit and delete*/

class Names{
    public:
    vector<string> removeFromList(vector<string>& names, string& name){
        auto found = find(names.begin(), names.end(), name);
        if (found != names.end()){
            names.erase(found);
        }
        else{
            cout << "Element not found" << endl;
        }
        return names;
    }

    vector<string> addToList(vector<string>& names, string& name){
        names.push_back(name);
        return names;
    }
};

int main(){
    Names listOfNames;
    vector<string> names = {};
    while (true){
        string name = "";
        string operation = "";
        cout << "Enter a name and operation (add, remove, quit): " << endl;
        if (!(cin >> name >> operation)){
            break;
        }
        if (operation == "quit") break;
        if (operation == "add"){
            listOfNames.addToList(names, name);
        }
        else if (operation == "remove"){
            listOfNames.removeFromList(names, name);
        }
        else{
            cout << "Invalid Operation: " << endl;
            break;
        }

        cout << "Current names: " << endl;
        for (const string& str : names){
            cout << " - " << str << endl;
        }

        cout << "Press ENTER to continue" << endl;
        cin.ignore();
        cin.get();
    }

    cout << "Program Terminated" << endl;
    return 0;
}