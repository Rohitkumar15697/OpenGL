#include<windows.h>
#include<GL/glut.h>
#include<math.h>


float r=0.12;
float dist=-40;      // car born coordinate
int state=1;
//x,y,z for lookAt coordinates
float x=0;
float y=0;
float z=20;


float zx=0;
float zy=0;
float zz=-1;



void reshape(int w,int h)
{
        glViewport(0,0,w,h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(50,w/h,1,1000.0);
        glMatrixMode(GL_MODELVIEW);

}



void timer(int value)
{
     glutPostRedisplay();
       glutTimerFunc(5,timer,0);

    switch(state)
    {
    case 1:
    if(dist<45)
    {
         dist+=0.025;
    }
    else
        state=0;
        break;

    case 0:
        if(dist>-40)
        {
            dist=-40;
            glLoadIdentity();
        }
            state=-1;
            break;

    case -1:
        if(dist<45)
        {
         dist+=0.025;
         glLoadIdentity();

        }
            state=1;
        break;



}

}

//KeyBoard Function
void mykey(unsigned char key,int xp,int yp)
{

    if(key=='w')
    {
        z-=0.15;
        zz-=0.15;

    }
    if(key=='s')
    {
        z+=0.15;
        zz+=0.15;
    }

    if(key=='a')
    {
        x-=0.15;
        zx-=0.15;
    }
    if(key=='d')
    {
        x+=0.15;
        zx+=0.15;
    }

    if(key=='z')
    {
        y+=0.15;
        zy+=0.15;
    }
    if(key=='x')
    {
        y=1;
        zx=0;
        zy=0;
        zz=-1;
    }
     glutPostRedisplay();
}



void mymouse(int button,int state,int px,int py)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        zx-=0.1;
    }

    if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
    {
        zx+=0.1;
    }
}




