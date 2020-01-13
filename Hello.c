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
		
		
		//making the spaceship (another triangle)
		glVertex2i(300, 210);	//spaceship
		glVertex2i(320, 240);
		glVertex2i(320, 240);
		glVertex2i(330, 210);		
		glVertex2i(300, 210);		
		glVertex2i(330, 210);		

		

	glEnd();
	
	
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
