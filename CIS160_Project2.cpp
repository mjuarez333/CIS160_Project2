/*
	Name: Miguel Juarez
	Date: 10/18/2022
	Class: CIS 160 Fundamentals of Computer Science I
	Project Name: PCCC Carpet Billing
	Description: Computerized billing system that displays customer information and calculate the customer's carpet bill
*/

//Preprocessor directives needed for program
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

//LABOR is the cost of labor per sq ft and TAX is the rate of tax added on to the bill
const float LABOR = 5.95, TAX = 0.06825;

int main()
{
	string name; //holds full name of the customer
	int size; //size of carpet ordered in sq ft
	float length; //length of room in ft
	float width; //width of room in feet
	float price; //cost of the carpet per sq ft
	float discount; //discount rate to deduct from cost of carpet
	float cCost; //total cost of carpet calculated(size*price)
	float lCost; //total cost of labor calculated(size*LABOR)
	float installed; //sum of labor and carpet costs
	float discountPrice; //amount to deduct from carpet cost after applying doscount rate
	float subTotal; //amount after deducting the discount price 
	float tax; //amount of tax to be added with TAX rate
	float total; //total cost of the bill after adding tax
	string line; //adds a line above the subtotal price for formatting
	line.assign(10, '_');

	//Receives input of user for customer's name, room dimensions, carpet cost and discount rate
	cout << "Customer Name: ";
	getline(cin, name);
	cout << "\nRoom's Length: ";
	cin >> length;
	cout << "\nRoom's Width: ";
	cin >> width;
	cout << "\nPrice / Sq Ft: ";
	cin >> price;
	cout << "\nDiscount Rate: ";
	cin >> discount;

	/*calculations done for total area of carpet bought and the cost of the carpet.
	* Accounting for labor cost, discount, and tax to finalize pricing. */
	size = ceil(length * width);
	cCost = size * price;
	lCost = size * LABOR;
	installed = lCost + cCost;
	discount /= 100;
	discountPrice = installed * discount;
	subTotal = installed - discountPrice;
	tax = subTotal * TAX;
	total = subTotal + tax;

	//Bill formatted to display customer pricing information
	cout << "\n\nWelcome to Passaic County Carpeting Company" << endl;
	cout << "\nCustomer information:" << endl;
	cout << "\tCustomer Name:\t" << name << endl;
	cout << "\tCarpet Size:\t" << size << " Square Feet" << endl;
	cout << "\nCharges:" << endl;
	cout << fixed << showpoint << setprecision(2); //displays all prices with only 2 digits after the decimal
	cout << "\tCarpet Cost: @ $" << price << " Sq Ft\t$" << cCost << endl;
	cout << "\tLabor Cost:  @ $" << LABOR << " Sq Ft\t$" << lCost << endl;
	cout << "\n\tInstalled Price:\t\t$" << installed << endl;
	cout << "\tDiscount:\t\t\t$" << discountPrice << endl;
	cout << "\t\t\t\t\t" << line << endl;
	cout << "\tSubTotal:\t\t\t$" << subTotal << endl;
	cout << "\n\tTaxes:\t\t\t\t$" << tax << endl;
	cout << "\n\tTotal Cost:\t\t\t$" << total << endl;
	cout << "\n" << name << ", Thank You for Using PCCC Carpeting\n\n\n";
	cin.get();

	return 0;
}