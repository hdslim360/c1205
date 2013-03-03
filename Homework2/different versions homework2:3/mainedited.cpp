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
#include <ctype.h>
//Listed below are the global variables used for any function;
//these are generic and can be used by all functions, instance variables
//needed by certain objects will be declared within them.


int submenuChoice_A=0; // Circles and Cylinders switch variable
int submenuChoice_B=0; //Spheres switch variable
int submenuChoice_C=0; //Rectangles and Rectangular Solids switch Variable
int submenuChoice_D=0; //Triangles and Pyramids switch variable
const float PI =  3.1415926535;
float length = 0;
float width = 0;
float base = 0;
float height = 0;
float radius = 0;
float volume = 0;
float area = 0;
float Cyldepth = 0;


using namespace std;

//below is the declaration of the objects used 
//for the various formulas for which the program is written.
//the objects are listed following main().
int get_menu_choice();
int main_menu(int menuChoice); 
int checkEntry(int numEntry);
float CircleArea(float radius);
float CircleCircumference(float radius);
float CylinderVolume(float Cyldepth , float radius);
float PerimeterRectangle(float length, float height);
float RectangleArea(float length, float height);
float VolumeRectangularSolid(float length, float height, float depth);
float RightTriangleArea(float base, float height);
float SphereVolume(float radius);
float SphereSurfaceArea(float radius);
float ConeVolume (float radius, float height);
float ConeSurfaceArea( float radius, float height);

int main(int argc,char *argv[]){
    int menuChoice = 0;
    cout<<"Welcome to Geometry'R'Us"<<endl<<endl;
       
        /*The switches used are nested within one another as well as
         * enclosed with in do-while and while loops this gives the user the
         * ability to move up and down within the menu structure so that once 
         * the exit choice was selected it would not end the program all together.
         */
    
        do{        
            menuChoice=get_menu_choice();
            main_menu(menuChoice);
             //this while loop is to allow for the correction of bad data
             //i.e  int or char entered for menuChoice other than 1-5.
            while((menuChoice>5)||menuChoice<0){
                cout<<"please enter a valid selection"<<endl;
                cin>>menuChoice;
                }
            
            cout<<endl;
            cout<<endl;
            cout<<"Thank You for using Geometry'R'Us!"<<endl;
            
            
        
        }while (menuChoice<5);
    
return(0);        
}
int get_menu_choice(){
            
            int menu_choice;
            cout<<"Please select one from the following menu items:"<<endl<<endl;
            cout<<"Enter 1 for Circles and Cylinders"<<endl;
            cout<<"Enter 2 for Spheres and Cones"<<endl;
            cout<<"Enter 3 for Squares and Rectangular Solids"<<endl;
            cout<<"Enter 4 for Triangles and Pyramids"<<endl;
            cout<<"Enter 5 to Exit"<<endl;
            menu-choice=checkEntry();
            return menu_choice;
            }

int checkEntry(){
	int user_input=0;
	
}
int main_menu(int menuChoice){
switch( menuChoice )
                {
            
                case 1:
                  cout<<"Circles and Cylinders: "<<endl;//submenu 1 selection for circles and cylinders
                      do{
                        cout<<"Please select the formula you wish to use:"<<endl;  
                        cout<<"Choose 1 for the Area of a Circle:"<<endl;
                        cout<<"Choose 2 for the Circumference of a Circle:"<<endl;
                        cout<<"Choose 3 for the Volume of a Cylinder:"<<endl;
                        cout<<"Choose 4 for the Surface Area of a Cylinder:"<<endl;
                        cout<<"Choose 5 to exit:"<<endl<<endl;
                        cin>>submenuChoice_A;
                        //the next while loop is to handle poor user input
                        while((submenuChoice_A>5)||submenuChoice_A<0){
                                cout<<"please enter a valid selection"<<endl;
                                cin>>submenuChoice_A;
                                }  
                        
                         switch(submenuChoice_A){
                                case 1:
                                    //circle function for radius calc
                                    cout<<"Please enter the radius of the circle "<<endl;
                                    cout<<"you wish to calculate the area for: "<<endl;
                                    cin>>radius;
                                    cout<<endl;
                                    CircleArea(radius);
                                    
                                    break;
                                    
                                case 2:
                                    //circle circumference 
                                    cout<<"Please enter the radius of the circle "<<endl;
                                    cout<<"you wish to calculate the circumference for: "<<endl;
                                    cin>>radius;
                                    cout<<endl;
                                    CircleCircumference(radius);
                                    break;
                                    
                                case 3:
                                    //cylinder volume
                                    cout<<"Please enter the radius of the cylinder:"<<endl;
                                    cout<<" you wish to calculate the volume for: "<<endl;
                                    cin>>radius;
                                    cout<<endl;
                                    cout<<"Please enter the depth of the cylinder: "<<endl;
                                    cout<<endl;
                                    cin>>Cyldepth;
                                    CylinderVolume( Cyldepth, radius);
                                    break;
                                    
                                
                                   
                            }
                        }while(submenuChoice_A <=4);   
                   break; 
               
               case 2: 
                    cout<<"Spheres and Cones:  "<<endl;//sub menu selection for spheres and cones
                    do{
                        cout<<"Please select the Formula you wish to use: "<<endl<<endl;
                        cout<<"Spheres:"<<endl<<endl;
                        cout<<"Choose 1 for the Volume of a Sphere:  "<<endl;
                        cout<<"Choose 2 for the Surface Area of a Sphere:  "<<endl<<endl;
                        cout<<"Cones:"<<endl<<endl;
                        cout<<"Choose 3 for the Volume of a Cone:  "<<endl;
                        cout<<"Choose 4 for the Surface Area of a Cone"<<endl<<endl;
                        cout<<"Choose 5 to EXIT"<<endl;
                        cin>>submenuChoice_B;
                             
                        switch(submenuChoice_B){
                            case 1://Sphere volume function
                                    cout<<"Please enter the radius of the sphere "<<endl;
                                    cout<<" you wish to calculate the volume for: "<<endl;
                                    cin>>radius;
                                    cout<<endl;
                                    SphereVolume(radius);
                                    break;
                            
                            case 2://Sphere Surface Area function
                                    cout<<"Please enter the radius of the sphere "<<endl;
                                    cout<<" you wish to calculate the Surface Area for: "<<endl;
                                    cin>>radius;
                                    cout<<endl;
                                    SphereSurfaceArea(radius);
                                    break;
                                
                                
                                
                            case 3://Volume of cone function
                                    cout<<"Please enter the radius of the cone "<<endl;
                                    cout<<" you wish to calculate the Volume for: "<<endl;
                                    cin>>radius;
                                    cout<<endl;
                                    cout<<"Please enter the height of the cone "<<endl;
                                    cout<<" you wish to calculate the Volume for: "<<endl;
                                    cin>>height;
                                    cout<<endl;
                                    ConeVolume(radius, height);
                                    break;
                                    
                                    
                                break;
                            case 4:// Surface Area of a cone
                                    cout<<"Please enter the radius of the cone "<<endl;
                                    cout<<" you wish to calculate the Surface Area for: "<<endl;
                                    cin>>radius;
                                    cout<<endl;
                                    cout<<"Please enter the height of the cone "<<endl;
                                    cout<<" you wish to calculate the Surface Area for: "<<endl;
                                    cin>>height;
                                    cout<<endl;
                                    ConeSurfaceArea(radius, height);
                                    break;
                                    
                                break;
                                
                            
                                        
                        }
                        
                    }while(submenuChoice_B<=4);
                        
                        break; 
	 
               case 3:
                    cout<<"Squares, Rectangles, and Rectangular Solids:"<<endl;
                    cout<<"Choose 4 for the Perimeter of a Square or Rectangle:"<<endl;
                    cout<<"Choose 5 for the Area of a Square or Rectangle:"<<endl;
                    cout<<"Choose 6 for the Volume of a Hexahedron:"<<endl; 
                    
                        break; 
                      
               case 4:
                    cout<<"Triangles and Pyramids: "<<endl; 
                   
                        break; 
	
            
               case 5:
                    
	   
                        break;
                        
	}
	return 5;
}   

