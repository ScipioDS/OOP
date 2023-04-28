#include <iostream>
#include <cstring>
using namespace std;

class DisciplinaryAction{
private:
    char * name;
    int index;
    char * reason;
    int sessions;
    void copy(const DisciplinaryAction &other){
        //initialisation
        this->name = new char[strlen(other.name)+1];
        this->reason = new char[strlen(other.reason)+1];

        //copy
        strcpy(this->name,other.name);
        strcpy(this->reason,other.reason);

        this->index = other.index;
        this->sessions = other.sessions;
    }
public:
    //default
    DisciplinaryAction(){
        this->name = new char[0];
        this->index = 0;
        this->reason = new char[0];
        this->sessions = 0;
    }

    //argument constructor
    DisciplinaryAction(char * other_name, int other_index, char * other_reason, int other_sessions){
        //initialisation
        this->name = new char[strlen(other_name)+1];
        this->reason = new char[strlen(other_reason)+1];

        //copy
        strcpy(this->name,other_name);
        strcpy(this->reason,other_reason);

        this->index = other_index;
        this->sessions = other_sessions;
    }

    //copy constructor
    DisciplinaryAction(const DisciplinaryAction &other){
        copy(other);
    }

    //destructor
    ~DisciplinaryAction(){
        delete [] this->name;
        delete [] this->reason;
    }

    //set & get index
    void setIndex(int other_index){this->index = other_index;}
    int getIndex(){return this->index;}

    //set & get sessions
    void setSessions(int other_sessions){this->sessions = other_sessions;};
    int getSessions(){return this->sessions;};

    //operator =
    DisciplinaryAction& operator=(const DisciplinaryAction &other){
        if(this != &other){
            delete [] this->name;
            delete [] this->reason;
            copy(other);
        }
        return * this;
    }

    //operator <<
    friend ostream& operator<<(ostream& out, const DisciplinaryAction &other){
        out << "Student: " << other.name << endl;
        out << "Student's index: " << other.index << endl;
        out << "Reason: " << other.reason << endl;
        out << "Sessions: " << other.sessions << endl;
        return out;
    }

    //operator ++
    DisciplinaryAction& operator++(){
        this->sessions++;
        return * this;
    }

    //operator >=
    bool operator>=(const DisciplinaryAction &other) const {
        if (sessions >= other.sessions) {
            return true;
        }
        else {
            return false;
        }
    }


};

int main() {
    int n;
    cin >> n;

    /// Testing Default constructor and equal operator
    /// Array input

    DisciplinaryAction arr[n];

    for (int i = 0; i < n; i++) {
        char name[100];
        char reason[100];
        int index;
        int sessions;

        cin >> name >> index >> reason >> sessions;

        arr[i] = DisciplinaryAction(name, index, reason, sessions);
    }

    cout << "-- Testing operator = & operator <<  --\n";
    cout << arr[0];

    /// Testing copy constructor & set index

    DisciplinaryAction merka(arr[0]);
    merka.setIndex(112233);

    cout << "\n-- Testing copy constructor & set index --\n";
    cout << "-------------\n";
    cout << "Source:\n";
    cout << "-------------\n";
    cout << arr[0];

    cout << "\n-------------\n";
    cout << "Copied and edited:\n";
    cout << "-------------\n";
    cout << merka;

    /// Testing if array is OK

    cout << "\n-- Testing if array was inputted correctly --\n";

    for (int i = 0; i < n; i++)
        cout << arr[i];


    cout << "\nTesting operator ++ and <<" << endl;
    for (int i = 0; i < n; i++)
        cout << (++arr[i]);


    cout << "\nTesting operator >=" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                cout << i << " " << ((arr[i] >= arr[j]) ? ">= " : "< ") << j << endl;
            }
        }
    }

    return 0;
}