void drawcar(float dist)
{

    //CAR
    glTranslatef(dist,-0.12,-4);
    //glRotatef(angle,2,1,0);


    //car side 1
    glBegin(GL_POLYGON);
    glColor3f(1,0.1,0.5);

    glVertex3f(-0.8,-0.3,0.2);        //lower left point

    glVertex3f(-0.8,-0.1,0.2);

    glVertex3f(-0.5,-0.1,0.2);

    glVertex3f(-0.3,0.1,0.2);   //top left point

      glColor3f(1,0,1);
    glVertex3f(0.2,0.1,0.2);        //top right point

    glVertex3f(0.5,-0.1,0.2);

    glVertex3f(0.82,-0.1,0.2);

    glVertex3f(0.82,-0.3,0.2);          //lower right point

    glEnd();

    //car view from -z axis  side2
    glBegin(GL_POLYGON);

    glVertex3f(-0.8,-0.3,-0.2);        //lower left point

    glVertex3f(-0.8,-0.1,-0.2);

    glVertex3f(-0.5,-0.1,-0.2);

    glVertex3f(-0.3,0.1,-0.2);   //top left point

      glColor3f(1,0,1);
    glVertex3f(0.2,0.1,-0.2);        //top right point

    glVertex3f(0.5,-0.1,-0.2);

    glVertex3f(0.82,-0.1,-0.2);

    glVertex3f(0.82,-0.3,-0.2);          //lower right point
    glEnd();



    //upper view
    glBegin(GL_QUADS);
      glColor3f(0,0,1);

    //top upper view
   glVertex3f(-0.3,0.1,0.2);        //left corner
   glVertex3f(0.2,0.1,0.2);     //right corner
   glVertex3f(0.2,0.1,-0.2);        //right corner
   glVertex3f(-0.3,0.1,-0.2);   //left corner



    glColor3f(0.2,0.2,0.2);
   //left back top
   glVertex3f(-0.3,0.1,-0.2);
   glVertex3f(-0.55,-0.1,-0.2);
   glVertex3f(-0.55,-0.1,0.2);
   glVertex3f(-0.3,0.1,0.2);


   //right front top view
    //glColor3f(1,1,1.5);
    glVertex3f(0.2,0.1,-0.2);
     glVertex3f(0.2,0.1,0.2);
     glVertex3f(0.5,-0.1,0.2);
      glVertex3f(0.5,-0.1,-0.2);


    // front top view engine
    glColor3f(0,0,1);
        glVertex3f(0.5,-0.1,0.2);
      glVertex3f(0.5,-0.1,-0.2);
      glVertex3f(0.82,-0.1,-0.2);
      glVertex3f(0.82,-0.1,0.2);



      //back top view
       glVertex3f(-0.8,-0.1,0.2);
      glVertex3f(-0.55,-0.1,0.2);
        glVertex3f(-0.55,-0.1,-0.2);
          glVertex3f(-0.8,-0.1,-0.2);


          //front headlight view
          glColor3f(0.5,0,0.2);
               glVertex3f(0.82,-0.1,-0.2);
                glVertex3f(0.82,-0.1,0.2);
                  glVertex3f(0.82,-0.3,0.2);
                    glVertex3f(0.82,-0.3,-0.2);

            //headlights
            glColor3f(1,1,1);
            glVertex3f(0.821,-0.15,0.15);
            glVertex3f(0.821,-0.15,0.05);
            glVertex3f(0.821,-0.25,0.05);
            glVertex3f(0.821,-0.25,0.15);

            glVertex3f(0.821,-0.15,-0.15);
            glVertex3f(0.821,-0.15,-0.05);
            glVertex3f(0.821,-0.25,-0.05);
            glVertex3f(0.821,-0.25,-0.15);

        //back light view
        glColor3f(0.5,0.5,0.5);
        glVertex3f(-0.8,-0.1,0.2);
        glVertex3f(-0.8,-0.1,-0.2);
           glVertex3f(-0.8,-0.3,-0.2);
              glVertex3f(-0.8,-0.3,0.2);


              //bottom view
               glColor3f(0.3,0.2,0.1);
                glVertex3f(-0.8,-0.3,0.2);
                 glVertex3f(-0.8,-0.3,-0.2);
                  glVertex3f(0.82,-0.3,-0.2);
                   glVertex3f(0.82,-0.3,0.2);


    glEnd();


      //Windows
     glColor3f(0.2,0.2,0.2);
    glBegin(GL_TRIANGLES);
    //left window in front view
    glVertex3f(-0.29,0.09,0.201);
    glVertex3f(-0.29,-0.1,0.201);
    glVertex3f(-0.53,-0.1,0.201);

    //behind above window in z-axis
      glVertex3f(-0.29,0.09,-0.201);
    glVertex3f(-0.29,-0.1,-0.201);
    glVertex3f(-0.53,-0.1,-0.201);

    //right window in front view
      glVertex3f(0.19,0.09,0.201);
      glVertex3f(0.19,-0.1,0.201);
      glVertex3f(0.47,-0.1,0.201);

      //behind above window
      glVertex3f(0.19,0.09,-0.201);
      glVertex3f(0.19,-0.1,-0.201);
      glVertex3f(0.47,-0.1,-0.201);

    glEnd();

    //center window
    glBegin(GL_QUADS);
      glVertex3f(-0.28,0.09,0.201);
    glVertex3f(-0.28,-0.1,0.201);
      glVertex3f(0.18,-0.1,0.201);
      glVertex3f(0.18,0.09,0.201);

      //behind the above window
        glVertex3f(-0.28,0.09,-0.201);
    glVertex3f(-0.28,-0.1,-0.201);
      glVertex3f(0.18,-0.1,-0.201);
      glVertex3f(0.18,0.09,-0.201);

    glEnd();


    //tyres
    //left circles
    glTranslatef(-0.39,-0.3,0.2001);
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    for(int i=0;i<=360;i++)
    {
        glVertex3f(r*cos(i),r*sin(i),0);
    }
    glEnd();


    //right circle
     glTranslatef(0.7,0,0);
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    for(int i=0;i<=360;i++)
    {
        glVertex3f(r*cos(i),r*sin(i),0);
    }
    glEnd();


    //z axis circles
     glTranslatef(-0.7,0,-0.401);
       glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    for(int i=0;i<=360;i++)
    {
        glVertex3f(r*cos(i),r*sin(i),0);
    }
    glEnd();


    //right circle
     glTranslatef(0.7,0,0);
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    for(float i=0;i<=360;i++)
    {
        glVertex3f(r*cos(i),r*sin(i),0);
    }
    glEnd();

}





