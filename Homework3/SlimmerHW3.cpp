/* 
 * File:   SlimmerHW3.cpp
 * Author: Jeremy Slimmer id#2132936
 * Prof Dan Stocker
 * Created on March 3, 2013, 2:25 PM
 */

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <limits>

//Listed below is the global constant used for any function;
const double PI = 3.1415926535;
// also all variables have been declared locally
using namespace std;
/*below is the declarations of menu, switch, and input functions used*/
int get_main_menu_choice();
int main_menu();
int get_circle_menu();
int circle_menu();
int get_sphere_menu();
int sphere_menu();
int get_rectangle_menu();
int rectangle_menu();
int checkentryformenu();
double checkEntryforchar();
double get_user_input(string input_type);
/*below is the declaration of the functions  used 
 *for the various formulas for which the program is written.
 *the functions  are listed following main().
 */
double CircleArea(double radius);
double CircleCircumference(double radius);
double CylinderVolume(double radius, double height);
double CylinderSurfaceArea(double radius, double height);
double SphereVolume(double radius);
double SphereSurfaceArea(double radius);
double ConeVolume(double radius, double height);
double ConeSurfaceArea(double radius, double height);
double PerimeterRectangle(double length, double height);
double RectangleArea(double length, double height);
double VolumeRectangularSolid(double length, double height, double width);
double SurfaceAreaRectangularSolid(double length, double height, double width);
void output(double calculation, string type, string operation);

int main(int argc, char *argv[]) {
    cout << "Welcome to Geometry'R'Us" << endl << endl;
    main_menu(); // calls the main menu
    cout << endl;
    cout << endl;
    cout << "Thank You for using Geometry'R'Us!" << endl;
    return 0;
}

int get_main_menu_choice() {
    // this displays the menu and gathers input
    int menu_choice;
    cout << "Please enter the proper menu selection:" << endl;
    do {
        cout << "Enter 1 for Circles and Cylinders" << endl;
        cout << "Enter 2 for Spheres and Cones" << endl;
        cout << "Enter 3 for Squares and Rectangular Solids" << endl;
        cout << "Enter 4 or 5 to Exit" << endl;

        menu_choice = checkentryformenu();
        /*the function - checkentry for menu - above gathers the input
         from the user to pass to the switch*/
    } while ((menu_choice < 1) || (menu_choice > 5));
    return menu_choice;
}

double checkEntryforchar() {
    /*all inputs are run through this function to filter bad data
     this keeps the cin buffer from being short circuited due to char inputs*/
    double user_input = 0;
    while (!(cin >> user_input)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Please enter a valid number " << endl;

    }
    return user_input;
}

int checkentryformenu() {
    /*this also uses the checkentry function to verify input before
     doing its own check of a proper menu selection*/
    int user_input = 0;
    do {

        user_input = checkEntryforchar();
        if ((user_input < 1) || (user_input > 5)) {
            cout << "Please enter the proper menu selection:" << endl;
        }
    } while ((user_input < 1) || (user_input > 5));
    return user_input;
}

int main_menu() {
    
    /* this is the main menu switch form this the user call the 
     * functions for the various menus
     * also case 4 is blank on purpose for expansion and
     * is currently set to change the menu_choice var to 5 to exit
     * this way no extra edge case didn't have to be accounted for.
     */
    int menu_choice = 0;
    do {

        menu_choice = get_main_menu_choice();

        switch (menu_choice) {

            case 1:
                circle_menu();
                break;

            case 2:
                sphere_menu();
                break;

            case 3:
                rectangle_menu();
                break;

            case 4:
                menu_choice = 5;
                break;


            case 5:
                menu_choice = 5;

                break;

        }
    } while (menu_choice < 5);
    return 5;
}

int get_circle_menu() {
    // user prompt and input for the user for circle sub-menu;
    
    cout << "Circles and Cylinders: " << endl;
    int menu_choice = 0;
    do {

        cout << "Choose 1 for the Area of a Circle:" << endl;
        cout << "Choose 2 for the Circumference of a Circle:" << endl;
        cout << "Choose 3 for the Volume of a Cylinder:" << endl;
        cout << "Choose 4 for the Surface Area of a Cylinder:" << endl;
        cout << "Choose 5 to exit:" << endl << endl;
        cout << "Please select the formula you wish to use:" << endl;
        menu_choice = checkentryformenu();
        //also uses the checkentry to screen inputs
    } while ((menu_choice < 1) || (menu_choice > 5));
    return menu_choice;
}

