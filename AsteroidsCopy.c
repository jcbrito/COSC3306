/*Use this at the top of your file to make it compile on either Windows or Linux without requiring any
modification:
* 
* 	Name: Juan Brito
* 	Course: COSC 3306
* 	Date: Jan 15 2020
* 	Description: This program is based off the classic game
* 				 asteroids. this is a simple scene with simple 
* 				 animations. this drawing is made up of mostly 
* 				 lines. Thanks to Professor Miguel for providing
* 				 the starting code (HelloWorld.c). The original 
* 				 file was used as a basis for learning
* 				 FreeGlut and open GL. 
* 
* */
#include <dos.h>
#ifdef _WIN32
#include <windows.h>
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif
//#include <GL/glut.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/freeglut.h>

    //these are constant coordinates for objects
    // the are global variables so that the objects
    // can be controlled by only modifying one
    // set of coordinates.
    
    int nameX = 280;
    
    //spaceship coordinates
    int point1X = 200; //point a
    int point1Y = 200; 

    
    //asteroid coordinates
    
    int roid1X = 400;
    int roid1Y = 400;
    
    int roid2X = 100;
    int roid2Y = 190;
    
    int roid3X = 400;
    int roid3Y = 200;
    
    //roid speeds
 	int roidSpeed1 = 1;
 	int roidSpeed2 = 1;
 	int roidSpeed3 = 1;
 	
 	//ship speed
	int shipSpeed = 1;
    
    