float CircleCircumference(float radius)
{ 
    char cont;
    float circumference = 0;
    circumference= (radius*2)*PI;
    cout<<"The circumference of a circle with a radius of "
        <<radius<<" is "<< circumference <<endl;
    cout<<"Press any letter to continue"<<endl;
    cin>>cont;
    return (circumference);

}


float CircleArea(float radius)
{       char cont;
    float area = 0;
         area = PI*(radius*radius);
	cout << "The area of a circle with radius " 
             <<radius
             << " is: " 
             <<area
             << endl;
	cout<<"Press any letter to continue"<<endl;
        cin>>cont;
        return (area);
}

float RectangleArea(float length, float width)
{char cont;
	float area = length * width;
	cout << "The area of a rectangle with a length of " 
             <<length<< " and a width of " <<width<< " is: " <<area<< endl;
	cout<<"Press any letter to continue"<<endl;
        cin>>cont;
        return(area);
}

float RightTriangleArea(float base, float height)
{       char cont;
	float area = (base * height)/2;
	cout << "The area of a right triangle with a base of " 
		 << base
		 << " and a height of " 
		 << height
		 << " is: " 
		 << area << endl;
	cout<<"Press any letter to continue"<<endl;
        cin>>cont;
        return(area); 
}
float CylinderVolume(float Cyldepth, float radius)
{
    char cont;
	float volume = (Cyldepth * PI) * (radius*radius);
	cout << "The volume of a cylinder with a height of " 
		 << Cyldepth
		 << " and a radius of " 
		 << radius
		 << " is: " 
		 << volume << endl;
	cout<<"Press any letter to continue"<<endl;
        cin>>cont;
        return(volume);
}
float SphereVolume(float radius)
{       char cont;
	float volume = (4/3) * PI * (radius*radius*radius);
	cout << "The volume of a sphere with a radius of " 
		 << radius
		 << " is: " 
		 << volume << endl;
	cout<<"Press any letter to continue"<<endl;
        cin>>cont;
        return(volume);
}
float SphereSurfaceArea(float radius)
{       
    char cont;
    
    float sphsurfaceArea=(4*PI)*(radius*radius);
    cout<<"The surface area of a sphere with a radius of  "
            <<radius
            <<" is: "
            <<sphsurfaceArea<<endl;
    cout<<"Press any letter to continue";
    cin>>cont;
    return(sphsurfaceArea);
}
float ConeSurfaceArea( float radius, float height )
{
    char cont;
    float consurfaceArea= (PI*radius)+((PI*radius)*sqrt((radius*radius)*(height*height))) ;
     cout<<"The surface area of a cone with a radius of  "
            <<radius
            <<" and a height of "
            <<height
            <<" is: "
            <<consurfaceArea<<endl;
    cout<<"Press any letter to continue";
    cin>>cont;
    return(consurfaceArea);
    
}
float ConeVolume (float radius, float height )
{
    char cont;
    float conevolume = ((1/3)*(PI*(radius*radius)))*height;
    cout<<"The volume of a cone with a radius of  "
            <<radius
            <<" and a height of "
            <<height
            <<" is: "
            <<conevolume<<endl;
    cout<<"Press any letter to continue";
    cin>>cont;
    return(conevolume);
}
