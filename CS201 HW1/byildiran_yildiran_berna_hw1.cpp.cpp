#include<iostream>
#include<string>

using namespace std;

int main()
{
	string name;
	double priceOutCalls, billOutCalls, priceInCalls, billInCalls, priceIntperMB, usedGB, billInt, priceSMS, billSMS;
	double allRoamingBill, tax, totalBill;
	int minutesOutCalls, minutesInCalls, numberSMS;

    cout << "Please enter your name: "; // asking for the namez
	cin >> name;
	cout << endl;

	cout << name << ", please enter the price for outgoing call per minute: "; // asking for the price of outgoing calls per minute
	cin >> priceOutCalls ;

	cout << name << ", please enter how many minutes you have talked in outgoing calls: "; // asking for the minutes you have talked in outgoing calls
	cin >> minutesOutCalls;

	billOutCalls = priceOutCalls * minutesOutCalls; // calculate the total bill of outgoing calls
	cout << name << ", you have spent " << billOutCalls << " TL for outgoing calls you made while you are abroad."; 
	cout << endl << endl;

	cout << name << ", please enter the price for incoming call per minute: "; // asking for the price for incoming call per minute
	cin >> priceInCalls;

	cout << name << ", please enter how many minutes you have talked in incoming calls: " // asking for the minutes you have talked in incoming calls
	cin >> minutesInCalls;

	billInCalls = priceInCalls * minutesInCalls; // calculate the total bill of incoming calls
	cout << name << ", you have spent " << billInCalls << " TL for incoming calls you made while you are abroad.";
	cout << endl << endl;

	cout << name << ", please enter the price for internet usage per MB: "; // asking for the price for internet usage per MB
	cin >> priceIntperMB;

	cout << name << ", please enter how many GBs you have used: "; // asking for the GBs you have used
	cin >> usedGB;

	billInt = priceIntperMB * usedGB * 1024; // calculate the total bill of internet usage
	cout << name << ", you have spent " << billInt << " TL for the internet while you are abroad.";
    cout << endl << endl;

	cout << name << ", please enter the price for one SMS: "; // asking for the price for one SMS
	cin >> priceSMS;

	cout << name << ", please enter the number of SMS you have sent: "; // askig for the  the number of SMS you have sent
	cin >> numberSMS;

	billSMS = priceSMS * numberSMS; // calculate the total bill of SMS
	cout << name << ", you have spent " << billSMS << " TL for the SMS while you are abroad.";
	cout << endl << endl;

	allRoamingBill = billSMS + billInt + billInCalls + billOutCalls; // calculate the total bill for roaming services without tax
	cout << name << ", total cost for all roaming services is " << allRoamingBill << " TL." << endl;

	tax = allRoamingBill * 18 / 100; // calculate the tax
	cout << name << ", tax is " << tax << " TL." << endl;

	totalBill = allRoamingBill + tax; // calculate the total bill for roaming services with tax
	cout << name << ", total roaming bill fee with tax is "<< totalBill << " TL." << endl;


	return 0;
}