void road()
{

    //road
      glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-170,-0.67,-5.5);
    glVertex3f(170,-0.67,-5.5);
    glVertex3f(170,-0.67,-1.6);
    glVertex3f(-170,-0.67,-1.6);


    //left side and right side lane
        glColor3f(1,1,1);
        //home side lane
        glVertex3f(-170,-0.66,-2);
        glVertex3f(170,-0.66,-2);
        glVertex3f(170,-0.66,-2.1);
        glVertex3f(-170,-0.66,-2.1);
        //eye side lane

         glVertex3f(-170,-0.66,-5.1);
        glVertex3f(170,-0.66,-5.1);
        glVertex3f(170,-0.66,-5);
        glVertex3f(-170,-0.66,-5);


       //white center Lane
        glColor3f(1,1,1);
          glVertex3f(2.5,-0.6,-3.65);
        glVertex3f(2.7,-0.6,-3.65);
        glVertex3f(2.7,-0.6,-3.75);
        glVertex3f(2.5,-0.6,-3.75);

          glVertex3f(2,-0.6,-3.65);
        glVertex3f(2.2,-0.6,-3.65);
        glVertex3f(2.2,-0.6,-3.75);
        glVertex3f(2,-0.6,-3.75);

        glVertex3f(1.5,-0.6,-3.65);
        glVertex3f(1.7,-0.6,-3.65);
        glVertex3f(1.7,-0.6,-3.75);
        glVertex3f(1.5,-0.6,-3.75);

        glVertex3f(1.2,-0.6,-3.65);
        glVertex3f(1,-0.6,-3.65);
        glVertex3f(1,-0.6,-3.75);
        glVertex3f(1.2,-0.6,-3.75);

        glVertex3f(0.5,-0.6,-3.65);
        glVertex3f(0.7,-0.6,-3.65);
        glVertex3f(0.7,-0.6,-3.75);
        glVertex3f(0.5,-0.6,-3.75);

        glVertex3f(0,-0.6,-3.65);
        glVertex3f(0.2,-0.6,-3.65);
        glVertex3f(0.2,-0.6,-3.75);
        glVertex3f(0,-0.6,-3.75);

          glVertex3f(-0.5,-0.6,-3.65);
        glVertex3f(-0.3,-0.6,-3.65);
        glVertex3f(-0.3,-0.6,-3.75);
        glVertex3f(-0.5,-0.6,-3.75);

          glVertex3f(-1,-0.6,-3.65);
        glVertex3f(-0.8,-0.6,-3.65);
        glVertex3f(-0.8,-0.6,-3.75);
        glVertex3f(-1,-0.6,-3.75);

         glVertex3f(-1.5,-0.6,-3.65);
        glVertex3f(-1.3,-0.6,-3.65);
        glVertex3f(-1.3,-0.6,-3.75);
        glVertex3f(-1.5,-0.6,-3.75);

        glVertex3f(-1.8,-0.6,-3.65);
        glVertex3f(-2,-0.6,-3.65);
        glVertex3f(-2,-0.6,-3.75);
        glVertex3f(-1.8,-0.6,-3.75);

        glVertex3f(-2.3,-0.6,-3.65);
        glVertex3f(-2.5,-0.6,-3.65);
        glVertex3f(-2.5,-0.6,-3.75);
        glVertex3f(-2.3,-0.6,-3.75);

        glEnd();
}






