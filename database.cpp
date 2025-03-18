#include<iostream>
#include<string>
#include<limits>
#include<iomanip>
#include<conio.h>
#define FIELD_COUNT 12
using namespace std;
// author @Ajaysvasan
// Defining an array for the fields to make some process easier 
string fields[] = {"name","dept","rollNumber","regNo","age","phoneNumber","bloodGroup","address","type","boardingPoint","classSec","year"};

// creating a database 

class createDatabase{
    private:
    string name, Dept, rollnumber, bloodGroup, address, type, boardingPoint, classSec, phoneNumber,year;
    int regNo, age;
    public:
        createDatabase *next;
        createDatabase *prev;
        createDatabase(string name,string Dept,string rollnumber,int regNo,int age,string phoneNumber,string bloodGroup,string address,string type,string boardingPoint,string classSec,string year){
            this->name = name;
            this->Dept = Dept;
            this->rollnumber = rollnumber;
            this->regNo = regNo;
            this->age = age;
            this->phoneNumber = phoneNumber;
            this->bloodGroup = bloodGroup;
            this->address = address;
            this->type = type;
            this->boardingPoint = boardingPoint;
            this->classSec = classSec;
            this->year = year;
            next = nullptr;
            prev = nullptr;
        }
        // functions for retriving the informations 
        string getName(){return this->name;}
        string getDept(){return this->Dept;}
        string getRollNumber(){return this->rollnumber;}
        int getRegNo(){return this->regNo;}
        int getAge(){return this->age;}
        string getPhoneNumber(){return this->phoneNumber;}
        string getBloodGroup(){return this->bloodGroup;}
        string getType(){return this->type;}
        string getAddress(){return this->address;}
        string getBoardingPoint(){return this->boardingPoint;}
        string getClassSec(){return this->classSec;}
        string getYear(){return this->year;}

        // functions to update the informations
        void updateName(string name){ this->name=name;}
        void updateDept(string dept){ this->Dept=dept;}
        void updateRollNumber(string rollNo){ this->rollnumber=rollNo;}
        void updateRegNo(int regNo){this->regNo = regNo;}
        void updateAge(int age){this->age= age;}
        void updatePhoneNumber(string phoneNumber){this->phoneNumber = phoneNumber;}
        void updateBloodGroup(string bloodGroup){this->bloodGroup = bloodGroup;}
        void updateAddress(string address){this->address = address;}
        void updateType(string type){this->type = type;}
        void updateBoardingPoint(string boardingPoint){this->boardingPoint = boardingPoint;}
        void updateClassSec(string classSec){this->classSec = classSec;}
        void updateYear(string year){ this->year = year;}
};

// creating doubly linked list to store values for multiple students

class Database{
    private:
        createDatabase *head;
        private:

    // Function to split a doubly linked list into two halves
    createDatabase* split(createDatabase* head) {
        createDatabase* slow = head;
        createDatabase* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        createDatabase* secondHalf = slow->next;
        slow->next = nullptr; // Split the list
        if (secondHalf) secondHalf->prev = nullptr;

        return secondHalf;
    }
    createDatabase* merge(createDatabase* first, createDatabase* second) {
        // Base cases
        if (!first) return second;
        if (!second) return first;

        if (first->getRegNo() <= second->getRegNo()) {
            first->next = merge(first->next, second);
            if (first->next) first->next->prev = first;
            first->prev = nullptr;
            return first;
        } else {
            second->next = merge(first, second->next);
            if (second->next) second->next->prev = second;
            second->prev = nullptr;
            return second;
        }
    }
    createDatabase* mergeSort(createDatabase* node) {
        if (!node || !node->next) return node; // Base case: single node or empty list

        // Split the list into two halves
        createDatabase* secondHalf = split(node);

        // Recursively sort each half
        createDatabase* left = mergeSort(node);
        createDatabase* right = mergeSort(secondHalf);

        // Merge the sorted halves
        return merge(left, right);
    }

    public:
        Database():head(nullptr){}
        void addStudents(string name,string Dept,string rollnumber,int regNo,int age,string phoneNumber,string bloodGroup,string address,string type,string boardingPoint,string classSec,string year){
            createDatabase *newValue = new createDatabase(name, Dept, rollnumber, regNo, age, phoneNumber, bloodGroup, address, type, boardingPoint,classSec,year);
            if (head==nullptr){
                head = newValue;
            }
            else{
                createDatabase * temp = head;
                while(temp->next!=nullptr){
                    temp=temp->next;
                }
                newValue->prev = temp;
                temp->next = newValue;
            }
            // cout<<"Node has been inserted";
        }
                void display() {
            createDatabase* temp = head;
            
            // Print the header row (field names)
            cout << left;
            for (int i = 0; i < FIELD_COUNT; ++i) {
                cout << setw(20) << fields[i];
            }
            cout << endl;

            // Print a separator line
            for (int i = 0; i < FIELD_COUNT; ++i) {
                cout << setw(20) << "--------------------";
            }
            cout << endl;

            // Print each student's data
            while (temp != nullptr) {
                cout << setw(20) << temp->getName();
                cout << setw(20) << temp->getDept();
                cout << setw(20) << temp->getRollNumber();
                cout << setw(20) << temp->getRegNo();
                cout << setw(20) << temp->getAge();
                cout << setw(20) << temp->getPhoneNumber();
                cout << setw(20) << temp->getBloodGroup();
                cout << setw(20) << temp->getAddress();
                cout << setw(20) << temp->getType();
                cout << setw(20) << temp->getBoardingPoint();
                cout << setw(20) << temp->getClassSec();
                cout << endl;
                temp = temp->next;
            }
        }

        void sortDatabase() {
            head = mergeSort(head);
            cout << "\nDatabase sorted successfully by Registration Number (ascending order).\n";
            }
        void update(int regNo,string field){
            createDatabase *temp = head;
            while(temp!=nullptr){
                if(temp->getRegNo()==regNo){
                }
            }
        }
};

int main() {
    Database db;

    string name, Dept, rollnumber, bloodGroup, address, type, boardingPoint, classSec, phoneNumber,year;
    int regNo, age;
    bool exit = true;
    char choice;

    while (exit) {
        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Department: ";
        getline(cin, Dept);

        cout << "Enter Roll Number: ";
        getline(cin, rollnumber);

        cout<<"Enter Year: ";
        getline(cin,year);

        cout<< "Enter Registration Number: ";
        while (!(cin >> regNo)) {
            cout << "Invalid input. Please enter a numeric value for Registration Number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Age: ";
        while (!(cin >> age)) {
            cout << "Invalid input. Please enter a numeric value for Age: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Phone Number: ";
        getline(cin, phoneNumber);

        cout << "Enter Blood Group: ";
        getline(cin, bloodGroup);

        cout << "Enter Address: ";
        getline(cin, address);

        cout << "Enter Type: ";
        getline(cin, type);

        if (type == "d" || type == "D") {
            cout << "Enter Boarding Point: ";
            getline(cin, boardingPoint);
        }

        cout << "Enter Class Section: ";
        getline(cin, classSec);
        db.addStudents(name, Dept, rollnumber, regNo, age, phoneNumber, bloodGroup, address, type, boardingPoint, classSec,year);
        cout << "\nStudent added successfully.\n";

        db.sortDatabase();

        cout << "\nDo you want to continue adding students (y/n)? ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');


        if (choice != 'y' && choice != 'Y') {
            exit = false;
        }
    }

    db.display();
    cin.get();

    return 0;
}