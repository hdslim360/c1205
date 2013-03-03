/* 
 * File:   Geometry
 * Author: Jeremy Slimmer
 * CSCI-1205 Prof. Dan Stocker
 * Created on February 4, 2013, 5:37 PM
 * Homework Assignment #2 
 */

#include <iostream>
#include <cstdlib>
#include <cmath>


//Listed below are the global variables used for any function;
//these are generic and can be used by all functions, instance variables
//needed by certain objects will be declared within them.

//using enums to make sure that menu choice varibles can't be changed 
enum mainchoice {CIRCLES_CYLINDERS = 1, SPHERES_CONES = 2, RECTANGLES = 3 , EXIT = 5}
enum circlechoice {CIRCLE_AREA = 1, CIRCLE_CIRCUM = 2, CYL_VOLUME = 3, CYL_SURFACEAREA = 4, EXIT = 5};
enum spherechoice {}



const float PI = 3.1415926535;
float length = 0;
float width = 0;
float base = 0;
float height = 0;
float radius = 0;
float Cyldepth = 0;
float depth = 0;


using namespace std;


int MainMenu(int menuChoice);
int Circle_CylMenu (int Circle_menu);
int Sphere_ConeMenu (int Sphere_menu);
int SquareMenu (int Square_menu);

//below is the declaration of the objects used 
//for the various formulas for which the program is written.
//the objects are listed following main().

float CircleArea(float radius);
float CircleCircumference(float radius);

float CylinderVolume(float radius, float Cyldepth);
float CylinderSurfaceArea(float radius, float Cyldepth);

float PerimeterRectangle(float length, float height);
float RectangleArea(float length, float height);
float VolumeRectangularSolid(float length, float height, float depth);

float SphereVolume(float radius);
float SphereSurfaceArea(float radius);

float ConeVolume(float radius, float height);
float ConeSurfaceArea(float radius, float height);