void home()
{
        glTranslatef(3,0,0);


        glBegin(GL_QUADS);
        //front
        glColor3f(0.1,0.5,0.8);
        glVertex3f(-1,-0.5,-9);
        glVertex3f(2,-0.5,-9);
        glVertex3f(2,2,-9);
        glVertex3f(-1,2,-9);

        //gate
        glColor3f(0,0,0);
        glVertex3f(0.2,-0.4,-8.99);
        glVertex3f(0.7,-0.4,-8.99);
        glVertex3f(0.7,1.1,-8.99);
        glVertex3f(0.2,1.1,-8.99);

        //left side
            glColor3f(1,0,1);
         glVertex3f(-1,-0.5,-9);
        glVertex3f(-1,2,-9);
        glVertex3f(-1,2,-11);
        glVertex3f(-1,-0.5,-11);

        //right side
            glColor3f(0.1,1,0.8);
         glVertex3f(2,-0.5,-9);
        glVertex3f(2,2,-9);
        glVertex3f(2,2,-11);
        glVertex3f(2,-0.5,-11);

        //back side
            glColor3f(0.1,0.5,0.8);
        glVertex3f(-1,2,-11);
        glVertex3f(-1,-0.5,-11);
        glVertex3f(2,-0.5,-11);
        glVertex3f(2,2,-11);

        //upper left
            glColor3f(0.1,1,1);
        glVertex3f(-1,2,-11);
        glVertex3f(0.5,3.2,-11);
        glVertex3f(0.5,3.2,-9);
        glVertex3f(-1,2,-9);

        //upper right
            glColor3f(1,1,0.8);
        glVertex3f(0.5,3.2,-9);
        glVertex3f(0.5,3.2,-11);
        glVertex3f(2,2,-11);
        glVertex3f(2,2,-9);

        glEnd();


        //upper triangles
        glBegin(GL_TRIANGLES);
        //front triangle
        glColor3f(1,0,1);
        glVertex3f(-1,2,-9);
        glVertex3f(2,2,-9);
        glVertex3f(0.5,3.2,-9);

        //back triangle
          glVertex3f(-1,2,-11);
        glVertex3f(2,2,-11);
        glVertex3f(0.5,3.2,-11);
        glEnd();





}

void tree()
{

        //treees
        glColor3f(0.5,0.5,0.5);
        glBegin(GL_POLYGON);
        glVertex3f(0.1,-1,-50);
        glVertex3f(0.1,4,-50);
        glVertex3f(0.9,4,-50);
        glVertex3f(0.9,-1,-50);
        glEnd();



        glColor3f(0,0.7,0);

        glTranslatef(0.4,3,-50);
        glRotatef(90,-1,0,0);
        glutSolidCone(2,8,10,10);
        glLoadIdentity();
}





void rock()
{
     glColor3f(0.4,0.4,0.4);
    glBegin(GL_POLYGON);
    //rock left side of road
    glVertex3f(-108,-0.5,80);
    glVertex3f(-108,40,50);
    glVertex3f(-108,30,45);
    glVertex3f(-108,40,40);
    glVertex3f(-108,10,25);
    glVertex3f(-108,45,20);
    glVertex3f(-108,-0.5,-4);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-108,-0.5,-8);
    glVertex3f(-108,35,-25);
    glVertex3f(-108,20,-35);
    glVertex3f(-108,35,-40);
    glVertex3f(-108,-0.5,-65);
    glEnd();


}




void sky()
{
      //sky
    glColor3f(0.9,1,1);
    glBegin(GL_QUADS);
    glVertex3f(-170,-1,200);
    glVertex3f(-170,200,200);
    glVertex3f(-170,200,-200);
    glVertex3f(-170,-1,-200);

    glVertex3f(-170,-1,-200);
    glVertex3f(-170,200,-200);
    glVertex3f(170,200,-200);
    glVertex3f(170,-1,-200);

    glVertex3f(170,-1,200);
    glVertex3f(170,200,200);
    glVertex3f(170,200,-200);
    glVertex3f(170,-1,-200);

    glVertex3f(170,-1,200);
    glVertex3f(170,200,200);
    glVertex3f(-170,200,200);
    glVertex3f(-170,-1,200);
    glEnd();

}







