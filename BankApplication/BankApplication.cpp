/*This is Bank ATM machine Program that handles ATM operations like:
1. Check Account Balance
2. Deposit Money in an Account.
3. WithDraw Money from Account.

*/
#include <iostream>

// account login information with balance
int CustomerAccountNumber = 12345;
int pinNumber = 54321;
int AccountBalance = 0;
// create an booling to see if the account is validate

bool ValidateCustomerDetails() {

	int InputAccountNumber = -1;
	int InputPinNumber = -1;
	bool isAccountInvalid = true;
	bool isPinInvalid = true;

	std::cout << " *_*Welcome To J ATM ! " << std::endl;

	while (isAccountInvalid) {

		std::cout << "Please Enter Your o_o Bank Account Number : ";
		std::cin >> InputAccountNumber;

		if (InputAccountNumber == CustomerAccountNumber) {
			isAccountInvalid = false;
		}
		else {
			std::cout << "Invalid Account (^_^) Number! Try Again.? " << std::endl;
		}
	}
	int RetryCount = 3;
	while (isPinInvalid && RetryCount) {

		std::cout << "Enter your Customer PIN (*&*) : ";
		std::cin >> InputPinNumber;

		if (InputPinNumber == pinNumber) {
			isPinInvalid = false;
		}
		else {
			RetryCount--;
			if (RetryCount)
				std::cout << "Invalid Customer PIN  (^_^) number! Try again. " << std::endl;
			else
			{
				std::cout << "Your Account is Locked! 3 retry(*_(o) Reached! Try After some time. " << std::endl;
				return false;
			}

		}

	}

	return true;

}

// create the menu of an atm

int DisplayMenu() {

	int UserInputOption = -1;

	std::cout << "Welcome to Your Account!! Please choose and Option to Proceed" << std::endl;
	std::cout << "	1 - View Your Account balance" << std::endl;
	std::cout << "	2 - Withdraw Cash" << std::endl;
	std::cout << "	3 - Deposit Amount" << std::endl;
	std::cout << "	4 - Exit" << std::endl;
	std::cout << "Enter an Option to Proceed : " << std::endl;
	std::cin >> UserInputOption;
	return UserInputOption;
	system("cls");

}

// show account balance

void DisplayAccountBalance() {

	std::cout << "Your Account Balance is: " << std::endl;
	std::cout << "$" << AccountBalance << std::endl;

}

//allowed user to with draw cash

void WithDrawMoneyFromAccount() {

	int UserInputOption = -1;
	int valueToWithdraw = 0;
	long CustomerRequest = 0;
	bool isNotFinished = true;

	do {

		std::cout << "Withdraw Options: " << std::endl;
		std::cout << "1 - $20" << std::endl;
		std::cout << "2 - $40" << std::endl;
		std::cout << "3 - $60" << std::endl;
		std::cout << "4 - $100" << std::endl;
		std::cout << "5 - $200" << std::endl;
		std::cout << "6 - Custom Amount" << std::endl;
		std::cout << "7 - Cancel Transaction" << std::endl;
		std::cout << "Choose A With(o)_($)Draw Option (1-7). " << std::endl;

		std::cin >> UserInputOption;
		switch (UserInputOption) {
		case 1:
			valueToWithdraw = 20;
			break;
		case 2:
			valueToWithdraw = 40;
			break;
		case 3:
			valueToWithdraw = 60;
			break;
		case 4:
			valueToWithdraw = 100;
			break;
		case 5:
			valueToWithdraw = 200;
			break;
		case 7:
			isNotFinished = false;
			break;
		case 6:
			std::cout << "Enter Amount to WithDraw:" << std::endl;
			std::cin >> CustomerRequest;
			valueToWithdraw = CustomerRequest;
			isNotFinished = false;
			break;
		default:
			std::cout << "Invalid option! Try again." << std::endl;
			break;
		}

		if (valueToWithdraw != 0) {
			if (valueToWithdraw > AccountBalance) {
				std::cout << "Sorry!! Your Account Balance is Only $" << AccountBalance << ". You can't withdraw $" << valueToWithdraw << std::endl;
			}
			else {
				AccountBalance = AccountBalance - valueToWithdraw;
				isNotFinished = false;
			}
			valueToWithdraw = 0;
		}

	} while (isNotFinished);

}

// depositing v money
void DepositMoneyInAccount() {

	int UserInputOption = -1;
	bool isNotFinished = true;
	long depositAmount = 0;

	do {

		std::cout << " Amount Depositing Options. ()_() Please Enter Your Selection" << std::endl;
		std::cout << "1 - $20" << std::endl;
		std::cout << "2 - $40" << std::endl;
		std::cout << "3 - $60" << std::endl;
		std::cout << "4 - $100" << std::endl;
		std::cout << "5 - $200" << std::endl;
		std::cout << "6 - Custom Amount" << std::endl;
		std::cout << "7 - Cancel Transaction" << std::endl;
		std::cout << "Choose A Deposit Option (1-7): " << std::endl;

		std::cin >> UserInputOption;
		switch (UserInputOption) {
		case 1:
			AccountBalance = AccountBalance + 20;
			isNotFinished = false;
			break;
		case 2:
			AccountBalance = AccountBalance + 40;
			isNotFinished = false;
			break;
		case 3:
			AccountBalance = AccountBalance + 60;
			isNotFinished = false;
			break;
		case 4:
			AccountBalance = AccountBalance + 100;
			isNotFinished = false;
			break;
		case 5:
			AccountBalance = AccountBalance + 200;
			isNotFinished = false;
			break;
		case 7:
			isNotFinished = false;
			break;
		case 6:
			std::cout << "Please Enter Amount to Deposit:" << std::endl;
			std::cin >> depositAmount;
			AccountBalance = AccountBalance + depositAmount;
			isNotFinished = false;
			break;
		default:
			std::cout << "Invalid option! Try again." << std::endl;
			break;
		}

	} while (isNotFinished);

}

// run the code
int main() {
	
	system("Color, 0B");

	if (ValidateCustomerDetails()) {

		int isNotFinished = true;

		do {

			switch (DisplayMenu()) {
			case 1:
				DisplayAccountBalance();
				break;
			case 2:
				WithDrawMoneyFromAccount();
				break;
			case 3:
				DepositMoneyInAccount();
				break;
			case 4:
				isNotFinished = false;
				break;
			default:
				std::cout << "Invalid option! Try again." << std::endl;
				break;
			}
			system("cls");
		} while (isNotFinished);
		 system("pause>0");
	}

	return 0;

}