#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<cctype>
#include<windows.h>//decoration purpose
using namespace std;

void header();
void mheader();
char islogin(char& x);
void isAdmin();
void adminMenu(bool&);
void isUser(bool&);
char addcar(char& y);
char deletecar(char& y);
char orderdetails(char&);
void loginusermenu();
void backmenu();
void usermainmenu();
void displayloct();
void loctmenu();
void returntitle();
void view();
void menu();
void rentCar();
void Location();
void ReturnCar();
void feedback();
string car[30][5];
double carPrice[30][5];
bool login = false;
bool rgst = false;
bool verification = false;
bool re = false;
bool exits = false;
int action;
int userAct;
int j = 0;
char quit;
ofstream userlist;
ofstream loct;
ofstream ret;
ifstream check;
ifstream ord;
ifstream ren;
string userid, password, id, pass;
string cname, cnames, carno, carbrand, carmodel, colourss;
string address[] = { "Jalan 11,Bukit Mertajam" ,"Jalan 4, Sungai Jawi" ,"Lorong 7,Sungai Bakap" };
int location;
double price, tprice;
string cuname;
string carnum;
string name;
string cuna, carnu, date;

struct user
{
	int SIZE = 100;
	string carPlate;
	string carBrand;
	string carModel;
	string RateperHour;
	string carColour;
};
int main()
{
	HANDLE colour;
	colour = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	char x;
	char selection, choice, y;//for user input 1 2
	bool back = false, backtomenu = false, z = false;
	do
	{
		islogin(x);
		selection = x;
		switch (selection)
		{
		case '1':
		{
			system("cls");
			isAdmin();
			system("cls");
			//bool z will be returned from function protocol and Login menu will be displayed again when z = true
			adminMenu(z);
			backtomenu = z;
			break;
		}
		case '2':
		{
			system("cls");
			isUser(z);
			backtomenu = z;
			break;
		}
		case '3':
		{
			SetConsoleTextAttribute(colour, 14);
			cout << setw(36) << "[-------------------------------]" << endl;
			cout << setw(36) << "| Thanks for using our service! |" << endl;
			cout << setw(36) << "[-------------------------------]" << endl;
			SetConsoleTextAttribute(colour, 7);
			system("pause");
			return 0;
		}
		default://do nothing
			break;
		}
	} while (backtomenu == true);

	return 0;
}