int circle_menu() {
    /*this is the first submenu
     this uses strings for each function called these are then sent for the
     output () as fill in the blank in the output statement
     switch runs in a do while loop for menu repeating by the user. 
     */
    int menu_choice;
    double radius = 0;
    double height = 0;
    double calculation = 0;
    string shape;// used to send the output () the correct shape
    string operation;//used to send the output() the correct formula type ie. area or volume
    string input_type; //used to send the get_input the fill in the blank 
    do {
        menu_choice = 0;
        menu_choice = get_circle_menu();
        cout << endl;
        switch (menu_choice) {
            case 1:
                //circle area
                shape = "circle";
                operation = "area";
                input_type = "radius";
                radius = get_user_input(input_type);
                calculation = CircleArea(radius);
                output(calculation, shape, operation);
                break;

            case 2:
                //circle circumference 
                shape = "circle";
                operation = "circumference";
                input_type = "radius";
                radius = get_user_input(input_type);
                calculation = CircleCircumference(radius);
                output(calculation, shape, operation);
                break;

            case 3:
                //cylinder volume
                shape = "cylinder";
                operation = "volume";
                input_type = "radius";
                radius = get_user_input(input_type);
                input_type = "height";
                height= get_user_input(input_type);
                calculation = CylinderVolume(radius, height);
                output(calculation, shape, operation);
                break;
            case 4:
                //cylinder surface area
                shape = "cylinder";
                operation = "surface area";
                input_type = "radius";
                radius = get_user_input(input_type);
                input_type = "height";
                height= get_user_input(input_type);
                calculation = CylinderSurfaceArea(radius, height);
                output(calculation, shape, operation);
                break;

            case 5:

                break;


        }
    } while (menu_choice < 5);
}

double get_user_input(string input_type) {
    /*this gets input for calculations from the user
     uses the check for filter*/
    cout<<"Remember this program does not track or handle units of measurement!! "<<endl;
    cout<<"Please enter units accordingly"<<endl;
    double user_input = 0;
    cout << "Please enter the "<<input_type<<" :"<< endl;
    user_input = checkEntryforchar();
    return user_input;
}

double CircleCircumference(double radius) {
    //calculation for circle circumference
    return ((radius * 2) * PI);
}

double CircleArea(double radius) {
     //calculation for circle area
    return (PI * (radius * radius));
}

double CylinderVolume(double radius, double height) {
     //calculation for cylinder volume
    return ((height * PI) * (radius * radius));
}

double CylinderSurfaceArea(double radius, double height) {
    //calculation for cylinder surface area
    return ((height * (PI * radius * 2))+((radius * radius)*(2 * PI)));
}

int get_sphere_menu() {
    int menu_choice;
    //sub menu selection for spheres and cones also uses check to filter input
    cout << "Spheres and Cones:  " << endl; 
    do {
        cout << "Spheres:" << endl << endl;
        cout << "Choose 1 for the Volume of a Sphere:  " << endl;
        cout << "Choose 2 for the Surface Area of a Sphere:  " << endl << endl;
        cout << "Cones:" << endl << endl;
        cout << "Choose 3 for the Volume of a Cone:  " << endl;
        cout << "Choose 4 for the Surface Area of a Cone" << endl;
        cout << "Choose 5 to EXIT" << endl << endl;
        cout << "Please select the Formula you wish to use: " << endl;
        menu_choice = checkentryformenu();
    } while ((menu_choice < 1) || (menu_choice > 5));
    return menu_choice;
}

int sphere_menu() {
    /*this is the second submenu
     this uses strings for each function called these are then sent for the
     output () as fill in the blank in the output statement
     switch runs in a do while loop for menu repeating by the user. 
     */
    int menu_choice;
    double radius = 0;
    double height = 0;
    double calculation = 0;
    string shape;
    string operation;
    string input_type;
    do {
        menu_choice = 0;
        menu_choice = get_sphere_menu();
        cout << endl;
        switch (menu_choice) {
            case 1://Sphere volume function
                shape = "sphere";
                operation = "volume";
                input_type = "radius";
                radius = get_user_input(input_type);
                calculation = SphereVolume(radius);
                output(calculation, shape, operation);
                break;

            case 2://Sphere Surface Area function
                shape = "sphere";
                operation = "surface area";
                input_type = "radius";
                radius = get_user_input(input_type);
                calculation = SphereSurfaceArea(radius);
                output(calculation, shape, operation);
                break;

            case 3://Volume of cone function
                shape = "cone";
                operation = "volume";
                input_type = "radius";
                radius = get_user_input(input_type);
                input_type = "height";
                height = get_user_input(input_type);
                calculation = ConeVolume(radius, height);
                output(calculation, shape, operation);
                break;

            case 4:// Surface Area of a cone
                shape = "cone";
                operation = "surface area";
                input_type = "radius";
                radius = get_user_input(input_type);
                input_type = "height";
                height= get_user_input(input_type);
                calculation = ConeSurfaceArea(radius, height);
                output(calculation, shape, operation);
                break;

            case 5:

                break;

        }

    } while (menu_choice <= 4);

}