int main(int argc, char *argv[]) {
    int menuChoice; // menu switch variable for main menu
	int Circle_menu;
	int Sphere_menu;
	int Square_menu; 
	


	cout << "Welcome to Geometry'R'Us" << endl << endl;

    /*The switches used are nested within one another as well as
     * enclosed with in do-while and while loops this gives the user the
     * ability to move up and down within the menu structure so that once 
     * the exit choice was selected it would not end the program all together.
     */

    do {
        cout << "Please select one from the following menu items:" << endl << endl;
        cout << "Enter 1 for Circles and Cylinders" << endl;
        cout << "Enter 2 for Spheres and Cones" << endl;
        cout << "Enter 3 for Squares and Rectangular Solids" << endl;

        cout << "Enter 5 to Exit" << endl;
        cin >> menuChoice;
		while ((menuChoice>5)||(menuChoice==4)) // to handle bad user data for integers char will short circuit
		{ 
			cout<< menuChoice<<" is not a valid choice"<<endl;
			cout<<"Please enter a new choice"<<endl;
			cin>>menuChoice;
		}


        cout << endl;
        cout << endl;
		mainmenu(menuChoice);

        switch (menuChoice) {
            case ChoiceA:
                do {
                    cout << "Circles and Cylinders: " << endl; //submenu 1 selection for circles and cylinders

                    menuChoice = 0;
                    cout << "Please select the formula you wish to use:" << endl;
                    cout << "Choose 1 for the Area of a Circle:" << endl;
                    cout << "Choose 2 for the Circumference of a Circle:" << endl;
                    cout << "Choose 3 for the Volume of a Cylinder:" << endl;
                    cout << "Choose 4 for the Surface Area of a Cylinder:" << endl;
                    cout << "Choose 5 to exit:" << endl << endl;
                    cin >> menuChoice;
					
					while (menuChoice>5)
							{ 
								cout<< menuChoice<<" is not a valid choice"<<endl;
								cout<<"Please enter a new choice"<<endl;
								cin>>menuChoice;
							}


                    switch (menuChoice) {
                        case ChoiceA:

                            //circle function for radius calc
                            cout << "Please enter the radius of the circle " << endl;
                            cout << "you wish to calculate the area for: " << endl;
                            cin >> radius;
                            cout << endl;
                            CircleArea(radius);

                            break;
                        case ChoiceB:

                            //circle circumference 
                            cout << "Please enter the radius of the circle " << endl;
                            cout << "you wish to calculate the circumference for: " << endl;
                            cin >> radius;
                            cout << endl;
                            CircleCircumference(radius);
                            break;
                        case ChoiceC:

                            //cylinder volume
                            cout << "Please enter the radius of the cylinder:" << endl;
                            cout << " you wish to calculate the volume for: " << endl;
                            cin >> radius;
                            cout << endl;
                            cout << "Please enter the depth of the cylinder: " << endl;
                            cout << endl;
                            cin >> Cyldepth;
                            CylinderVolume(radius, Cyldepth);
                            break;

                        case ChoiceD:
                            //cylinder surface area
                            cout << "Please enter the radius of the cylinder:" << endl;
                            cout << " you wish to calculate the Surface Area for: " << endl;
                            cin >> radius;
                            cout << endl;
                            cout << "Please enter the depth of the cylinder: " << endl;
                            cout << endl;
                            cin >> Cyldepth;
                            CylinderSurfaceArea(radius, Cyldepth);
                            break;

                        case Exit:

                            break;

                        default:

                            break;

                    }//closing submenu switch
                } while (menuChoice != 5); ///allows the menu to have more than one iteration

                menuChoice = 0; //resets the menu switch

                break; // closes out main menu choice 1 


            case ChoiceB:

                do { //set up the abitlity to run more than one formula
                    cout << "Spheres and Cones:  " << endl; //sub menu selection for spheres and cones
                    cout << "Please select the Formula you wish to use: " << endl << endl;
                    cout << "Choose 1 for the Volume of a Sphere:  " << endl;
                    cout << "Choose 2 for the Surface Area of a Sphere:  " << endl;
                    cout << "Choose 3 for the Volume of a Cone:  " << endl;
                    cout << "Choose 4 for the Surface Area of a Cone" << endl;
                    cout << "Choose 5 to EXIT" << endl;
                    cin >> menuChoice;
						
						while (menuChoice>5)
						{ 
							cout<< menuChoice<<" is not a valid choice"<<endl;
							cout<<"Please enter a new choice"<<endl;
							cin>>menuChoice;
						}
						
                    switch (menuChoice) {
                        case ChoiceA://Sphere volume function
                            cout << "Please enter the radius of the sphere " << endl;
                            cout << " you wish to calculate the volume for: " << endl;
                            cin >> radius;
                            cout << endl;
                            SphereVolume(radius);
                            break;

                        case ChoiceB://Sphere Surface Area function
                            cout << "Please enter the radius of the sphere " << endl;
                            cout << " you wish to calculate the Surface Area for: " << endl;
                            cin >> radius;
                            cout << endl;
                            SphereSurfaceArea(radius);
                            break;



                        case ChoiceC://Volume of cone function
                            cout << "Please enter the radius of the cone " << endl;
                            cout << " you wish to calculate the Volume for: " << endl;
                            cin >> radius;
                            cout << endl;
                            cout << "Please enter the height of the cone " << endl;
                            cout << " you wish to calculate the Volume for: " << endl;
                            cin >> height;
                            cout << endl;
                            ConeVolume(radius, height);
                            break;


                            break;

                        case ChoiceD:// Surface Area of a cone
                            cout << "Please enter the radius of the cone " << endl;
                            cout << " you wish to calculate the Surface Area for: " << endl;
                            cin >> radius;
                            cout << endl;
                            cout << "Please enter the height of the cone " << endl;
                            cout << " you wish to calculate the Surface Area for: " << endl;
                            cin >> height;
                            cout << endl;
                            ConeSurfaceArea(radius, height);
                            break;

                        case Exit:

                            break;

                        default:

                            break;


                    }

                } while (menuChoice != 5);

                menuChoice = 0;

                break;

            case ChoiceC:
                do {
                    menuChoice = 0;
                    cout << "Please select the formula you wish to use" << endl;
                    cout << "Squares, Rectangles, and Rectangular Solids:" << endl;
                    cout << "Choose 1 for the Perimeter of a Square or Rectangle:" << endl;
                    cout << "Choose 2 for the Area of a Square or Rectangle:" << endl;
                    cout << "Choose 3 for the Volume of a Rectangular Solid:" << endl;
                    cout << "Choose 5 to EXIT" << endl;

                    cin >> menuChoice;

					while ((menuChoice>5)||(menuChoice==4))
					{ 
						cout<< menuChoice<<" is not a valid choice"<<endl;
						cout<<"Please enter a new choice"<<endl;
						cin>>menuChoice;
					}

                    switch (menuChoice) {
                        case ChoiceA:

                            //function for rectangle or square are calc 
                            cout << "Please enter the length for the rectangle you wish to calculate the Perimeter of:" << endl;
                            cin >> length;
                            cout << endl;
                            cout << "Now enter the height" << endl;
                            cin >> height;
                            PerimeterRectangle(length, height);

                            break;
                        case ChoiceB:
                            //rectangular area
                            cout << "Please enter the length for the rectangle you wish to calculate the area of:" << endl;
                            cin >> length;
                            cout << endl;
                            cout << "Now enter the height" << endl;
                            cin >> height;


                            RectangleArea(length, height);
                            break;
                        case ChoiceC:

                            //Rectangular Solid volume
                            cout << "Please enter the length for the rectangular solid  you wish to calculate the Volume of:" << endl;
                            cin >> length;
                            cout << endl;
                            cout << "Now enter the height" << endl;
                            cin >> height;
                            cout << endl << "Now enter the depth:" << endl;
                            cin >> depth;
                            VolumeRectangularSolid(length, height, depth);
                            break;

                        case Exit:

                            break;

                        default:

                            break;
                    }
                } while (menuChoice != 0);
                menuChoice = 0;
                break;

            case Exit:

                cout << "Thank You for using Geometry'R'Us!" << endl;

                break;
            default:

                break;
        }
    } while (menuChoice != 5);

    return (0);
}