char islogin(char& x)
{
	bool back1 = false;
	HANDLE colour;
	colour = GetStdHandle(STD_OUTPUT_HANDLE);
	header();
	cout << "\n\t         ----------------------------------------------------" << endl;
	cout << "\t         |        Welcome to ProMax Car Rental System!      |\n";
	cout << "\t         ----------------------------------------------------";
	cout << "\n\n1. Admin\n2. User\n3. Exit the program\n\n" << endl;

	do//When back1=true, user have to key in again
	{
		SetConsoleTextAttribute(colour, 7);//Decoration purpose
		cout << "Please key in your choice >>";
		cin >> x;

		if (x != '1' && x != '2' && x != '3')
		{
			SetConsoleTextAttribute(colour, 12);//Decoration purpose
			cout << "Invalid input! Please key in again!" << endl;
			back1 = true;
		}
		else
		{
			back1 = false;
		}
	} while (back1 == true);
	return x;
}
void isAdmin()
{
	//Use c string to store password
	char password[20];
	header();
	cout << "\n\n\nProMax Car Rental System (Admin)\n";
	//Any password is allowed as no data validation here
	cout << "Password: ";
	cin >> password;

}
void adminMenu(bool& z)
{
	char selection, selectExit, y, choice;
	bool back = false, backtoChoice = false;
	HANDLE colour = GetStdHandle(STD_OUTPUT_HANDLE);

	do//When back=true, the admin menu will display again
	{
		header();
		cout << "\n\t\t------------------------------------------------";
		cout << "\n\t\t|\tProMax Car Rental System (Admin)       |";
		cout << "\n\t\t------------------------------------------------";
		cout << "\n\nAdmin menu\n1. Add car\n2. Delete car\n3. Order details\n4. Log out\n\n";
		do//When backtoChoice=true, users have to key in choice again
		{
			SetConsoleTextAttribute(colour, 7);
			cout << "Please key in your choice >>";
			cin >> choice;

			if (choice != '1' && choice != '2' && choice != '3' && choice != '4')
			{
				SetConsoleTextAttribute(colour, 12);
				cout << "Invalid input! Please key in again!" << endl;
				backtoChoice = true;
			}
			else
			{
				backtoChoice = false;
			}
		} while (backtoChoice == true);

		switch (choice)
		{
		case '1':
		{
			do//For display addcar module and return back to admin menu when back=true
			{
				system("cls");
				selectExit = addcar(y);
				if (toupper(selectExit) == 'Y')
					back = true;
				else
					back = false;
			} while (back == false);
			break;
		}
		case '2':
		{
			do // For display delete module and return back to admin menu when back = true
			{
				system("cls");
				selectExit = deletecar(y);
				if (toupper(selectExit) == 'Y')
					back = true;
				else
					back = false;
			} while (back == false);
			break;
		}
		case '3':
		{
			do // For display order details module and return back to admin menu when back = true
			{
				system("cls");
				selectExit = orderdetails(y);
				if (toupper(selectExit) == 'Y')
					back = true;
				else
					back = false;
			} while (back == false);
			break;
		}
		case '4':
		{
			back = false;
			//z will be returned for further checking
			z = true;
			break;
		}
		default://do nothing
			break;
		}
		system("cls");
	} while (back == true);
}
void isUser(bool& z) //Choose user interface.
{
	HANDLE colour = GetStdHandle(STD_OUTPUT_HANDLE);
	do //Login/register module
	{

		header();
		loginusermenu(); //User menu for login,register,and logout.
		cin >> action;
		if (action < 1 || action >3) //Detect invalid action number.
		{
			while (action < 1 || action >3) //Let user key in the action number until the action number is correct.
			{

				cout << "Invalid output, please try again: ";
				cin >> action;
			}
		}
		switch (action) //Run the function according to the action number key in by the user.
		{
		case 1: //Login
		{
			cout << "Please enter username: ";
			cin >> id;
			cout << "Please enter password: ";
			cin >> pass;
			check.open("user.txt");

			while (!check.eof()) //Read user.txt for checking is the username and password that key in by customer are matched or not.
			{

				check >> userid >> password; //Read username and password from user.txt.
				if (userid == id && password == pass) //If match, then exit directly from the while loop.
				{
					SetConsoleTextAttribute(colour, 11);
					cout << "  [---------------]" << endl;
					cout << "  | Login success!|" << endl;
					cout << "  [---------------]" << endl;
					SetConsoleTextAttribute(colour, 7);
					system("pause");
					login = true;
					break;
				}
			}
			check.close();
			if (login == false) //If username and password not matched, tell user to key in again.
			{
				SetConsoleTextAttribute(colour, 12);
				cout << "[-----------------------------------------------------]" << endl;
				cout << "| Incorrect username or password, please try again... |" << endl;
				cout << "[-----------------------------------------------------]" << endl;
				SetConsoleTextAttribute(colour, 7);
				backmenu();//Back to user login/register interface.
			}
			break;
		}
		case 2: //Register new account
		{
			cout << "Please key in username: ";
			cin >> id;
			cout << "Please key in password: ";
			cin >> pass;

			userlist.close();
			ifstream check;
			check.open("user.txt");

			while (!check.eof()) //Read user.txt to make sure the username and password which registered by user is a new one.
			{

				check >> userid >> password;
				if (userid == id && password == pass) //If username and password already exit in user.txt,exit directly from while loop, 
					//then do not allow user to register these both username and password.
					//The user need to register another username and password
				{
					SetConsoleTextAttribute(colour, 12);
					cout << "[------------------------------------------------------]" << endl;
					cout << "| The username already existed, please register again! |" << endl;
					cout << "[------------------------------------------------------]" << endl;
					SetConsoleTextAttribute(colour, 7);
					cout << endl;
					rgst = false;
					break;
				}
				rgst = true;
			}
			check.close();
			if (rgst == true) //If register success
			{
				SetConsoleTextAttribute(colour, 11);
				cout << "[----------------------------------------------------------]" << endl;
				cout << "| Congratulation! Your account is registered successfully! |" << endl;
				cout << "[----------------------------------------------------------]" << endl;
				SetConsoleTextAttribute(colour, 7);
				userlist.open("user.txt", ios::app);
				userlist << id << " " << pass << endl; //Write username and password which registered by user into user.txt;
				userlist.close();
			}
			backmenu(); //Back to user login/register interface.
			break;
		}
		case 3: // Logout/exit
		{
			SetConsoleTextAttribute(colour, 14);
			cout << setw(36) << "[-------------------------------]" << endl;
			cout << setw(36) << "| Thanks for using our service! |" << endl;
			cout << setw(36) << "[-------------------------------]" << endl;
			SetConsoleTextAttribute(colour, 7);
			system("pause");
			system("cls");
			z = true;
			break;
		}
		}
		if (login == true) //If login success, exit do...while loop(close user login/register interface).
		{
			break;
		}
	} while (action != 3);

	if (login == true) // If login success, go to user main action menu after close user login/register interface.
	{
		system("cls");
		do
		{
			header();
			usermainmenu();//Show user main action menu for user select.
			cin >> userAct; //Key in user main action number.
			switch (userAct) //Run module according to the action number which selected by the user.
			{

			case 1: //View module(view car informations)
			{
				menu();
				system("pause");
				system("cls");
				break;
			}
			case 2: //Rent module(rent car)
			{
				rentCar();
				system("cls");
				break;
			}
			case 3: //Select module(select location)
			{
				Location();
				break;
			}
			case 4: //Return module(return car)
			{
				ReturnCar();
				break;
			}
			case 5: //Feedback module(user feedback)
			{
				feedback();
				system("pause");
				system("cls");
				break;
			}

			case 6: //logout
			{
				SetConsoleTextAttribute(colour, 14);
				cout << setw(36) << "[-------------------------------]" << endl;
				cout << setw(36) << "| Thanks for using our service! |" << endl;
				cout << setw(36) << "[-------------------------------]" << endl;
				SetConsoleTextAttribute(colour, 7);
				system("pause");
				system("cls");
				z = true;
				break;
			}
			default: //Key in action number again due to invalid action number
			{
				SetConsoleTextAttribute(colour, 12);
				cout << "[-------------------------------------------]" << endl;
				cout << "|Invalid action number, please select again!|\n";
				cout << "[-------------------------------------------]" << endl;
				SetConsoleTextAttribute(colour, 7);
				system("pause");
				system("cls");
			}

			}

		} while (userAct != 6);
	}
}
char addcar(char& y)
{
	ifstream addFile("CarMenu.txt");
	ofstream outFile("CarMenu.txt", ios::app);
	double RateperHour[20][5];
	//use struct to declare variable in array
	user order[20];
	int i = 0, j = 0;
	bool reKey = false;

	//decoration
	HANDLE colour;
	colour = GetStdHandle(STD_OUTPUT_HANDLE);
	header();
	cout << "\n\n\t\t\t\tProMax Car Rental System (Add Car)\n";
	SetConsoleTextAttribute(colour, 14);
	cout << "====================================================================================================" << endl;
	cout << "|\t" << left << setw(13) << "Plate" << "|\t  " << left << setw(13) << "Brand" << "|\t" << left << setw(13) << "Model" << "| "
		<< left << setw(15) << "Rate per Hour" << " |\t" << left << setw(11) << "Colour" << "|" << endl;
	cout << "====================================================================================================" << endl;
	SetConsoleTextAttribute(colour, 7);

	if (addFile.is_open())
	{
		for (i = 0; !addFile.eof(); i++)
		{
			//Read car details by using struct and two-dimensional array, then display
			addFile >> order[i].carPlate >> order[i].carBrand >> order[i].carModel >> RateperHour[i][3] >> order[i].carColour;
			cout << "|\t" << left << setw(13) << order[i].carPlate << "|\t  " << left << setw(13) << order[i].carBrand << "|\t" << left << setw(13)
				<< order[i].carModel << "| " << left << setw(15) << fixed << setprecision(2) << RateperHour[i][3]
				<< " |\t" << left << setw(11) << order[i].carColour << "|" << endl;
			cout << "----------------------------------------------------------------------------------------------------" << endl;
		}
		cout << "\nPress Y/y anywhere to exit\n\n\n";

		do//when reKey=true, admin have to key in again car plate
		{
			SetConsoleTextAttribute(colour, 7);
			cout << "Car Plate: ";
			cin >> order[i].carPlate;
			reKey = false;
			//Search whether the car input exist or not
			for (int j = 0; j < i; j++)
			{
				if (order[i].carPlate == order[j].carPlate)
				{
					SetConsoleTextAttribute(colour, 12);//Decoration purpose
					cout << "The car already exist in the system. Please key in again!" << endl;
					reKey = true;
				}
			}
		} while (reKey == true);

		//Admin is allowed to exit anywhere by typing y OR Y during input section
		if (order[i].carPlate == "Y" || order[i].carPlate == "y")
		{
			y = 'y';
			return y;
		}
		cout << "Car Brand: ";
		cin >> order[i].carBrand;
		if (order[i].carBrand == "Y" || order[i].carBrand == "y")
		{
			y = 'y';
			return y;
		}
		cout << "Car Model: ";
		cin >> order[i].carModel;
		if (order[i].carModel == "Y" || order[i].carModel == "y")
		{
			y = 'Y';
			return y;
		}
		do//Admin have to re-key in rate per hour when reKey=true
		{
			SetConsoleTextAttribute(colour, 7);
			cout << "Rate per Hour (RM): ";
			cin >> RateperHour[i][3];

			if (RateperHour[i][3] < 0 || RateperHour[i][3] > 1000)
			{
				SetConsoleTextAttribute(colour, 12);
				cout << "Invalid input! Please key in again!" << endl;
				reKey = true;
			}
			else
			{
				reKey = false;
			}
		} while (reKey == true);

		cout << "Car Colour: ";
		cin >> order[i].carColour;
		if (order[i].carColour == "Y" || order[i].carColour == "y")
		{
			y = 'Y';
			return y;
		}
		//Update the input into the carMenu.txt
		outFile << "\n" << order[i].carPlate << " " << order[i].carBrand << " " << order[i].carModel << " " << fixed << setprecision(2) << RateperHour[i][3] << " " << order[i].carColour;

		addFile.close();
		outFile.close();
		SetConsoleTextAttribute(colour, 2);
		cout << "Add the car successfully!" << endl;
		SetConsoleTextAttribute(colour, 7);
		cout << "\nPlease enter Y to exit or other to update the menu >> ";//New menu will be updated after entered any character
		cin >> y;
		return y;
	}
	else//When carMenu.txt is not open
	{
		cout << "Error in uploading the menu" << endl;
		cout << "\n\nPlease enter Y to exit >> " << endl;
		cin >> y;
		return y;
	}
}
char deletecar(char& y)
{
	ifstream deleteFile("CarMenu.txt");
	ofstream outFile("CarMenu.txt", ios::app);
	const int size = 15, size2 = 5;
	char deletecar[8];
	string carDlt[size][size2];
	int i = 0, j = 0, length;
	bool reKey = false;
	HANDLE colour = GetStdHandle(STD_OUTPUT_HANDLE);

	header();
	cout << "\n\n\t\t\t\tProMax Car Rental System (Delete Car)\n";
	SetConsoleTextAttribute(colour, 14);
	cout << "====================================================================================================" << endl;
	cout << "|\t" << left << setw(13) << "Plate" << "|\t  " << left << setw(13) << "Brand" << "|\t" << left << setw(13) << "Model" << "| " << left << setw(15) << "Rate per Hour" << " |\t" << left << setw(11) << "Colour" << "|" << endl;
	cout << "====================================================================================================" << endl;
	SetConsoleTextAttribute(colour, 7);

	if (deleteFile.is_open())
	{
		//Using for loop to read data and store in string two-dimensional array
		for (i = 0; !deleteFile.eof(); i++)
		{
			deleteFile >> carDlt[i][0] >> carDlt[i][1] >> carDlt[i][2] >> carDlt[i][3] >> carDlt[i][4];
			cout << "|\t" << left << setw(13) << carDlt[i][0] << "|\t  " << left << setw(13) << carDlt[i][1] << "|\t" << left << setw(13)
				<< carDlt[i][2] << "| " << left << setw(15) << carDlt[i][3]
				<< " |\t" << left << setw(11) << carDlt[i][4] << "|" << endl;
			cout << "----------------------------------------------------------------------------------------------------" << endl;
		}
		length = i;
		cout << "\nPress Y/y anywhere to exit\n\n\n";
		do
		{
			SetConsoleTextAttribute(colour, 7);
			cout << "Please enter the car plate that you want to delete >>";
			cin >> deletecar;
			if (deletecar[0] == 'Y' || deletecar[0] == 'y')
			{
				y = 'Y';
				return y;
			}
			//Using for loop to find the keyed in car and clear all its details of this specific row of array
			for (int i = 0; i < length; i++)
			{
				if (deletecar == carDlt[i][0])
				{
					carDlt[i][0].clear();
					carDlt[i][1].clear();
					carDlt[i][2].clear();
					carDlt[i][3].clear();
					carDlt[i][4].clear();
					reKey = true;
					break;
				}
				else
					reKey = false;
			}
			//If the selected car is not in the menu, prompt user to key in again
			if (reKey == false)
			{
				SetConsoleTextAttribute(colour, 12);
				cout << "The car does not exist! Please re-key in!" << endl;
			}
		} while (reKey == false);
		deleteFile.close();
		outFile.close();//Close the CarMenu.txt which is opened with ios::app

		//Open the CarMenu.txt (become empty) and rewrite the updated array into the text file.
		deleteFile.open("CarMenu.txt");
		outFile.open("CarMenu.txt");
		for (i = 0; i < length; i++)
		{
			//If the stored array is not empty, write them to file
			if (!carDlt[i][0].empty())
			{
				if (i == 0)
				{
					outFile << carDlt[0][0] << " " << carDlt[0][1] << " " << carDlt[0][2] << " " << fixed << setprecision(2) << carDlt[0][3] << " " << carDlt[0][4];
				}
				//If i is not zero, endline first then start to write them to file
				else if (!(i == 0))
				{
					outFile << "\n" << carDlt[i][0] << " " << carDlt[i][1] << " " << carDlt[i][2] << " " << carDlt[i][3] << " " << carDlt[i][4];
				}
			}
		}
		outFile.close();
		SetConsoleTextAttribute(colour, 2);
		cout << "Delete the car successfully!" << endl;
		SetConsoleTextAttribute(colour, 7);
		cout << "\nPlease enter Y to exit or other to update the menu >> ";//Value will be updated after enter any character
		cin >> y;
		return y;
	}
	else//When carMenu.txt is not open
	{
		cout << "Error in uploading the menu" << endl;
		cout << "\n\nPlease enter Y to exit >> " << endl;
		cin >> y;
		return y;
	}
}
char orderdetails(char& y)
{
	ifstream myFile;
	ofstream outFile;
	const int size = 15;
	const int size2 = 5;
	int select, length;
	bool back = false, backtoDetails = false, checkFile = false;
	char x;
	string carDetails[size][size2];
	double price[size][size2];
	HANDLE colour = GetStdHandle(STD_OUTPUT_HANDLE);
	string name[50], nameSame[50];
	//Use do while loop to display order details and perform iteration when back=true

	do
	{
		myFile.open("rentCar.txt", ios::app);
		outFile.open("rentCar.txt", ios::app);
		int i = 0;
		header();
		cout << "\n\n\t\t\tProMax Car Rental System (Order Details)\n";
		SetConsoleTextAttribute(colour, 14);
		cout << "=============================================================================" << endl;
		cout << "|" << left << setw(15) << "Customer Name" << "|" << left << setw(10) << "Plate" << "|" << left << setw(10) << "Brand" << "|" << left << setw(10) << "Model"
			<< "|" << left << setw(10) << "Colour" << "|" << left << setw(15) << "Total Paid" << "|" << endl;
		cout << "=============================================================================" << endl;
		SetConsoleTextAttribute(colour, 7);
		//check whether the text file is empty
		if (myFile.peek() == EOF)
		{
			checkFile = false;
		}
		else
		{
			checkFile = true;
		}

		if (checkFile == false)
		{
			myFile.close();
			outFile.close();
			SetConsoleTextAttribute(colour, 12);
			cout << "\n\tThere is no order in this month yet.\n\tPlease improve the sales!!";
			SetConsoleTextAttribute(colour, 7);
			cout << "\n\n\nPlease enter Y to back to previous >>";
			cin >> x;
			if (x == 'Y' || x == 'y')
			{
				back = false;
				y = 'Y';
				return y;
			}
		}
		else if (checkFile == true)
		{
			while (!myFile.eof())
			{
				getline(myFile, name[i]);
				cout << "|" << left << setw(15) << name[i];

				myFile >> carDetails[i][0] >> carDetails[i][1] >> carDetails[i][2] >> carDetails[i][3] >> carDetails[i][4] >> price[i][5];
				cout << "|" << left << setw(10) << carDetails[i][0] << "|" << left << setw(10) << carDetails[i][1] << "|" << left << setw(10) << carDetails[i][2]
					<< "|" << left << setw(10) << carDetails[i][4] << "|" << left << setw(15) << fixed << setprecision(2) << price[i][5] << "|" << endl;
				cout << "-----------------------------------------------------------------------------" << endl;
				myFile.ignore();
				i++;
			}
			length = i;
			cout << "\n\n<1> Generate monthly report \t\t <2> Back \n\nPlease key in your choice >> ";
			cin >> select;
			//Use while loop to check for data validation
			while (select != 1 && select != 2)
			{
				SetConsoleTextAttribute(colour, 12);//Decoration purpose
				cout << "Invalid input! Please key in your choice again >> ";
				cin >> select;
			}
			SetConsoleTextAttribute(colour, 7);//Decoration purpose
			if (select == 1)
			{
				system("cls");
				//Use do while loop to display monthly report and perform iteration when backtoDetails=true
				do
				{
					int j = 0;
					double sum = 0;
					header();
					cout << "\n\t\t\t\tProMax's Monthly Report\n\n";
					SetConsoleTextAttribute(colour, 14);
					cout << "=============================================================================================" << endl;
					cout << "|\t" << left << setw(17) << "Customer Name" << "|\t\t" << left << setw(20) << "Rented Car" << "|\t\t" << left << setw(20) << "Total Paid (RM)" << "|" << endl;; //<< left << setw(20) << "Return Date" << endl;
					cout << "=============================================================================================" << endl;
					SetConsoleTextAttribute(colour, 7);
					while (j < length)
					{
						cout << "|\t" << left << setw(17) << name[j] << "|\t\t" << left << setw(20) << carDetails[j][0]
							<< "|\t\t" << left << setw(20) << fixed << setprecision(2) << price[j][5] << "|" << endl;
						cout << "---------------------------------------------------------------------------------------------" << endl;;
						sum = sum + price[j][5];
						j++;
					}
					SetConsoleTextAttribute(colour, 15);
					cout << "\n\nTotal Sales = RM " << sum;
					SetConsoleTextAttribute(colour, 7);
					cout << "\n\nPlease enter Y to back to previous >>";
					cin >> x;
					if (x == 'Y' || x == 'y')
					{
						myFile.close();
						outFile.close();
						system("cls");
						backtoDetails = false;//Exit monthly report
						back = true;
					}
					else
						backtoDetails = true;
					system("cls");
				} while (backtoDetails == true);
			}
			else if (select == 2)
			{
				back = false;
				y = 'Y';
				return y;
			}
		}
	} while (back == true);

	cout << "\n\nPlease enter Y to exit or other to refresh the details >> " << endl;//Value will be updated after enter Y or N
	cin >> y;
	return y;
}

