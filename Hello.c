/*Use this at the top of your file to make it compile on either Windows or Linux without requiring any
modification:*/
#ifdef _WIN32
#include <windows.h>
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif
//#include <GL/glut.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/freeglut.h>

    int nameX = 280;
    
    //spaceship coordinates
    int point1X = 200; //point a
    int point1Y = 200; 

    
    //asteroid coordinates
    
    int roid1X = 300;
    int roid1Y = 300;
    

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
	glClear(GL_COLOR_BUFFER_BIT); // clears the screen 
	glBegin(GL_LINES); // draws points
		// using these coordinates
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
	
		    
	
		int num = rand() % 4; //random number between 0 and 5 to choose 
		
		switch (num)
		{
			case 0:					//moves ship to the right
				point1X += 5;
				break;
				
			case 1:
				point1Y += 5;		//moves the ship up
				break;	
			
			case 2:
				point1X -= 5;		//moves the ship to the left
				break;

			
			case 3:
				point1Y -= 5;		//moves the ship down
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
					
		
				point1X %= 560;	//keep the space ship in a certain range
				point2X %= 560;
				point3X %= 560;
				point4X %= 560;
				
				point1Y %= 440;
				point2Y %= 440;
				point3Y %= 440;
				point4Y %= 440;
				
			if(point4Y < point1Y){ //keep the ship in shape
				point4Y += 120;
				}	
	
		glColor3f(1,0,0);
							
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
	glBegin(GL_POLYGON);
		
		
		
	
	
	glEnd();
	
	
	
	
	glColor3f(1,1,1);
	
	glBegin(GL_POINTS);
		
		//generate stars on our background
	
		srand(time(NULL));
		
		for(int i = 0; i < 50; i++){
			
			int random_X = rand() % 640;
			int random_Y = rand() % 480;
			
			glVertex2i(random_X, random_Y);
			
		}
		
	
	glEnd();
	
	
	glRasterPos2f(35, 450);				// sets drawing point 
	
	
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1');	//draws number 1
	//glRasterPos2f(175, 200);				// sets new drawing point 
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');	//draws number 3
	//glRasterPos2f(200, 200);				
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3'); //draws number 3	
	//glRasterPos2f(225, 200);				
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '7'); //draws number 7	
	//glRasterPos2f(250, 200);
	
	nameX += 10;
	nameX = nameX % 620;
	
	
	glRasterPos2f(nameX, 100);								//coordinates for my name		
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'B');	//draws number prints my name
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'Y');					
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ':');					
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'J');					
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'U');					
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'A');				
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'N');					
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ' ');				
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'B');					
				

	glFlush(); // send all output to display 
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