//You will need to add this to the 'build' (linker) option from your compiler:  -lGL -lglut -lGLU
//<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
 void myInit(void)
 {
    glClearColor(0.0,0.0,0.0,0.0); // set white background color
    glColor3f(1.0f, 1.0f, 1.0f); // set the drawing color 
    glPointSize(2.0); // a dot is 4 by 4 pixels
    glMatrixMode(GL_PROJECTION); // more on MatrixMode later
    glLoadIdentity(); // more on Identity later
    gluOrtho2D(0, 640, 0, 480); // width: 0-640; height: 0-480
}
//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	for(int i = 0; i < 250; i++){
	glClear(GL_COLOR_BUFFER_BIT); // clears the screen 
	glBegin(GL_LINES); 
		// using these coordinates we will drway the triangles under the score
		glVertex2i(20, 420);	//triangle 1
		glVertex2i(30, 440);
		glVertex2i(30, 440);	
		glVertex2i(40, 420);
		
		glVertex2i(40, 420);	//triangle 2
		glVertex2i(50, 440);
		glVertex2i(50, 440);
		glVertex2i(60, 420);
		
		glVertex2i(60, 420);	//triangle 3
		glVertex2i(70, 440);
		glVertex2i(70, 440);
		glVertex2i(80, 420);
		
		glVertex2i(80, 420);	//triangle 4
		glVertex2i(90, 440);
		glVertex2i(90, 440);
		glVertex2i(100, 420);
		
		
		glVertex2i(20, 420);	//line under triangles
		glVertex2i(100, 420);
			
	glEnd();
	
	
	// this is the spaceship
	glBegin(GL_LINES);
	
		    
	
		int num = rand() % 3 ; //random number between 0 and 5 to choose 
		
		switch (num)
		{
			case 0:							//moves ship depending on a random
				point1X += shipSpeed;		//number generated between 0 and 2 
				break;						// inclusive
				
			case 1:
				point1Y += shipSpeed;
				break;
			
			case 2:
				point1X += shipSpeed;
				point1Y += shipSpeed;
				break;
									
		} 
		
				//drawing the ship relative to 
				// the starting point
				int point2X = point1X + 50; //point b
				int point2Y = point1Y + 30;
				
				
				int point3X = point2X + 50; //point c
				int point3Y = point2Y - 30;
				
				int point4X = point3X - 50; //point d
				int point4Y = point2Y + 120;
					
		
			if(point1X < 40){ //keep the ship in shape
				
				shipSpeed *= -1 ;
				
				}
			else if(point1X > 520){		//checks the limits of the position of the ship
				shipSpeed *= -1 ;		// keeps it in a certain area in the screen
				}
				
			if(point4Y > 460){
				shipSpeed *= -1;
			}
			
			else if(point1Y < 40){
				shipSpeed *= -1;
			
			}		
	
		glColor3f(1,0,0);				//set the color to red
							
		//drawing the ship 
		glVertex2i(point1X, point1Y); //Point A		
		glVertex2i(point2X, point2Y);
		
		glVertex2i(point2X, point2Y); //Point B
		glVertex2i(point3X, point3Y);
		
		glVertex2i(point3X, point3Y); //Point C
		glVertex2i(point4X, point4Y);
		
		glVertex2i(point4X, point4Y); //Point D
		glVertex2i(point1X, point1Y);

	
	glEnd();
	
	
			// drwaing some asteroids 
	glBegin(GL_LINES);
	
		glColor3f(1,1,1);
		
		
		roid1X += roidSpeed1;
		
		if(roid1X > 490){						//checks the limits of the position of the asteroid
			roidSpeed1 *= -1;
		}
		else if( roid1X < 399){
			roidSpeed1 *= -1;

		}
		
		
		glVertex2i(roid1X, roid1Y);				//point A
		glVertex2i(roid1X + 10, roid1Y + 50);
		
		glVertex2i(roid1X + 10, roid1Y + 50);	//Point B
		glVertex2i(roid1X + 50, roid1Y + 50);

		glVertex2i(roid1X + 50, roid1Y + 50);	//Point C
		glVertex2i(roid1X + 70, roid1Y + 25);

		glVertex2i(roid1X + 70, roid1Y + 25);	//Point D
		glVertex2i(roid1X + 50, roid1Y );

		glVertex2i(roid1X + 50, roid1Y );		//Point E
		glVertex2i(roid1X + 25, roid1Y + 25);
	
		glVertex2i(roid1X + 25, roid1Y + 25);	//Point F
		glVertex2i(roid1X, roid1Y);
		
		
		// second asteroid
		
				
		if(roid2Y > 280){					//checks the limits of the position of the asteroid
			roidSpeed2 *= -1;
		}
		else if( roid2Y < 150){
			roidSpeed2 *= -1;

		}
		
		roid2Y += roidSpeed2;
		glVertex2i(roid2X, roid2Y);				//point A
		glVertex2i(roid2X + 10, roid2Y + 50);
		
		glVertex2i(roid2X + 10, roid2Y + 50);	//Point B
		glVertex2i(roid2X + 50, roid2Y + 50);

		glVertex2i(roid2X + 50, roid2Y + 50);	//Point C
		glVertex2i(roid2X + 70, roid2Y + 25);

		glVertex2i(roid2X + 70, roid2Y + 25);	//Point D
		glVertex2i(roid2X + 50, roid2Y );

		glVertex2i(roid2X + 50, roid2Y );	//Point E
		glVertex2i(roid2X + 25, roid2Y + 25);
	
		glVertex2i(roid2X + 25, roid2Y + 25);	//Point F
		glVertex2i(roid2X, roid2Y);
		
		// third asteroid
		
			
		if(roid3Y > 280){					//checks the limits of the position of the asteroid
			roidSpeed3 *= -1;
		}
		else if( roid3Y < 190){
			roidSpeed3 *= -1;

		}
		
		roid3Y += roidSpeed3;				//moves this asteroid

		
		glVertex2i(roid3X, roid3Y);				//point A
		glVertex2i(roid3X + 10, roid3Y + 50);
		
		glVertex2i(roid3X + 10, roid3Y + 50);	//Point B
		glVertex2i(roid3X + 50, roid3Y + 50);

		glVertex2i(roid3X + 50, roid3Y + 50);	//Point C
		glVertex2i(roid3X + 70, roid3Y + 25);

		glVertex2i(roid3X + 70, roid3Y + 25);	//Point D
		glVertex2i(roid3X + 50, roid3Y );

		glVertex2i(roid3X + 50, roid3Y );	//Point E
		glVertex2i(roid3X + 25, roid3Y + 25);
	
		glVertex2i(roid3X + 25, roid3Y + 25);	//Point F
		glVertex2i(roid3X, roid3Y);		
		

	glEnd();
	
	
	
	
	glColor3f(1,1,1);
	
	glBegin(GL_POINTS);
		
		//generate stars on our background
	
		srand(time(NULL));
		
		for(int i = 0; i < 50; i++){
			
			int random_X = rand() % 640;	//generating random X Y coordinates to
			int random_Y = rand() % 480;	// dynamically put stars on the screen
			
			glVertex2i(random_X, random_Y);	// puting a dot at the randomly generated X Y coordinate.
			
		}
		
	
	glEnd();
	
	
	glRasterPos2f(35, 450);				// sets drawing point 

	float red = (float)rand()/(float)(RAND_MAX);
	float green = (float)rand()/(float)(RAND_MAX);
	float blue = (float)rand()/(float)(RAND_MAX);

	int scoreInt = rand() %9000 + 1000;					//this is generating the random score
	char scoreStr[5];
	itoa(scoreInt, scoreStr, 10);						//changing the int into a String
	
	

	
	//glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1' );	//draws number 1
	 			
	//glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');	//draws number 3

	//glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3'); //draws number 3	

	//glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '7'); //draws number 7	
	
	
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, scoreStr);	// a way to display a randomized score
	
	
	nameX += 2;												// this moves my name across the X-axis in the right direction
	nameX = nameX % 620;									//once it reaches the X value of 620 it is returned to the left 
	
	glColor3f(red, green, blue);							//using the 3 random floats we will get a random color
	glRasterPos2f(nameX, 100);								//coordinates for my name		
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'B');	
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'Y');					
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ':');					
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'J');					
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'U');					
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'A');				
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'N');					
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ' ');				
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'B');					
				

	glFlush(); // send all output to display 
	glColor3f(1, 1, 1);										//resets the color back to white
	_sleep(19);												// a delay to make the animation smoother
	}
}

//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
void main(int argc, char** argv)
{
	glutInit(&argc, argv);	// initializes the freeGLUT toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // sets display mode
	glutInitWindowSize(640,480); // sets window size
	glutInitWindowPosition(100, 150); // sets window position on screen
	glutCreateWindow("<(0_0)> Asteroids <(0_0)>"); // opens the screen window
	glutDisplayFunc(myDisplay); // registers function
	myInit(); //initializes values      
	
	glutMainLoop();	// goes into a perpetual loop
		
	         
	
}
