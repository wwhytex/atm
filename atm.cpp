#include <iostream>
using namespace std;

class atm {
private:
	int pin;
	int money;
	bool ispin;

public:
	atm(int startpin, double startmoney) {
		pin = startpin;
		money = startmoney;
		ispin = false;
	}

	void Deposit(int deposit) {
		if (ispin == true) {
			money = money + deposit;
			cout << "You deposited: ";
			cout << deposit;
		}
		else {
			cout << "Input correct pin" << endl;
		}
	}

	void Withdraw(int withdrawvalue) {
		if (ispin == true) {
			if (money > withdrawvalue) {
				money = money - withdrawvalue;
				cout << "You withdraw: ";
				cout << withdrawvalue;
			}
			else
				cout << "You don't have enough money";
		}
		else {
			cout << "Input correct pin" << endl;
		}
	}

	void Inputpin(int inputpin) {
		if (inputpin == pin) {
			ispin = true;
			cout << "Your pin is right " << endl;
		}
		else {
			cout << "Your pin is not right "<< endl;
		}
	}

	void Checkmoney() {
		if (ispin == true) {
			cout << money;
		}
		else {
			cout << "Input correct pin" << endl;
		}
	}
};

int main() {

	atm atm1(1711, 500);

	int DepositInput;
	int WithdrawInput;
	int PinInput;
	string UserInput;

	cout << "What is your pin: ";
	cin >> PinInput;
	atm1.Inputpin(PinInput);

	while (true) {
		cout << endl << "What do you want to do: ";
		cin >> UserInput;

		if (UserInput == "deposit") {
			cout << "How many money you want to deposit: ";
			cin >> DepositInput;
			atm1.Deposit(DepositInput);
		}
		if (UserInput == "withdraw") {
			cout << "How much money you want to withdraw: ";
			cin >> WithdrawInput;
			atm1.Withdraw(WithdrawInput);
		}
		if (UserInput == "checkmoney") {
			cout << "You have: ";
			atm1.Checkmoney();
		}
	}
}
