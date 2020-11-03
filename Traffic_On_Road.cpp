#include<GL/glut.h>


float x=-180;
float y=-180;
float z=-180;
float p=-180;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glBegin(GL_LINES);
    glVertex2d(-290,-100);
    glVertex2d(290,-100);

    glVertex2d(-290,-220);
    glVertex2d(290,-220);

    glEnd();


        glBegin(GL_QUADS);

        glVertex2d(x,-155);
        glVertex2d(x+50,-155);
        glVertex2d(x+50,-165);
        glVertex2d(x,-165);

          glVertex2d(y+150,-155);
        glVertex2d(y+200,-155);
        glVertex2d(y+200,-165);
        glVertex2d(y+150,-165);

         glVertex2d(z+300,-155);
        glVertex2d(z+350,-155);
        glVertex2d(z+350,-165);
        glVertex2d(z+300,-165);

         glVertex2d(p+450,-155);
        glVertex2d(p+500,-155);
        glVertex2d(p+500,-165);
        glVertex2d(p+450,-165);
        glEnd();

        //car
         glBegin(GL_QUADS);
        glVertex2d(10,-135);
        glVertex2d(90,-135);
        glVertex2d(90,-180);
        glVertex2d(10,-180);

        glVertex2d(90,-140);
        glVertex2d(110,-140);
        glVertex2d(110,-175);
        glVertex2d(90,-175);
        glEnd();

    glFlush();
    glutSwapBuffers();
}
void reshape(int w,int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-300,300,-300,300);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int value)
{
    glutTimerFunc(1,timer,0);
    glutPostRedisplay();
    x-=0.5;
    y-=0.5;
    z-=0.5;
    p-=0.5;
    if(x==-340)
    {

        x=310;
    }
    if(y==-500)
    {

        y=150;
    }
    if(z==-650)
    {

        z=0;
    }
    if(p==-800)
    {

        p=-150;
    }


}

int main(int a,char**b)
{
    glutInit(&a,b);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    glutInitWindowPosition(200,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("traffic ");
        glutDisplayFunc(display);
        glutReshapeFunc(reshape);
        glutTimerFunc(1,timer,0);
    glutMainLoop();
}