void loginusermenu()
{

	cout << "***********************************************************************************" << endl;
	cout << "*                          Welcome to ProMax Car Rental!!                         *" << endl;
	cout << "***********************************************************************************" << endl;
	cout << endl;

	cout << "Please login or register a new account for the further actions!" << endl;
	cout << "1.Login account" << endl;
	cout << "2.Register new account" << endl;
	cout << "3.Logout/Exit" << endl;
	cout << "Please select the action number: ";

}

void backmenu() //Back to user login/register interface.
{
	cin.ignore();
	cout << "Please press enter to back to menu.";
	cin.get();
	system("cls");
}
void usermainmenu()
{
	cout << "***********************************************************************************" << endl;
	cout << "*                        ProMax Car Rental User Main menu                         *" << endl;
	cout << "***********************************************************************************" << endl;
	cout << "\nUser menu\n";
	cout << "1. View Car Module" << endl;
	cout << "2. Rent Car" << endl;
	cout << "3. Choose Location to Pick Up Car" << endl;
	cout << "4. Return Car" << endl;
	cout << "5. Feedback" << endl;
	cout << "6. Logout" << endl;
	cout << "\nPlease enter your action number >>";

}

void displayloct() //Display location selection menu
{
	cout << "***********************************************************************************" << endl;
	cout << "*               Welcome to ProMax Car Rent location selection menu!!              *" << endl;
	cout << "***********************************************************************************" << endl;
	cout << endl;

	cout << "Please select a location that you want to get your rented car from there!" << endl;
	cout << "**If you want to quit this section, please enter '4' for exit**" << endl;
	cout << "1. Jalan 11,Bukit Mertajam" << endl;
	cout << "2. Jalan 4, Sungai Jawi" << endl;
	cout << "3. Lorong 7,Sungai Bakap" << endl;
	cout << "4. Exit***" << endl;
	cout << "Please key in the number to select location: ";

}