void display()
{

     glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

        glClearColor(0,1,0,1);


            gluLookAt(x,y,z,zx,zy,zz,0,1,0);


            road();
            drawcar(dist);
            glLoadIdentity();

            gluLookAt(x,y,z,zx,zy,zz,0,1,0);
            glRotatef(180,0,1,0);
            glTranslatef(-5,-0.13,7);
            drawcar(dist);
            glLoadIdentity();


            //call home 3 times

             gluLookAt(x,y,z,zx,zy,zz,0,1,0);
                 glTranslatef(-8,-0.2,0);
            home();

            glLoadIdentity();

            gluLookAt(x,y,z,zx,zy,zz,0,1,0);
            glTranslatef(5,-0.1,0);
            home();

            glLoadIdentity();

            gluLookAt(x,y,z,zx,zy,zz,0,1,0);
            glTranslatef(-25,-0.1,0);
            home();



             glLoadIdentity();

                //call rock


                 gluLookAt(x,y,z,zx,zy,zz,0,1,0);
                 glTranslatef(-16,0,2.5);
             rock();
               sky();
               glTranslatef(0,0,-110);
                 rock();
                  glTranslatef(0,0,220);
                 rock();


                glLoadIdentity();
                  gluLookAt(x,y,z,zx,zy,zz,0,1,0);
                glRotatef(90,0,1,0);
                 glTranslatef(280,-0.3,-100);

             rock();
               glTranslatef(0,0,130);

             rock();





    glLoadIdentity();
     gluLookAt(x,y,z,zx,zy,zz,0,1,0);
     tree();
     glLoadIdentity();
     gluLookAt(x,y,z,zx,zy,zz,0,1,0);
     glTranslatef(-28,0,-10);
    tree();
    glLoadIdentity();
    gluLookAt(x,y,z,zx,zy,zz,0,1,0);
     glTranslatef(-22,0,-6);
    tree();
    glLoadIdentity();
    gluLookAt(x,y,z,zx,zy,zz,0,1,0);
     glTranslatef(-16,0,-2);
    tree();
    glLoadIdentity();
    gluLookAt(x,y,z,zx,zy,zz,0,1,0);
     glTranslatef(-10,0,2);
    tree();
    glLoadIdentity();
    gluLookAt(x,y,z,zx,zy,zz,0,1,0);
     glTranslatef(-4,0,4);
    tree();
    glLoadIdentity();
    gluLookAt(x,y,z,zx,zy,zz,0,1,0);
     glTranslatef(2,0,8);
    tree();
    glLoadIdentity();
    gluLookAt(x,y,z,zx,zy,zz,0,1,0);
     glTranslatef(8,0,5);
    tree();
    glLoadIdentity();
    gluLookAt(x,y,z,zx,zy,zz,0,1,0);
     glTranslatef(14,0,10);
    tree();
    glLoadIdentity();
    gluLookAt(x,y,z,zx,zy,zz,0,1,0);
     glTranslatef(20,0,18);
    tree();
    glLoadIdentity();
    gluLookAt(x,y,z,zx,zy,zz,0,1,0);
     glTranslatef(26,0,15);
    tree();
    gluLookAt(x,y,z,zx,zy,zz,0,1,0);
     glTranslatef(32,0,0);
    tree();
    glLoadIdentity();
    gluLookAt(x,y,z,zx,zy,zz,0,1,0);
     glTranslatef(38,0,-3);
    tree();




    glFlush();
    glutSwapBuffers();
}











int main(int a,char**b)
{
    glutInit(&a,b);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowPosition(100,10);
    glutInitWindowSize(900,600);
    glutCreateWindow("nothing");
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);



    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
  glutTimerFunc(5,timer,0);
  glutKeyboardFunc(mykey);
  glutMouseFunc(mymouse);
    glutMainLoop();
}
