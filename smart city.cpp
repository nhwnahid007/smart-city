#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <math.h>

void init()
{
    glClearColor(1.0 / 255 * 135, 1.0 / 255 * 206, 1.0 / 255 * 235, 0.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
    //glOrtho(-50, 50, -50, 50, -50, 50);
    gluOrtho2D(0.0, 900.0, 0.0, 900.0); // Orthographic representation; multiply the current matrix by an orthographic matrix 2D= left right,bottom,top equivalent near=-1,far=1
}

void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy) {

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);// center of circle

    for (int i = 0; i <= 100;i++) {

        float angle = 2 * 3.1416 * (i * 1.0 / 100);

        float x = rx * cosf(angle);
        float y = ry * sinf(angle);

        glVertex2f((x + cx), (y + cy));
    }

    glEnd();


}

float car = 0;
float boat = 0;
float air = 0;
float bus = 0;
float cloud = 0;


void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0 / 255 * 27, 1.0 / 255 * 149, 1.0 / 255 * 224);
    //river
    glBegin(GL_QUADS);
    glVertex2f(00.0, 00.0);
    glVertex2f(900.0, 0.0);
    glVertex2f(900.0, 150.0);
    glVertex2f(00.0, 150.0);

    glEnd();

    //boat
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(boat + 300.0, 50.0);
    glVertex2f(boat + 500.0, 50.0);
    glVertex2f(boat + 520.0, 90.0);
    glVertex2f(boat + 280.0, 90.0);
    glEnd();
    //boat upper
    glBegin(GL_POLYGON);
    glColor3f(1.0 / 255 * 61, 1.0 / 255 * 79, 1.0 / 255 * 118);
    glVertex2f(boat + 310.0, 90.0);
    glVertex2f(boat + 490.0, 90.0);
    glVertex2f(boat + 480.0, 120.0);
    glVertex2f(boat + 320.0, 120.0);
    glVertex2f(boat + 310.0, 90.0);

    glEnd();

    //boat box 

    glBegin(GL_POLYGON);
    glColor3f(1.0 / 255 * 35, 1.0 / 255 * 172, 1.0 / 255 * 196);
    glVertex2f(boat + 333.0, 95.0);
    glVertex2f(boat + 373.0, 95.0);
    glVertex2f(boat + 373.0, 115.0);
    glVertex2f(boat + 333.0, 115.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0 / 255 * 35, 1.0 / 255 * 172, 1.0 / 255 * 196);
    glVertex2f(boat + 386.0, 95.0);
    glVertex2f(boat + 426.0, 95.0);
    glVertex2f(boat + 426.0, 115.0);
    glVertex2f(boat + 386.0, 115.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0 / 255 * 35, 1.0 / 255 * 172, 1.0 / 255 * 196);
    glVertex2f(boat + 470.0, 95.0);
    glVertex2f(boat + 439.0, 95.0);
    glVertex2f(boat + 439.0, 115.0);
    glVertex2f(boat + 470.0, 115.0);
    glEnd();

    //boat moving

    if (boat >= -400)
    {
        boat = boat - 0.03;
        glutPostRedisplay();
    }

    else {
        boat = 1000;
        glutPostRedisplay();
    }



    //cloud
    glColor3f(1.0 / 255 * 208, 1.0 / 255 * 204, 1.0 / 255 * 204);
    circle(50, 10, cloud + 150, 700);
    circle(30, 25, cloud + 125, 710);
    circle(22, 20, cloud + 180, 702);
    circle(22, 20, cloud + 115, 700);




    circle(22, 20, cloud + 290, 740);
    circle(22, 20, cloud + 315, 750);
    circle(30, 20, cloud + 325, 740);





    circle(22, 20, cloud + 450, 700);
    circle(22, 20, cloud + 460, 690);
    circle(30, 20, cloud + 470, 705);



    if (cloud <= 900)
    {
        cloud = cloud + 0.02;
        glutPostRedisplay();
    }

    else {
        cloud = -10;
        glutPostRedisplay();
    }





    //road
    glBegin(GL_POLYGON);
    glColor3f(.20, .20, .20);

    glVertex2f(00.0, 150.0);
    glVertex2f(900.0, 150.0);
    glVertex2f(900.0, 280.0);
    glVertex2f(0.0, 280.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);

    glVertex2f(0, 215);
    glVertex2f(190, 215);

    glVertex2f(200, 215);
    glVertex2f(390, 215);

    glVertex2f(400, 215);
    glVertex2f(590, 215);


    glVertex2f(600, 215);
    glVertex2f(790, 215);
    glVertex2f(800, 215);
    glVertex2f(990, 215);

    glEnd();


    //car bottom

    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);

    glVertex2f(car + 160.0, 190.0);
    glVertex2f(car + 280.0, 190.0);
    glVertex2f(car + 280.0, 225.0);
    glVertex2f(car + 250.0, 225.0);
    glVertex2f(car + 245.0, 235.0);
    glVertex2f(car + 160.0, 235.0);


    glEnd();

    //car upper
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(car + 160.0, 235.0);
    glVertex2f(car + 245.0, 235.0);
    glVertex2f(car + 237.0, 260.0);
    glVertex2f(car + 170.0, 260.0);


    glEnd();

    //car glass left
    glBegin(GL_POLYGON);
    glColor3f(1.0 / 255 * 246, 1.0 / 255 * 254, 1.0 / 255 * 255);
    glVertex2f(car + 163.0, 237.0);
    glVertex2f(car + 200.0, 237.0);
    glVertex2f(car + 200.0, 257.0);
    glVertex2f(car + 172.0, 257.0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0 / 255 * 246, 1.0 / 255 * 254, 1.0 / 255 * 255);
    glVertex2f(car + 205.0, 237.0);
    glVertex2f(car + 242.0, 237.0);
    glVertex2f(car + 235.0, 257.0);
    glVertex2f(car + 205.0, 257.0);

    glEnd();

    glColor3f(0, 0, 0);
    circle(12, 13, car + 190, 190);
    circle(12, 13, car + 250, 190);

    //car run


    if (car <= 900)
    {
        car = car + 0.09;
        glutPostRedisplay();
    }

    else {
        car = -200;
        glutPostRedisplay();
    }

    //building

    glBegin(GL_POLYGON);
    glColor3f(1.0 / 255 * 193, 1.0 / 255 * 113, 1.0 / 255 * 71);
    glVertex2f(100.0, 280.0);
    glVertex2f(290.0, 280.0);
    glVertex2f(290.0, 500.0);
    glVertex2f(100.0, 500.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0 / 255 * 246, 1.0 / 255 * 254, 1.0 / 255 * 255);
    glVertex2f(120.0, 330.0);
    glVertex2f(170.0, 330.0);
    glVertex2f(170.0, 380.0);
    glVertex2f(120.0, 380.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0 / 255 * 246, 1.0 / 255 * 254, 1.0 / 255 * 255);
    glVertex2f(215.0, 330.0);
    glVertex2f(265.0, 330.0);
    glVertex2f(265.0, 380.0);
    glVertex2f(215.0, 380.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0 / 255 * 246, 1.0 / 255 * 254, 1.0 / 255 * 255);
    glVertex2f(120.0, 400.0);
    glVertex2f(170.0, 400.0);
    glVertex2f(170.0, 450.0);
    glVertex2f(120.0, 450.0);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.0 / 255 * 246, 1.0 / 255 * 254, 1.0 / 255 * 255);
    glVertex2f(215.0, 400.0);
    glVertex2f(265.0, 400.0);
    glVertex2f(265.0, 450.0);
    glVertex2f(215.0, 450.0);
    glEnd();


    //tree

    glBegin(GL_POLYGON);
    glColor3f(1.0 / 255 * 150, 1.0 / 255 * 75, 1.0 / 255 * 0);
    glVertex2f(350.0, 280.0);
    glVertex2f(370.0, 280.0);
    glVertex2f(370, 400);
    glVertex2f(350.0, 400.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0 / 255 * 21, 1.0 / 255 * 71, 1.0 / 255 * 75);
    glVertex2f(275.0, 400.0);
    glVertex2f(445.0, 400.0);
    glVertex2f(360.0, 550.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0 / 255 * 21, 1.0 / 255 * 71, 1.0 / 255 * 75);
    glVertex2f(295.0, 375.0);
    glVertex2f(430.0, 375.0);
    glVertex2f(360.0, 525.0);
    glEnd();




    // Big building 

    glBegin(GL_POLYGON);
    glColor3f(1.0 / 255 * 35, 1.0 / 255 * 172, 1.0 / 255 * 196);



    glVertex2f(500.0, 280.0);

    glVertex2f(750.0, 280.0);

    glVertex2f(750.0, 400.0);

    glVertex2f(710.0, 400.0);

    glVertex2f(710.0, 550.0);
    glVertex2f(680.0, 550.0);
    glVertex2f(680.0, 590.0);




    glVertex2f(520.0, 590.0);
    glVertex2f(520.0, 530.0);
    glVertex2f(500.0, 530.0);



    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.0 / 255 * 150, 1.0 / 255 * 152, 1.0 / 255 * 115);
    glVertex2f(600.0, 590.0);
    glVertex2f(680.0, 590.0);
    glVertex2f(680.0, 650.0);
    glVertex2f(600.0, 650.0);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.0 / 255 * 150, 1.0 / 255 * 152, 1.0 / 255 * 115);
    glVertex2f(630.0, 650.0);
    glVertex2f(650.0, 650.0);
    glVertex2f(650.0, 750.0);
    glVertex2f(630.0, 750.0);
    glEnd();

    //house box

    glBegin(GL_QUADS);
    glColor3f(1.0 / 255 * 137, 1.0 / 255 * 135, 1.0 / 255 * 144);
    glVertex2f(520.0, 350.0);
    glVertex2f(560.0, 350.0);
    glVertex2f(560.0, 390.0);
    glVertex2f(520.0, 390.0);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0 / 255 * 137, 1.0 / 255 * 135, 1.0 / 255 * 144);
    glVertex2f(520.0, 410.0);
    glVertex2f(560.0, 410.0);
    glVertex2f(560.0, 450.0);
    glVertex2f(520.0, 450.0);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0 / 255 * 137, 1.0 / 255 * 135, 1.0 / 255 * 144);
    glVertex2f(520.0, 470.0);
    glVertex2f(560.0, 470.0);
    glVertex2f(560.0, 510.0);
    glVertex2f(520.0, 510.0);

    glEnd();

    //second column

    glBegin(GL_QUADS);
    glColor3f(1.0 / 255 * 137, 1.0 / 255 * 135, 1.0 / 255 * 144);
    glVertex2f(590.0, 350.0);
    glVertex2f(630.0, 350.0);
    glVertex2f(630.0, 390.0);
    glVertex2f(590.0, 390.0);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0 / 255 * 137, 1.0 / 255 * 135, 1.0 / 255 * 144);
    glVertex2f(590.0, 410.0);
    glVertex2f(630.0, 410.0);
    glVertex2f(630.0, 450.0);
    glVertex2f(590.0, 450.0);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0 / 255 * 137, 1.0 / 255 * 135, 1.0 / 255 * 144);
    glVertex2f(590.0, 470.0);
    glVertex2f(630.0, 470.0);
    glVertex2f(630.0, 510.0);
    glVertex2f(590.0, 510.0);

    glEnd();


    //third column 
    glBegin(GL_QUADS);
    glColor3f(1.0 / 255 * 137, 1.0 / 255 * 135, 1.0 / 255 * 144);
    glVertex2f(660.0, 350.0);
    glVertex2f(700.0, 350.0);
    glVertex2f(700.0, 390.0);
    glVertex2f(660.0, 390.0);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0 / 255 * 137, 1.0 / 255 * 135, 1.0 / 255 * 144);
    glVertex2f(660.0, 410.0);
    glVertex2f(700.0, 410.0);
    glVertex2f(700.0, 450.0);
    glVertex2f(660.0, 450.0);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0 / 255 * 137, 1.0 / 255 * 135, 1.0 / 255 * 144);
    glVertex2f(660.0, 470.0);
    glVertex2f(700.0, 470.0);
    glVertex2f(700.0, 510.0);
    glVertex2f(660.0, 510.0);

    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1.0 / 255 * 150, 1.0 / 255 * 75, 1.0 / 255 * 0);
    glVertex2f(820.0, 280.0);
    glVertex2f(840.0, 280.0);
    glVertex2f(840.0, 450.0);
    glVertex2f(820.0, 450.0);

    glEnd();

    glColor3f(1.0 / 255 * 21, 1.0 / 255 * 71, 1.0 / 255 * 75);
    circle(50, 60, 830, 420);
    circle(20, 30, 790, 420);
    circle(30, 35, 830, 470);
    circle(20, 30, 870, 420);


    //sun

    glColor3f(1.0 / 255 * 253, 1.0 / 255 * 183, 1.0 / 255 * 19);
    circle(50, 60, 450, 820);




    //Airplane


    glBegin(GL_POLYGON);
    glColor3f(1.0 / 255 * 59, 1.0 / 255 * 72, 1.0 / 255 * 117);
    glVertex2f(air + 150.0, 800.0);
    glVertex2f(air + 250.0, 800.0);
    glVertex2f(air + 250.0, 840.0);
    glVertex2f(air + 150.0, 840.0);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.0 / 255 * 164, 1.0 / 255 * 165, 1.0 / 255 * 169);
    glVertex2f(air + 250.0, 800.0);
    glVertex2f(air + 280.0, 810.0);
    glVertex2f(air + 250.0, 840.0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0 / 255 * 59, 1.0 / 255 * 72, 1.0 / 255 * 117);
    glVertex2f(air + 175.0, 840.0);
    glVertex2f(air + 200.0, 840.0);
    glVertex2f(air + 190.0, 870.0);
    glVertex2f(air + 175.0, 870.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0 / 255 * 59, 1.0 / 255 * 72, 1.0 / 255 * 117);
    glVertex2f(air + 220.0, 840.0);
    glVertex2f(air + 235.0, 840.0);
    glVertex2f(air + 220.0, 860.0);
    glVertex2f(air + 205.0, 860.0);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.0 / 255 * 59, 1.0 / 255 * 72, 1.0 / 255 * 117);
    glVertex2f(air + 200.0, 770.0);
    glVertex2f(air + 215.0, 770.0);
    glVertex2f(air + 225.0, 800.0);
    glVertex2f(air + 200.0, 800.0);
    glEnd();

    //air box

    glBegin(GL_POLYGON);
    glColor3f(1.0 / 255 * 164, 1.0 / 255 * 165, 1.0 / 255 * 169);
    glVertex2f(air + 154.0, 810.0);
    glVertex2f(air + 174.0, 810.0);
    glVertex2f(air + 174.0, 830.0);
    glVertex2f(air + 154.0, 830.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0 / 255 * 164, 1.0 / 255 * 165, 1.0 / 255 * 169);
    glVertex2f(air + 178.0, 810.0);
    glVertex2f(air + 198.0, 810.0);
    glVertex2f(air + 198.0, 830.0);
    glVertex2f(air + 178.0, 830.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0 / 255 * 164, 1.0 / 255 * 165, 1.0 / 255 * 169);
    glVertex2f(air + 202.0, 810.0);
    glVertex2f(air + 222.0, 810.0);
    glVertex2f(air + 222.0, 830.0);
    glVertex2f(air + 202.0, 830.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0 / 255 * 164, 1.0 / 255 * 165, 1.0 / 255 * 169);
    glVertex2f(air + 226.0, 810.0);
    glVertex2f(air + 246.0, 810.0);
    glVertex2f(air + 246.0, 830.0);
    glVertex2f(air + 226.0, 830.0);
    glEnd();


    //air moving


    if (air <= 900)
    {
        air = air + 0.15;
        glutPostRedisplay();
    }

    else {
        air = -200;
        glutPostRedisplay();
    }


    //bus 



    glBegin(GL_POLYGON);
    glColor3f(1.0 / 255 * 155, 1.0 / 255 * 135, 1.0 / 255 * 12);

    glVertex2f(bus + 300.0, 170.0);
    glVertex2f(bus + 480.0, 170.0);
    glVertex2f(bus + 480.0, 260.0);
    glVertex2f(bus + 300.0, 260.0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0 / 255 * 236, 1.0 / 255 * 183, 1.0 / 255 * 83);
    glVertex2f(bus + 300.0, 260.0);
    glVertex2f(bus + 480.0, 260.0);
    glVertex2f(bus + 472.0, 270.0);
    glVertex2f(bus + 320.0, 270.0);

    glEnd();



    glBegin(GL_POLYGON);
    glColor3f(1.0 / 255 * 168, 1.0 / 255 * 204, 1.0 / 255 * 215);
    glVertex2f(bus + 451.0, 225.0);
    glVertex2f(bus + 480.0, 225.0);
    glVertex2f(bus + 480.0, 260.0);
    glVertex2f(bus + 451.0, 260.0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0 / 255 * 76, 1.0 / 255 * 67, 1.0 / 255 * 65);
    glVertex2f(bus + 300.0, 225.0);
    glVertex2f(bus + 450.0, 225.0);
    glVertex2f(bus + 450.0, 260.0);
    glVertex2f(bus + 300.0, 260.0);

    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(bus + 300.0, 225.0);
    glVertex2f(bus + 480.0, 225.0);

    glVertex2f(bus + 315.0, 225.0);
    glVertex2f(bus + 315.0, 250.0);

    glVertex2f(bus + 330.0, 225.0);
    glVertex2f(bus + 330.0, 250.0);


    glVertex2f(bus + 345.0, 225.0);
    glVertex2f(bus + 345.0, 250.0);

    glVertex2f(bus + 360.0, 225.0);
    glVertex2f(bus + 360.0, 250.0);

    glVertex2f(bus + 375.0, 225.0);
    glVertex2f(bus + 375.0, 250.0);

    glVertex2f(bus + 390.0, 225.0);
    glVertex2f(bus + 390.0, 250.0);

    glVertex2f(bus + 405.0, 225.0);
    glVertex2f(bus + 405.0, 250.0);

    glVertex2f(bus + 420.0, 225.0);
    glVertex2f(bus + 420.0, 250.0);


    glVertex2f(bus + 435.0, 225.0);
    glVertex2f(bus + 435.0, 250.0);

    glEnd();

    glColor3f(0, 0, 0);
    circle(14, 15, bus + 330, 170);
    circle(14, 15, bus + 450, 170);

    glColor3f(1.0 / 255 * 106, 1.0 / 255 * 108, 1.0 / 255 * 109);
    circle(10, 11, bus + 330, 170);
    circle(10, 11, bus + 450, 170);



    if (bus <= 900)
    {
        bus = bus + 0.12;
        glutPostRedisplay();
    }

    else {
        bus = -300;
        glutPostRedisplay();
    }







    glFlush();




    glutSwapBuffers();
}

int main(int argc, char** argv) {
    PlaySound("D:\Study\\fall22\\Computer-Graphics-main\\OpenGL Programming\\project\highway-14475.wav", NULL, SND_ASYNC);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1200, 720);
    glutCreateWindow("LAB Project");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}