void loctmenu()
{
	cin.ignore();
	cout << "<Please press enter to back to user main menu.>";
	cin.get();
	system("cls");
	location = 4;
}

void returntitle()// Display header of interface of return car.
{
	cout << "********************************************************************************************************************" << endl;
	cout << "*                                       ProMax Car Rental Return Car Section                                       *" << endl;
	cout << "********************************************************************************************************************" << endl;
	cout << endl;

}

void view() {
	ifstream CarFile;
	string carPlate, carBrand, carModel, carColour;
	double RateperHour;
	HANDLE text = GetStdHandle(STD_OUTPUT_HANDLE);  //for decoration purpose
	system("cls");

	header();

	cout << "=======================================================================" << endl;
	cout << "|" << left << setw(10) << "Plate" << "|" << left << setw(13) << "Brand" << "|" << left << setw(12) << "Model" << "|" << left << setw(20) << "Rate per Hour" << "|" << left << setw(10) << "Colour" << "|" << endl;
	cout << "=======================================================================" << endl;
	CarFile.open("CarMenu.txt");

	while (!CarFile.eof())
	{
		CarFile >> carPlate >> carBrand >> carModel >> RateperHour >> carColour;  //read the data of car that recorded in the CarMenu.txt.
		SetConsoleTextAttribute(text, 14);
		cout << "|" << left << setw(10) << carPlate << "|" << left << setw(13) << carBrand << "|" << left << setw(12) << carModel << "|" << left << setw(20) << fixed << setprecision(2) << RateperHour << "|" << left << setw(10) << carColour << "|" << endl;
		CarFile.ignore();
	}
	CarFile.close();
	SetConsoleTextAttribute(text, 14);
	cout << "=======================================================================" << endl;
	SetConsoleTextAttribute(text, 7);
}

