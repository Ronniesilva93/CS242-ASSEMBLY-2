#include<iostream>
using namespace std;

int main() {
	//declorations
	int radius;
	int surfaceArea;
	int volume;
	const int PINUMER = 355;
	const int PIDENOM = 113;

	//get user input

	cout << "Enter the whole number radius: ";
	cin >> radius;

	//calculation

	_asm {
	call calcVolume
	call calcSurfaceArea
	jmp quit
		
	calcVolume:
		mov eax, PINUMER
			mov ebx, 4
			mul ebx
			mov ebx, radius
			mul ebx;the repition solves radius cubed
			mul ebx
			mul ebx
			xor edx, edx
			mov ebx, 3
			div ebx
			xor edx, edx
			div PIDENOM ;divides the bottom num of PI
			mov volume, eax
			ret

	calcSurfaceArea:
		mov eax, PINUMER
			mov ebx, 4
			mul ebx
			mov ebx, radius
			mul ebx ;the repition solves radius cubed
			mul ebx 
			xor edx,edx
			div PIDENOM
			mov surfaceArea,eax
			ret

	quit:

	}

	//output
	cout << "The surface area of the sphere is " << surfaceArea << endl;
	cout << "The volume of the sphere is  " << volume << endl;

	system("pause");
	return 0;
 }