double SphereVolume(double radius) {
     //calculation for sphere volume
    return ((4 / 3) * PI * (radius * radius * radius));
}

double SphereSurfaceArea(double radius) {
    //calculation for sphere surface area
    return ((4 * PI)*(radius * radius));
}

double ConeSurfaceArea(double radius, double height) {
    //calculation for cone surface area
    return ((PI * radius)+((PI * radius)*(sqrt((radius * radius)*(height * height)))));
}

double ConeVolume(double radius, double height) {
    //calculation for cone surface area
    return (((PI * (radius * radius)) * height) / 3);
}

int get_rectangle_menu() {
    /*this is the input function and user prompt 
     * that drives the rectangle menu switch
     *as before uses the check to filter data 
     */
    int menu_choice;
    cout << "Squares, Rectangles, and Rectangular Solids:" << endl;
    do {
        cout << "Choose 1 for the Perimeter of a Square or Rectangle:" << endl;
        cout << "Choose 2 for the Area of a Square or Rectangle:" << endl;
        cout << "Choose 3 for the Volume of a Rectangular Solid:" << endl;
        cout << "Choose 4 for the Surface Area of a Rectangular Solid:"<<endl;
        cout << "Choose 5 to Exit" << endl;
        cout << "Please select the Formula you wish to use: " << endl;
        menu_choice = checkentryformenu();
    } while ((menu_choice < 1) || (menu_choice > 5));
    return menu_choice;
}

int rectangle_menu() {
    /*this is the final submenu
     *this uses strings for each function called these are then sent for the
     *output () as fill in the blank in the output statement
     *switch runs in a do while loop for menu repeating by the user. 
     *also this switch has added if elses in each of the cases
     * this does a comparison to the inputs and if they are the the same to
     * determine the appropriate statement to assign to the string for the 
     * ouput*/
    int menu_choice;
    double length = 0;
    double width = 0;
    double height = 0;
    double calculation = 0;
    string shape;
    string operation;
    string input_type;
    do {
        menu_choice = 0;
        menu_choice = get_rectangle_menu();
        cout << endl;
        switch (menu_choice) {
            case 1:
                input_type = "length";
                length = get_user_input(input_type);
                input_type = "width";
                width = get_user_input(input_type);
                if (width == length) {
                    shape = "square";
                } else {
                    shape = "rectangle";
                }
                operation = "perimeter";
                calculation = PerimeterRectangle(length, width);
                output(calculation, shape, operation);
                break;

            case 2:
                input_type = "length";
                length = get_user_input(input_type);
                input_type = "width";
                width = get_user_input(input_type);
                if (width == length) {
                    shape = "square";
                } else {
                    shape = "rectangle";
                }
                operation = "area";
                calculation = RectangleArea(length, width);
                output(calculation, shape, operation);
                break;

            case 3:
                input_type = "length";
                length = get_user_input(input_type);
                input_type = "height";
                height = get_user_input(input_type);
                input_type = "width";
                width = get_user_input(input_type);
                if ((width == length) && (width == height)) {
                    shape = "cube";
                } else {
                    shape = "rectangular solid";
                }
                operation = "volume";
                calculation = VolumeRectangularSolid(length, height, width);
                output(calculation, shape, operation);
                break;

            case 4:
                input_type = "length";
                length = get_user_input(input_type);
                input_type = "height";
                height = get_user_input(input_type);
                input_type = "width";
                if ((width == length) && (width == height)) {
                    shape = "cube";
                } else {
                    shape = "rectangular solid";
                }
                operation = "surface area";
                calculation = SurfaceAreaRectangularSolid(length, height, width);
                output(calculation, shape, operation);
                break;

            case 5:

                break;

        }

    } while (menu_choice <= 4);


}

double RectangleArea(double length, double width) {
    //calculation for rectangle area
    return (length * width);
}

double PerimeterRectangle(double length, double width) {
    //calculation for rectangle perimeter
    return ((2 * length) +(2 * width));
}

double VolumeRectangularSolid(double length, double height, double width) {
    //calculation for rectangle volume
    return (length * width * height);
}

double SurfaceAreaRectangularSolid(double length, double height, double width) {
    //calculation for rectangle solid surface area
    return ((2 * (length * width))+(2 * (height * length))+(2 * (width * height)));
}

void output(double calculation, string shape, string operation) {
    /*this is the only output to the user 
     its designed to be super simple
     it uses the strings to fill in the blanks in the output statement*/
    cout << "The " << operation
            << " of the " << shape
            << " equals " << calculation
            << endl << endl;
}