void menu() {
	double carRange;
	ifstream CFile;
	int i = 0, j = 0;
	HANDLE text = GetStdHandle(STD_OUTPUT_HANDLE);  //for decoration purpose
	system("cls");
	view();//display the car menu to the users.

	CFile.open("CarMenu.txt");
	while (!CFile.eof())
	{
		CFile >> car[i][0] >> car[i][1] >> car[i][2] >> carPrice[i][3] >> car[i][4];//store the data of the text file in the array
		i++;
		CFile.ignore();
	}
	CFile.close();

	cout << endl;
	cout << "The price that you prefer( 30/ 40/ 50/ 60): ";  //key in the price range that user prefer.
	cin >> carRange;
	int leng = i;
	cout << "The available car is shown below: " << endl;
	for (int i = 0; i < leng; i++)
	{
		if (carRange >= carPrice[i][3])
		{
			cout << "  " << car[i][0] << " RM" << carPrice[i][3] << endl; //show the cars that match with the price range that user input.
		}

	}

	SetConsoleTextAttribute(text, 2);  //for decoration purpose
	cout << "=============================" << endl;
	cout << "|                           |" << endl;
	cout << "|        Thanks for         |" << endl;
	cout << "|      viewing our menu     |" << endl;
	cout << "|           !!!!!           |" << endl;
	cout << "|                           |" << endl;
	cout << "=============================" << endl;
	SetConsoleTextAttribute(text, 7);  //for decoration purpose

}