int mainmenu(int menuChoice)
{
	
	
	
	
}






float CircleCircumference(float radius) {
    char cont;
    float circumference = 0;
    circumference = (radius * 2) * PI;
    cout << "The circumference of a circle with a radius of "
            << radius << " is " << circumference << endl;
    cout << "Press any letter to continue" << endl;
    cin >> cont;
    return (circumference);

}

float CircleArea(float radius) {
    char cont;
    float area = 0;
    area = PI * (radius * radius);
    cout << "The area of a circle with radius "
            << radius
            << " is: "
            << area
            << endl;
    cout << "Press any letter to continue" << endl;
    cin >> cont;
    return (area);
}

float CylinderVolume(float Cyldepth, float radius) {
    char cont;
    float volume = (Cyldepth * PI) * (radius * radius);
    cout << "The volume of a cylinder with a height of "
            << Cyldepth
            << " and a radius of "
            << radius
            << " is: "
            << volume << endl;
    cout << "Press any letter to continue" << endl;
    cin >> cont;
    return (volume);
}

float CylinderSurfaceArea(float radius, float height) {
    char cont;
    float SurfaceArea = (Cyldepth * PI * radius * 2) + ((radius * radius)*2 * PI);
    cout << "The Surface Area of a cylinder with a height of "
            << Cyldepth
            << " and a radius of "
            << radius
            << " is: "
            << SurfaceArea << endl;
    cout << "Press any letter to continue" << endl;
    cin >> cont;
    return (SurfaceArea);
}

float SphereVolume(float radius) {
    char cont;
    float volume = (4 / 3) * PI * (radius * radius * radius);
    cout << "The volume of a sphere with a radius of "
            << radius
            << " is: "
            << volume << endl;
    cout << "Press any letter to continue" << endl;
    cin >> cont;
    return (volume);
}

float SphereSurfaceArea(float radius) {
    char cont;

    float sphsurfaceArea = (4 * PI)*(radius * radius);
    cout << "The surface area of a sphere with a radius of  "
            << radius
            << " is: "
            << sphsurfaceArea << endl;
    cout << "Press any letter to continue";
    cin >> cont;
    return (sphsurfaceArea);
}

float ConeSurfaceArea(float radius, float height) {
    char cont;
    float consurfaceArea = ((PI * radius)+((PI * radius))*(sqrt((radius * radius)*(height * height))));
    cout << "The surface area of a cone with a radius of  "
            << radius
            << " and a height of "
            << height
            << " is: "
            << consurfaceArea << endl;
    cout << "Press any letter to continue";
    cin >> cont;
    return (consurfaceArea);

}

float ConeVolume(float radius, float height) {
    char cont;
    float conevolume = ((PI * (radius * radius)) * height) / 3;
    cout << "The volume of a cone with a radius of  "
            << radius
            << " and a height of "
            << height
            << " is: "
            << conevolume << endl;
    cout << "Press any letter to continue";
    cin >> cont;
    return (conevolume);
}

float RectangleArea(float length, float width) {
    char cont;
    float area = length * width;
    cout << "The area of a rectangle with a length of "
            << length << " and a width of " << width << " is: " << area << endl;
    cout << "Press any letter to continue" << endl;
    cin >> cont;
    return (area);
}

float PerimeterRectangle(float length, float width) {
    char cont;
    float perimeter = ((2 * length) +(2 * width));
    cout << "The perimeter of a rectangle with a length of "
            << length << " and a width of " << width << " is: " << perimeter << endl;
    cout << "Press any letter to continue" << endl;
    cin >> cont;
    return (perimeter);
}

float VolumeRectangularSolid(float length, float height, float depth) {
    char cont;
    float volume = length * depth*height;
    cout << "The volume of a rectangle with a length of "
            << length << " and a width of " << height << "and a depth of " << depth << " is: " << volume << endl;
    cout << "Press any letter to continue" << endl;
    cin >> cont;
    return (volume);
}