#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

struct Customer {
    string firstName;
    string lastName;
    string fatherName;
    int age;
    string phnNo;
    string email;
    string dateOfBirth;
    string address;
};

struct CustomerCNIC {
    string CNIC_Name;
    string CNIC_Number;
    string CNIC_issueDate;
    string CNIC_expiryDate;
    string CNIC_address;
};

void writeToFile(const Customer& user, const CustomerCNIC& userCNIC) {
    ofstream file("user_info.txt", ios::app);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
    file << "******** User Info ********\n";
    file << "Name: " << user.firstName << " " << user.lastName << endl;
    file << "Father's Name: " << user.fatherName << endl;
    file << "Age: " << user.age << endl;
    file << "Phone Number: " << user.phnNo << endl;
    file << "Email: " << user.email << endl;
    file << "Date of Birth: " << user.dateOfBirth << endl;
    file << "Address: " << user.address << endl;
    file << endl;
    file << endl;
    file << "CNIC Name: " << userCNIC.CNIC_Name << endl;
    file << "CNIC Number: " << userCNIC.CNIC_Number << endl;
    file << "CNIC Issue Date: " << userCNIC.CNIC_issueDate << endl;
    file << "CNIC Expiry Date: " << userCNIC.CNIC_expiryDate << endl;
    file << "CNIC Address: " << userCNIC.CNIC_address << endl;
    file << "****************************\n\n";
    file.close();
}

void customerDetails(Customer& user) {
    cout << "\nEnter Your First Name: ";
    cin >> user.firstName;

    cout << "Enter Your Last Name: ";
    cin >> user.lastName;

    cout << "Enter Your Father Name: ";
    cin.ignore();
    getline(cin, user.fatherName);

    cout << "Enter Your Age: ";
    cin >> user.age;
    if (user.age < 18) {
        cout << "You are younger than 18. You are not eligible to open a bank account.";
        exit(0);
    }

    cout << "Enter Your Phone Number: ";
    cin >> user.phnNo;

    cout << "Enter Your Email Address: ";
    cin >> user.email;

    cout << "Enter Your Date Of Birth: ";
    cin.ignore();
    getline(cin, user.dateOfBirth);

    cout << "Enter Your Address: ";
    getline(cin, user.address);
}

void customerCNICdetails(CustomerCNIC& userCNIC) {
    cout << "\nEnter Your Name: ";
    cin.ignore();
    getline(cin, userCNIC.CNIC_Name);

    cout << "Enter A Valid CNIC Number: ";
    cin >> userCNIC.CNIC_Number;

    cout << "Enter Your CNIC Issue Date: ";
    cin.ignore();
    getline(cin, userCNIC.CNIC_issueDate);

    cout << "Enter Your CNIC Expiry Date: ";
    getline(cin, userCNIC.CNIC_expiryDate);

    cout << "Enter Your Address: ";
    getline(cin, userCNIC.CNIC_address);
}

void customerAccountDetails() {
    srand(time(NULL));

    // Generate random account number
    string account_number;
    account_number.reserve(9);
    for (int i = 0; i < 9; i++) {
        account_number.push_back('0' + rand() % 10);
    }

    // Generate random IBAN number starting with "PK"
    string IBAN = "PK";
    IBAN.reserve(24);
    for (int i = 0; i < 22; i++) {
        IBAN.push_back('0' + rand() % 10);
    }

    // Generate random CVV number
    string CVV;
    CVV.reserve(3);
    for (int i = 0; i < 3; i++) {
        CVV.push_back('0' + rand() % 10);
    }

    // Get the current date
    time_t current_time = time(NULL);
    tm* current_date = localtime(&current_time);

    // Output the generated data in Pakistan format
    cout << "\n******** Account Details ********\n\n";
    cout << "Account Number: " << account_number << endl;
    cout << "IBAN: " << IBAN << endl;
    cout << "CVV: " << CVV << endl;
    cout << "Issue Date: " << current_date->tm_mday << "-" << current_date->tm_mon + 1 << "-" << current_date->tm_year + 1900 << endl;
}

int main() {
    cout << "\n\t\tMeezan Bank - Account Opening System";

    Customer user;
    cout << "\n\n\n******** Enter Your Details ********";
    customerDetails(user);

    CustomerCNIC userCNIC;
    cout << "\n******** Enter Your CNIC Details ********";
    customerCNICdetails(userCNIC);

    cout << "\nPlease, Wait For Approval.....";
    sleep(5);

    cout << "\n\n\n";
    writeToFile(user, userCNIC);
    customerAccountDetails();

    return 0;
}
