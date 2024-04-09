#define GL_SILENCE_DEPRECATION // Used new GL library for my Mac
#include <GLUT/glut.h> 
#include <iostream>
#include <cmath>
#include <vector>


// Function for drag coefficient with respect to alfa
double computeCD(double Alpha) 
{
    double eps = 1.0 / 1.0; 
    double X = 1.2;// Mach Number
    return 4 * (pow(Alpha, 2) + pow(eps, 2)) / sqrt(pow(X, 2) - 1);  
}

// Function to display
void display() 
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.53, 0.81, 0.98); // Light sky blue color
    glLoadIdentity();

    // Change window size
    gluOrtho2D(-2.0, 22.0, -2.0, 2000.0);

    // X-axis
    glBegin(GL_LINES);
    glVertex2f(0.1, 0.1);
    glVertex2f(20.1, 0.1);
    glEnd();

    // Y-axis
    glBegin(GL_LINES);
    glVertex2f(0.1, 0.1);
    glVertex2f(0.1, 2000.1);
    glEnd();

    // Draw axis labels
    glColor3f(1.0, 1.0, 1.0); // Color = White
    glRasterPos2f(20.0, -1.5); // X-axis label placemnt
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'a');  


    glRasterPos2f(-1.5, 1900.0); // Y-axis label placemnt
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'c'); // Label for y-axis
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'd');

    // finding CD values for 0 to 18
    glBegin(GL_LINE_STRIP);
    for (int Alpha = 0; Alpha <= 18; ++Alpha) {
        double CoefD = computeCD(Alpha);
        glVertex2f(Alpha, CoefD);
    }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) 
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInit(&argc, argv);
    
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(1000, 800); // Set Window size
    
    glutCreateWindow("Question 4: Coefficient of Drag vs. alpha");
    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}