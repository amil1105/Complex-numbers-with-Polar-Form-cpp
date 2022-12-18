#include <iostream>
#include <math.h> // for math calculation...

using namespace std;

void input();
void menu();

int menuSelect = 0;

const double PI = 3.141592653589793238462643383279502884;


double real1, real2, imag1, imag2 = 0;

// The Class of Complex Numbers
class Complex
{
private:
	double real;
	double imag;

public:

	Complex(double g = 0, double s = 0)
	{
		real = g;
		imag = s;
	}

	void print();

	void PolarShow(Complex); // the Show polar form for add,sub,multiplication,division function.
	void polarOperation(Complex); // Polar representation according to the values entered in the 5th option in the menu.

	Complex operator+ (Complex obj)
	{
		Complex comp;
		comp.real = real + obj.real;
		comp.imag = imag + obj.imag;

		return comp;

	}

	Complex operator- (Complex obj)
	{
		Complex comp;
		comp.real = real - obj.real;
		comp.imag = imag - obj.imag;

		return comp;
	}

	Complex operator* (Complex obj)
	{
		Complex comp;
		comp.real = real * obj.real - imag * obj.imag;
		comp.imag = imag * obj.real + real * obj.imag;

		return comp;
	}

	Complex operator/ (Complex obj)
	{
		Complex comp;
		comp.real = (real * obj.real + imag * obj.imag) / (obj.real * obj.real + obj.imag * obj.imag);
		comp.imag = (imag * obj.real - real * obj.imag) / (obj.real * obj.real + obj.imag * obj.imag);

		return comp;
	}

	Complex operator+= (Complex obj)
	{
		Complex comp;
		comp.real += real + obj.real;
		comp.imag += imag + obj.imag;

		return comp;

	}

	Complex operator-= (Complex obj)
	{
		Complex comp;
		comp.real -= real - obj.real;
		comp.imag -= imag - obj.imag;

		return comp;
	}

	Complex operator*= (Complex obj)
	{
		Complex comp;
		comp.real *= real * obj.real - imag * obj.imag;
		comp.imag *= imag * obj.real + real * obj.imag;

		return comp;
	}

	Complex operator/= (Complex obj)
	{
		Complex comp;
		comp.real /= (real * obj.real + imag * obj.imag) / (obj.real * obj.real + obj.imag * obj.imag);
		comp.imag /= (imag * obj.real - real * obj.imag) / (obj.real * obj.real + obj.imag * obj.imag);

		return comp;
	}




};

void Complex::print() // print the result to screen
{

	if (imag > 0)
		cout << real << "+" << imag << "i" << endl;
	else if (imag < 0)
	{
		cout << real << "" << imag << "i" << endl;
	}
	else if (real == 0) {
		cout << imag << "i" << endl;
	}
	else
	{
		cout << real << endl;
	}
}




// Function that calculates the polar form of values.
void Complex::PolarShow(Complex)
{
	double absolute = sqrt(pow(imag, 2) + pow(real, 2));
	double r = atan(imag / real);
	r *= 180 / PI;

	if (imag == 0) {
		cout << "\nPolar Form: 0\n";
	}
	else if (real == 0) {
		cout << "\nNo Polar Form...\n";
	}
	else {
		cout << "\nPolar Form: " << absolute << " * cis(" << r << "°)\n";
	}

}

void  input() {
	cout << "Enter the real part of 1. number: " << endl;
	cin >> real1;
	cout << "Enter the imaginary part of 1. number:" << endl;
	cin >> imag1;
	cout << "Enter the real part of 2. number:" << endl;
	cin >> real2;
	cout << "Enter the imaginary part of 2. number:" << endl;
	cin >> imag2;
}


// Function that performs the operation according to the Menu Selection.
void CalcOperation()
{
	Complex k1(real1, imag1);
	Complex k2(real2, imag2);
	if (menuSelect == 1)
	{
		Complex k3 = k1 + k2;
		k3.print();
		k3.PolarShow(k3);
	}

	else if (menuSelect == 2)
	{
		Complex k3 = k1 - k2;
		k3.print();
		k3.PolarShow(k3);
	}
	else if (menuSelect == 3)
	{
		Complex k3 = k1 * k2;
		k3.print();
		k3.PolarShow(k3);
	}
	else if (menuSelect == 4)
	{
		Complex k3 = k1 / k2;
		k3.print();
		k3.PolarShow(k3);
	}


}
// Function that makes polar form according to the entered values.
void polarOperation() {
	double real, imag;
	cout << "Enter the real part of the number: " << endl;
	cin >> real;
	cout << "Enter the imaginary part of the number: " << endl;
	cin >> imag;
	double absolute = sqrt(pow(imag, 2) + pow(real, 2));
	double r = atan(imag / real);
	r *= 180 / PI;

	if (imag == 0) {
		cout << "\nPolar Form: 0\n";
	}
	else if (real == 0) {
		cout << "\nNo Polar Form...\n";
	}
	else {
		cout << "\nPolar Form: " << absolute << " * cis(" << r << "°)\n";
	}
}

// Menu Function.
void menu() {
	cout << "\tCOMPLEX NUMBERS\n\n";
	cout << "[ 1 ] Sum of two complex numbers\n";
	cout << "[ 2 ] Subtract two complex numbers\n";
	cout << "[ 3 ] Multiplying two complex numbers\n";
	cout << "[ 4 ] Divide two complex numbers\n";
	cout << "[ 5 ] Polar Form\n";
	cin >> menuSelect;

	switch (menuSelect)
	{
	case 1:
		input();
		CalcOperation();
		system("pause"); // Wait until you press a key.
		system("cls"); // clear screen.
		menu();
		break;
	case 2:
		input();
		CalcOperation();
		system("pause");
		system("cls");
		menu();
		break;
	case 3:
		input();
		CalcOperation();
		system("pause");
		system("cls");
		menu();
		break;
	case 4:
		input();
		CalcOperation();
		system("pause");
		system("cls");
		menu();
		break;
	case 5:
		polarOperation();
		system("pause");
		system("cls");
		menu();
		break;
	default: // other cases...
		cout << "Wrong choice..." << endl;
		system("pause");
		system("cls");
		menu();
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "");
	menu();
	system("pause");
	return 0;
};