void rentCar() {
	string plate;
	int hours;
	char ans;
	string sel;
	ifstream CFile;
	ofstream RFile, WFile;
	int i = 0;
	bool loop = false;
	HANDLE text = GetStdHandle(STD_OUTPUT_HANDLE);  //for decoration purpose
	system("cls");
	view();
	cout << endl;

	SetConsoleTextAttribute(text, 1);  //for decoration purpose
	cout << "*************************************************************" << endl;
	cout << "*                                                           *" << endl;
	cout << "*                      RENT CAR MODULE                      *" << endl;
	cout << "*                                                           *" << endl;
	cout << "*************************************************************" << endl;
	cout << endl;
	SetConsoleTextAttribute(text, 7);  //for decoration purpose

	CFile.open("CarMenu.txt");  //store the data that read from file in the array.
	while (!CFile.eof())
	{
		CFile >> car[i][0] >> car[i][1] >> car[i][2] >> carPrice[i][3] >> car[i][4];
		i++;
		CFile.ignore();
	}
	CFile.close();

	int leng = i;

	do
	{
		if (j > 0)
		{
			system("cls");
			view();
		}
		cout << "\nCar plate of car to rent: ";  //ask user to key in the car plate and the hours that want to rent
		cin >> plate;
		cout << "Hours to rent: ";
		cin >> hours;


		for (int i = 0; i < leng; i++)
		{
			if (plate == car[i][0])  //if the car plate key in by user is same as the car plate that stored in the array
			{
				cout << "Price should pay: RM" << carPrice[i][3] * hours;
				cout << endl;
				cout << "Are you sure to rent this car?(Y/N): ";
				cin >> ans;
				if (ans == 'Y' || ans == 'y')  //if the user wants to rent car, will ask user to key in his/her name.
				{
					cin.ignore();
					cout << "Enter your name: " << endl;
					getline(cin, name);
					RFile.open("rentCar.txt", ios::app);
					if (j > 0)
					{
						RFile << "\n";
					}
					RFile << name << endl;  //will record the details of the order from the user like car plate, car brand, car model, car price per hours, car's colour and the price that user to pay
					RFile << car[i][0] << " " << car[i][1] << " " << car[i][2] << " " << fixed << setprecision(2) << carPrice[i][3] << " " << car[i][4] << " " << carPrice[i][3] * hours;
					SetConsoleTextAttribute(text, 2);  //for decoration purpose
					cout << "=============================" << endl;
					cout << "|                           |" << endl;
					cout << "|            Rent           |" << endl;
					cout << "|        Successfully       |" << endl;
					cout << "|            !!!!!          |" << endl;
					cout << "|                           |" << endl;
					cout << "=============================" << endl;
					SetConsoleTextAttribute(text, 7);  //for decoration purpose
				}
				else if (ans == 'N' || ans == 'n')  //if user don't want to rent the car, will display "Unable to rent" 
				{
					SetConsoleTextAttribute(text, 4);  //for decoration purpose
					cout << "==============================" << endl;
					cout << "|                            |" << endl;
					cout << "|         Unable to          |" << endl;
					cout << "|            Rent            |" << endl;
					cout << "|           !!!!!!           |" << endl;
					cout << "|                            |" << endl;
					cout << "==============================" << endl;
					SetConsoleTextAttribute(text, 7);  //for decoration purpose
				}
			}
		}
		cout << "Do you want to continue? (Y/N) >>";  //ask user that either want to rent another car or not
		cin >> sel;
		if (sel == "Y" || sel == "y")  //if yes, will loop again 
		{
			j++;
			RFile.close();
			loop = false;
			//break;
		}
		else  //if no, will stop the rent car part
		{
			j++;
			loop = true;
			RFile.close();
		}
	} while (loop == false);
	system("pause");
}
void feedback()
{
	string comment;
	ifstream cFile;
	ofstream feedFile;
	string carPlat, cusname, cuscar, cusdate;
	int rating;
	bool bug = false;
	HANDLE text = GetStdHandle(STD_OUTPUT_HANDLE);  //for decoration purpose

	cin.ignore();
	system("cls");

	SetConsoleTextAttribute(text, 6);  //for decoration purpose
	cout << "*************************************************************" << endl;
	cout << "*                                                           *" << endl;
	cout << "*                      FEEDBACK MODULE                      *" << endl;
	cout << "*                                                           *" << endl;
	cout << "*************************************************************" << endl;
	SetConsoleTextAttribute(text, 7);  //for decoration purpose
	cout << endl;

	//ask user to key in his/her name and car plate that rented to identify that the user either had rent the car or not
	cout << "Please enter name: " << endl;
	getline(cin, cusname);
	cout << "Please enter car plate that rent: " << endl;
	cin >> cuscar;
	cFile.open("return.txt");
	feedFile.open("feedback.txt", ios::app);
	while (!cFile.eof())
	{
		getline(cFile, name);//read the return.txt to identify the status of the user
		cFile >> carPlat >> cusdate;
		cFile.ignore();
		if (cusname == name && cuscar == carPlat)  //if found that the user had rent car, then the user can give the feedback
		{
			bug = true;
			cout << "Rating 1-5: " << endl;
			cin >> rating;


			if (rating == 1)
			{
				SetConsoleTextAttribute(text, 11);  //for decoration purpose
				cout << "======================================" << endl;
				cout << "|                                    |" << endl;
				cout << "|      Sad to recive this rating     |" << endl;
				cout << "|        and we will work hard       |" << endl;
				cout << "|           to improve it            |" << endl;
				cout << "|                                    |" << endl;
				cout << "======================================" << endl;
				SetConsoleTextAttribute(text, 7);  //for decoration purpose
				cout << endl;
				cout << endl;
				cout << "=====================================================================================" << endl;
				cout << "Please give us some suggestion or tell us your feeling: " << endl;
				cin.ignore();
				getline(cin, comment);
				feedFile << cusname << endl;
				feedFile << cuscar << " " << cusdate << endl;
				feedFile << "Comment: " << comment << endl;
				system("cls");
				SetConsoleTextAttribute(text, 2);  //for decoration purpose
				cout << "================================" << endl;
				cout << "|                              |" << endl;
				cout << "|     Thanks for giving us     |" << endl;
				cout << "|        the feedback!         |" << endl;
				cout << "|                              |" << endl;
				cout << "================================" << endl;
				SetConsoleTextAttribute(text, 7);  //for decoration purpose
				break;
			}
			else if (rating == 2)
			{
				SetConsoleTextAttribute(text, 11);  //for decoration purpose
				cout << "======================================" << endl;
				cout << "|                                    |" << endl;
				cout << "|          Thanks for rating         |" << endl;
				cout << "|          and we will make          |" << endl;
				cout << "|           it more better           |" << endl;
				cout << "|                                    |" << endl;
				cout << "======================================" << endl;
				SetConsoleTextAttribute(text, 7);  //for decoration purpose
				cout << endl;
				cout << endl;
				cout << "=====================================================================================" << endl;
				cout << "Please give us some suggestion or tell us your feeling: " << endl;

				cin.ignore();
				getline(cin, comment);
				feedFile << cusname << endl;
				feedFile << cuscar << " " << cusdate << endl;
				feedFile << "Comment: " << comment << endl;
				system("cls");
				SetConsoleTextAttribute(text, 2);  //for decoration purpose
				cout << "================================" << endl;
				cout << "|                              |" << endl;
				cout << "|     Thanks for giving us     |" << endl;
				cout << "|        the feedback!         |" << endl;
				cout << "|                              |" << endl;
				cout << "================================" << endl;
				SetConsoleTextAttribute(text, 7);  //for decoration purpose
				break;
			}
			else if (rating == 3)
			{
				SetConsoleTextAttribute(text, 11);  //for decoration purpose
				cout << "==========================================" << endl;
				cout << "|                                        |" << endl;
				cout << "|            Thanks for rating           |" << endl;
				cout << "|        and we will try our best        |" << endl;
				cout << "|  to make your experience more better.  |" << endl;
				cout << "|                                        |" << endl;
				cout << "==========================================" << endl;
				SetConsoleTextAttribute(text, 7);  //for decoration purpose
				cout << endl;
				cout << endl;
				cout << "=====================================================================================" << endl;
				cout << "Please give us some suggestion or tell us your feeling: " << endl;

				cin.ignore();
				getline(cin, comment);
				feedFile << cusname << endl;
				feedFile << cuscar << " " << cusdate << endl;
				feedFile << "Comment: " << comment << endl;
				system("cls");
				SetConsoleTextAttribute(text, 2);  //for decoration purpose
				cout << "================================" << endl;
				cout << "|                              |" << endl;
				cout << "|     Thanks for giving us     |" << endl;
				cout << "|        the feedback!         |" << endl;
				cout << "|                              |" << endl;
				cout << "================================" << endl;
				SetConsoleTextAttribute(text, 7);  //for decoration purpose
				break;
			}
			else if (rating == 4)
			{
				SetConsoleTextAttribute(text, 11);  //for decoration purpose
				cout << "=====================================" << endl;
				cout << "|                                   |" << endl;
				cout << "|        Thanks for rating          |" << endl;
				cout << "|      and we are appreciate        |" << endl;
				cout << "|     to receive this rating.       |" << endl;
				cout << "|                                   |" << endl;
				cout << "=====================================" << endl;
				SetConsoleTextAttribute(text, 7);  //for decoration purpose
				cout << endl;
				cout << endl;
				cout << "=====================================================================================" << endl;
				cout << "Please give us some suggestion or tell us your feeling: " << endl;

				cin.ignore();
				getline(cin, comment);
				feedFile << cusname << endl;
				feedFile << cuscar << " " << cusdate << endl;
				feedFile << "Comment: " << comment << endl;
				system("cls");
				SetConsoleTextAttribute(text, 2);  //for decoration purpose
				cout << "================================" << endl;
				cout << "|                              |" << endl;
				cout << "|     Thanks for giving us     |" << endl;
				cout << "|        the feedback!         |" << endl;
				cout << "|                              |" << endl;
				cout << "================================" << endl;
				SetConsoleTextAttribute(text, 7);  //for decoration purpose
				break;
			}
			else if (rating == 5)
			{
				SetConsoleTextAttribute(text, 11);  //for decoration purpose
				cout << "=====================================" << endl;
				cout << "|                                   |" << endl;
				cout << "|        Thanks you very much.      |" << endl;
				cout << "|    We will keep our performance   |" << endl;
				cout << "|          in the best.             |" << endl;
				cout << "|                                   |" << endl;
				cout << "=====================================" << endl;
				SetConsoleTextAttribute(text, 7);  //for decoration purpose
				cout << endl;
				cout << endl;
				cout << "=====================================================================================" << endl;
				cout << "Please give us some suggestion or tell us your feeling: " << endl;

				cin.ignore();
				getline(cin, comment);
				feedFile << cusname << endl;
				feedFile << cuscar << " " << cusdate << endl;
				feedFile << "Comment: " << comment << endl;
				system("cls");
				SetConsoleTextAttribute(text, 2);  //for decoration purpose
				cout << "================================" << endl;
				cout << "|                              |" << endl;
				cout << "|     Thanks for giving us     |" << endl;
				cout << "|        the feedback!         |" << endl;
				cout << "|                              |" << endl;
				cout << "================================" << endl;
				SetConsoleTextAttribute(text, 7);  //for decoration purpose
				break;
			}
			else {  //if the rating is more than 5, will show "Invalid Input"
				SetConsoleTextAttribute(text, 4);  //for decoration purpose
				cout << "=============================" << endl;
				cout << "|                           |" << endl;
				cout << "|          Invalid          |" << endl;
				cout << "|         Input!!!!         |" << endl;
				cout << "|                           |" << endl;
				cout << "=============================" << endl;
				SetConsoleTextAttribute(text, 7);  //for decoration purpose
				system("pause");
				feedback();
			}
			cFile.close();
			feedFile.close();
		}
	}
	if (bug == false)  //if found that the user do not have rent car, will show the statement that the user cannot give the feedback
	{
		SetConsoleTextAttribute(text, 4);  //for decoration purpose
		cout << "==================================" << endl;
		cout << "|            YOU ARE             |" << endl;
		cout << "|          UNAVAILABLE           |" << endl;
		cout << "|          TO GIVE THE           |" << endl;
		cout << "|     FEEDBACK  AND RATING!!!    |" << endl;
		cout << "==================================" << endl;
		SetConsoleTextAttribute(text, 7);  //for decoration purpose
	}
}
void Location() //Select module(for location)
{
	system("cls");
	cin.ignore();
	header();
	cout << endl;
	cout << "Please key in your name for verification: ";
	getline(cin, cname);
	ord.open("rentCar.txt");

	while (!ord.eof()) //Read rentCar.txt to ensure the user has made order or not.
	{
		//Read user's name from rentCar.txt.
		//Read car license plate number, brand, model, rent price per hour, colour and total rent price.
		getline(ord, cnames);
		ord >> carno >> carbrand >> carmodel >> price >> colourss >> tprice;
		ord.ignore();
		if (cnames == cname)// If user has made order, exit the while loop directly.
		{
			HANDLE colour = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(colour, 11);
			cout << " [-----------------------]" << endl;
			cout << " | Verification success! |" << endl;
			cout << " [-----------------------]" << endl;
			SetConsoleTextAttribute(colour, 7);
			system("pause");
			verification = true;
			break;
		}
		verification = false;
	}
	ord.close();
	if (verification == false) // If user hasn't made order or accidentally key in wrong name.
	{
		HANDLE colour = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(colour, 12);
		cout << "\n[--------------------------------------------------------------------------------]" << endl;
		cout << "|   Invalid name, please enter this section again and key in your name again.    |" << endl;
		cout << "|    You are only allowed to choose location after rented car, thank you!!!      |" << endl;
		cout << "[--------------------------------------------------------------------------------]\n" << endl;
		SetConsoleTextAttribute(colour, 7);
		system("Pause");
		system("cls"); //exit select module

	}
	else if (verification == true) // If user has made order.
	{
		loct.open("location.txt", ios::app);
		do
		{
			system("cls");
			header();
			displayloct(); //Display location selection menu.
			cin >> location; //Key in the location number.
			if (location < 1 || location >4) //If user key in invalid location number
			{
				while (location < 1 || location >4)//Let user key in location number again until he or she key in the correct location number.
				{
					cout << "*Invalid location number, please key in again: ";
					cin >> location;
				}
			}
			switch (location) //Do action according to the location number which selected by user.
			{
			case 1: //Select location number 1
			{
				HANDLE colour = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(colour, 11);
				cout << setw(37) << "[-------------------------------]" << endl;
				cout << setw(37) << "| Select location successfully! |" << endl;
				cout << setw(37) << "[-------------------------------]" << endl;
				SetConsoleTextAttribute(colour, 7);
				loct << cname << endl; //Write user's name in location.txt
				loct << address[0] << endl; //Write "Jalan 11,Bukit Mertajam" in location.txt,
				loctmenu(); // Back to location selection menu
				break;
			}
			case 2: //Select location number 2
			{
				HANDLE colour = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(colour, 11);
				cout << setw(37) << "[-------------------------------]" << endl;
				cout << setw(37) << "| Select location successfully! |" << endl;
				cout << setw(37) << "[-------------------------------]" << endl;
				SetConsoleTextAttribute(colour, 7);
				loct << cname << endl;
				loct << address[1] << endl; //Write "Jalan 4, Sungai Jawi" in location.txt.
				loctmenu();
				break;
			}
			case 3: //Select location number 3
			{
				HANDLE colour = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(colour, 11);
				cout << setw(36) << "[-------------------------------]" << endl;
				cout << setw(36) << "| Select location successfully! |" << endl;
				cout << setw(36) << "[-------------------------------]" << endl;
				SetConsoleTextAttribute(colour, 7);
				loct << cname << endl;
				loct << address[2] << endl; //Write "Lorong 7,Sungai Bakap" in location.txt.
				loctmenu();
				break;
			}
			case 4: //Exit location selection menu.
			{
				HANDLE colour = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(colour, 14);
				cout << setw(36) << "[-------------------------------]" << endl;
				cout << setw(36) << "| Thanks for using our service! |" << endl;
				cout << setw(36) << "[-------------------------------]" << endl;
				SetConsoleTextAttribute(colour, 7);
				system("pause");
				system("cls");
			}
			}
			loct.close();
		} while (location != 4);
	}
}
void ReturnCar()//Return module(return car)
{

	bool end = false;
	system("cls");
	do {
		mheader();
		returntitle(); // Display header of interface of return car.
		HANDLE colour = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(colour, 12);
		cout << "    [---------------------------------------------------------------------------------------------------------]\n";
		cout << "    |                          WARNING! After you complete return car,                                        |\n";
		cout << "    |  1. You are not allow to pick your car anymore which you have made order before                         |\n";
		cout << "    |  2. Even though you haven't pick up your car, you are still not allowed to pick your car anymore        |\n";
		cout << "    |  3. So, PLEASE come into this section only after you have pick up your rented car and want to return it |\n";
		cout << "    |  4. If we noticed we haven't received our car, you will get penalty                                     |\n";
		cout << "    [---------------------------------------------------------------------------------------------------------]\n";
		SetConsoleTextAttribute(colour, 7);
		cout << endl;
		SetConsoleTextAttribute(colour, 14);
		cout << "        [------------------------------------------------------------------------------------------------]\n";
		cout << "        | If you wish to give up complete return car and exit this section, here is the steps to exit:   |\n";
		cout << "        | 1.Enter the correct return date format,                                                        |\n";
		cout << "        | 2.Enter 'X' for your name and license plnate number,                                           |\n";
		cout << "        | 3.Enter 'X' for the license plate number,                                                      |\n";
		cout << "        | 4.Enter 'N' to exit this section.                                                              |\n";
		cout << "        | Don't worry, if you have complete return car, you will automatically exit this section.        |\n";
		cout << "        [------------------------------------------------------------------------------------------------]\n\n";
		SetConsoleTextAttribute(colour, 7);
		cout << "Please enter the return date (like 15-April-2023): ";
		cin >> date;
		//If user key in invalid return date, the while loop will let the user key in again until the return date is valid.
		if (date.size() < 10 || date.size() > 17)
		{
			while (date.size() < 10 || date.size() > 17)
			{
				cout << "Invalid format of date, please key in again." << endl;
				cout << ": ";
				cin >> date;
			}
		}
		cin.ignore();

		//Ask user to enter name and license plate number for verification.
		cout << "Please enter your name: ";
		getline(cin, cuname);
		cout << "Please enter the license plate number that you rented: ";
		cin >> carnum;
		cin.ignore();

		ret.open("return.txt", ios::app);
		ren.open("rentCar.txt");
		//Read user's name and the license plate number that rented by user from rentCar.txt.
		while (!ren.eof())
		{
			getline(ren, cnames);
			ren >> carno >> carbrand >> carmodel >> price >> colourss >> tprice;
			//If the user's name and license plate number that key in by the user are matched as those in rentCar.txt, 
			//record user's name and the license platenumber in return.txt.
			if (cnames == cuname && carno == carnum)
			{
				re = true;
				ret << cuname << endl;
				ret << carnum << " " << date << endl;
				break; //if both user's name and license plate number are matched,then exit directly the while loop.
			}
			re = false;
			ren.ignore();
		}
		ren.close();
		ret.close();
		if (re == false) //if user'sname or license plate OR both are not matched.
		{
			HANDLE colour = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(colour, 12);
			cout << "\n**Invalid name or license plate number, please fill in all information again,\n";
			cout << "**You can enter 'Y' to continue key in information of return car or you can enter 'N' to quit this section: ";
			SetConsoleTextAttribute(colour, 7);
			cin >> quit;
			if (quit == 'n' || quit == 'N')
			{
				system("cls");
				break;
			}
			else if (quit == 'y' || quit == 'Y')
			{
				end = false;
				system("cls");
			}

		}
		else if (re == true) //If complete return car successfully.
		{
			HANDLE colour = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(colour, 14);
			cout << "[---------------------------------------]" << endl;
			cout << "| Thanks for renting our car!! Goodbye! |" << endl;
			cout << "[---------------------------------------]" << endl;
			SetConsoleTextAttribute(colour, 7);
			system("pause");
			end = true;
			system("cls");
		}

	} while (end == false);
}
void header()
{
	HANDLE colour = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(colour, 12);
	cout << "\n";
	cout << "	 /$$$$$$$    /$$$$$$$    /$$$$$$   /$$      /$$   /$$$$$$   /$$    /$$" << endl;
	cout << "	/$$___  $$  /$$___  $$  /$$__  $$ | $$$    /$$$  /$$__  $$  | $$  |$$" << endl;
	cout << "       | $$   \\ $$ | $$   \\ $$ | $$  \\ $$ | $$$$  /$$$$ | $$  \\ $$   \\ $$ $$" << endl;
	cout << "       | $$$$$$$ / | $$$$$$$/  | $$  | $$ | $$ $$/$$ $$ | $$$$$$$$    | $$$" << endl;
	SetConsoleTextAttribute(colour, 8);
	cout << "       | $$        | $$$$      | $$  | $$ | $$  $$$| $$ | $$__  $$    / $$$" << endl;
	cout << "       | $$        | $$_ $$    | $$  | $$ | $$\\  $ | $$ | $$  | $$   / $$ $$" << endl;
	cout << "       | $$        | $$ \\ $$   | $$  | $$ | $$ \\/  | $$ | $$  | $$  / $$ | $$" << endl;
	cout << "       | $$        | $$  \\ $$  |  $$$$$$/ | $$     | $$ | $$  | $$ | $$   \\ $$" << endl;
	cout << "       |__/        |__/   |_/   \\______/  |__/     |__/ |__/  |__/ |_/     |_/" << endl;
	SetConsoleTextAttribute(colour, 7);
}
void mheader()
{
	HANDLE colour = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(colour, 12);
	cout << "\n";
	cout << "		 " << "	   /$$$$$$$    /$$$$$$$    /$$$$$$   /$$      /$$   /$$$$$$   /$$    /$$" << endl;
	cout << "		 " << "	  /$$___  $$  /$$___  $$  /$$__  $$ | $$$    /$$$  /$$__  $$  | $$  |$$" << endl;
	cout << "		 " << "       | $$   \\ $$ | $$   \\ $$ | $$  \\ $$ | $$$$  /$$$$ | $$  \\ $$   \\ $$ $$" << endl;
	cout << "		 " << "       | $$$$$$$ / | $$$$$$$/  | $$  | $$ | $$ $$/$$ $$ | $$$$$$$$    | $$$" << endl;
	SetConsoleTextAttribute(colour, 8);
	cout << "		 " << "       | $$        | $$$$      | $$  | $$ | $$  $$$| $$ | $$__  $$    / $$$" << endl;
	cout << "		 " << "       | $$        | $$_ $$    | $$  | $$ | $$\\  $ | $$ | $$  | $$   / $$ $$" << endl;
	cout << "		 " << "       | $$        | $$ \\ $$   | $$  | $$ | $$ \\/  | $$ | $$  | $$  / $$ | $$" << endl;
	cout << "		 " << "       | $$        | $$  \\ $$  |  $$$$$$/ | $$     | $$ | $$  | $$ | $$   \\ $$" << endl;
	cout << "		 " << "       |__/        |__/   |_/   \\______/  |__/     |__/ |__/  |__/ |_/     |_/" << endl;
	SetConsoleTextAttribute(colour, 7);
}
