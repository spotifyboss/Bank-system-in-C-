#include <iostream>
#include <fstream>
#include <string>
#include "Bank_functions.h"
using namespace std;

class Bank {
	
	private:
		string name;
		double account_number, i_deposit;
		string saccount_number;
	
	public:
		void menu(); //done
		void create(); //done
		void login(); //done
		void dashboard();
		void deposit();
		void withdraw();
		void deleteAccount();
	
};

void Bank::menu() {
	
	int choice;
	cout << "1. Create Account \n";
	cout << "2. Login \n";
	cout << "3. Exit \n";
	
	cout << " \t \t \t Choose \n";
	cin >> choice;
	
	if (choice == 1){
	
		create();	
	
	}
	
	else if(choice == 2){
		
		login();
	}
	
	else if(choice == 3){
		system("cls");
		cout << "\t\t\t Thank you for using our software\n";
	}
	else{
		system("cls");
		cout << " \t\t\t Invalid Choice \n\n\n\n";
		menu();
	}

}

void Bank::	create(){
	
	string name;
	double account_number, i_deposit;
	
	cout << "Enter Name:";
	cin >> name;
	
	cout << "Enter Account number: ";
	cin >> account_number;
	
	cout << "Enter Initial deposit: ";
	cin >> i_deposit;
	
	
	//changing the doubles to string
	
	stringstream ss_account_number; 
	
	stringstream ss_i_deposit;
	
	ss_account_number << account_number;
	ss_i_deposit << i_deposit;
	
if(SearchAccount(ss_account_number.str()) != 0){
	
	if (i_deposit <= 0){
		
		system("cls");
		cout << "\t\t\t Invalid Initial deposit \n\n\n\n";
		create();	
	}
	else{
		CreateAccount(name, account_number, i_deposit);
		system("cls");
		cout << "\t\t\t Account created successfully \n\n\n";
		
		DisplayAccount(ss_account_number.str());
		cout << "\n\n\n\n";
		
		saccount_number = ss_account_number.str();
		dashboard();
		
	}

	
}
else{
	
	system("cls");
	cout << "\t\t\t Account already exists \n\n\n";
	menu();
}

}
	
void Bank::login(){
	string account_number;
	
	cout << "Enter account number:";
	
	cin >> account_number;
	
	if(SearchAccount(account_number) == 1){
		system("cls");
		
		DisplayAccount(account_number);
		cout <<"\n\n\n\n";
		
		menu();
	}
	else{
		system("cls");
		cout << " \t\t\t Success! \n\n";
		cout << "\n\n\n\n";
		
		saccount_number = account_number;
		DisplayAccount(account_number);
		
		dashboard();
	}
	
}

void Bank::dashboard(){
	
	int choice;
	
	cout << "1. Withdraw \n";
	cout << "2. Deposit \n";
	cout << "3. Delete Account \n";
	cout << "4. Back to menu \n";
	cout << "5. Exit \n";
	cout << " \t \t \t Choose \n";
	cin >> choice;
	
	if (choice == 1){
	
		withdraw();	
	
	}
	
	else if(choice == 2){
		
		deposit();
		
	}
	
	else if(choice == 3){
		
		deleteAccount();
		
	}
	else if (choice == 4){
		system("cls");
		menu();
	}
	else if (choice == 5){
		system("cls");
		
		cout << "Thank you for using our software";
	}
	else{
		system("cls");
		cout << " \t\t\t Invalid Choice \n\n\n\n";
		
		DisplayAccount(saccount_number);
		dashboard();
	}

	
}	

void Bank::withdraw(){
	string amount;
	
	cout << "Enter withdraw amount:";
	cin >> amount;
	
	Withdraw(saccount_number,amount);
	
	system("cls");
	DisplayAccount(saccount_number);
	cout << "\n\n\n";
	
	dashboard();
	
}

void Bank::deposit(){
	
	string amount;
	
	cout << "Enter deposit amount:";
	cin >> amount;
	
	Deposit(saccount_number,amount);
	
	system("cls");
	DisplayAccount(saccount_number);
	cout << "\n\n\n";
	
	dashboard();
	
}

void Bank::deleteAccount(){
	
	DeleteAccount(saccount_number);
	
	system("cls");
	menu();
	
}
int main(){
	
	Bank B;
	
	B.menu();
	
	return 0;
}
