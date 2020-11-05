#include<iostream>
#include<fstream>
#include<string>
#include <sstream>
using namespace std;

#define GPIO_PATH "/sys/class/gpio"

void writeGPIO(string filename, string value){
	fstream fs;
	string path(GPIO_PATH);
	fs.open((path + filename).c_str(), fstream::out);
	fs << value;
	fs.close();
}

int main(int argc, char* argv[]){
	   if(argc!=3){
		cout << "Usage is: control_GPIO gpio_number state" << endl;
		cout << " gpio number: GPIO number to contro " << endl;
		cout << " state: hi or low " << endl;
			return 2;
				}
	      string cmd(argv[2]);
	      string gpio_number(argv[1]);
	      cout << "Starting the control GPIO program" << endl;
	      cout << "The current GPIO Path is: " << GPIO_PATH << endl;

	      ostringstream s;
	      s << "gpio" << gpio_number; // concatenates a number to gpio; e.g. gpio60
	      string name = string(s.str()); // converts stream to string. 

	  if(cmd=="hi"){
		 cout << "Turning the LED on" << endl;
		 writeGPIO("/"+name+"/direction","out");
		 writeGPIO("/"+name+"/value", "1");
		       }
	  else if (cmd=="low"){
		 cout << "Turning the LED off" << endl;
		 writeGPIO("/"+name+"/direction","out");
	         writeGPIO("/"+name+"/value", "0");
	
			       }
}
