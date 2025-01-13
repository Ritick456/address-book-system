#include<iostream>
using namespace std;

class Contact{
    public:
    string firstname;
    string lastname;
    string address;
    string city;
    string email;
    string state;
    string zip;
    string phonenumber;

    Contact(string firstname, string lastname, string address, string city, string state, string zip, string phonenumber, string email){
        this->firstname = firstname;
        this->lastname = lastname;
        this->address = address;
        this->city = city;
        this->state = state;
        this->zip = zip;
        this->phonenumber = phonenumber;
        this->email = email;
    }
};

int main(){

    cout << "Welcome to Address Book Program in AddressBookMain class on Master Branch" << endl;

    return 0;
}