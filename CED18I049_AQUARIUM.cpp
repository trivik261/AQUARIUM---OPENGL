//SHARAN SK-CED18I049
//ICG PROJECT - AQUARIUM

//#include<windows.h>   //Uncomment this line for Running Windows OS
#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>

float a=0,d=0,f=0,h=0,i=0,k=0,l=0,m=0,n=0,p=0,q=0,x=0,y=0,sandf=0;
float translation[3];
float scale[3];
float colorb[3],colorf1s1[3],colorf1s2[3],colorf2s1[3],colorf2s2[3],colort[3];

//Function to Draw a Point
void draw_pixel(GLfloat cx,GLfloat cy,GLfloat color1,GLfloat color2,GLfloat color3,GLint size)
{
  glColor3f(color1,color2,color3);
  glPointSize(size);
  glBegin(GL_POINTS);
  glVertex2f(cx,cy);
  glEnd();
}

//Function to Draw a Point
void plotpixels(GLint h,GLint k,GLint x,GLint y)
{
  draw_pixel(x+h,y+k,1,1,1,3);
  draw_pixel(-x+h,y+k,1,1,1,3);
  draw_pixel(x+h,-y+k,1,1,1,3);
  draw_pixel(-x+h,-y+k,1,1,1,3);
  draw_pixel(y+h,x+k,1,1,1,3);
  draw_pixel(-y+h,x+k,1,1,1,3);
  draw_pixel(y+h,-x+k,1,1,1,3);
  draw_pixel(-y+h,-x+k,1,1,1,3);
}

//Function to Draw a Circle
void circle_draw(GLint h,GLint k,GLint r)
{
  GLint d=1-r,x=0,y=r;
  while(y>x)
  {
    plotpixels(h,k,x,y);
    if(d<0)
      d+=2*x+3;
    else
    {
      d+=2*(x-y)+5;
      --y;
    }
    ++x;
  }
  plotpixels(h,k,x,y);
}
//Draw bubbles
void bubbles_1(float t1,float t2)
{
  glPushMatrix();
  if(h<0.03)
  {
    gluOrtho2D(0.0,640,0.0,480);
  }
  else
  {
    glTranslatef(t1,y-t2,0);
    gluOrtho2D(0.0,640,0.0,480);
    circle_draw(20,20,7);
  }
  glPopMatrix();

}

//Draw fishes
void fish1(float startx,float starty,float translation[],float scale[],float colorb[],float colort[],float colorf1s1[],float colorf1s2[],float colorf2s1[],float colorf2s2[],int modex,int modey,int anim)
{
  if(anim==1)
  glPushMatrix();                       //Ensure The Object(Stationary Objects in the frame) before the fish animation are saved                                 

  glTranslatef(modex*translation[0],modey* translation[1],translation[2]);              //Move the Fish along X-axis
  glScalef(scale[0], scale[1], scale[2]);

  glColor3f(colorb[0],colorb[1],colorb[2]);
                 //Set Color for the fish
  
  glBegin(GL_POLYGON);                  //Create Body of the fish
    
    glVertex2f(modex*(startx),modey*starty);
    glVertex2f(modex*(startx+0.05),modey*(starty+0.05));
    glVertex2f(modex*(startx+0.15),modey*starty);
    glVertex2f(modex*(startx+0.05),modey*(starty-0.05));

  glEnd();

                                        
  glBegin(GL_TRIANGLES);                //Create Tail of the fish

    glColor3f(colort[0],colort[1],colort[2]);

    glVertex2f(modex*(startx+0.13),modey*starty);
    glVertex2f(modex*(startx+0.2),modey*(starty+0.04));
    glVertex2f(modex*(startx+0.2),modey*(starty-0.04));

  glEnd();

  glBegin(GL_TRIANGLES);                //Create Fin1 of the fish
   
    glColor3f(colorf1s1[0],colorf1s1[1],colorf1s1[2]);
    glVertex2f(modex*(startx+0.05),modey*(starty+0.045));
    
    glColor3f(colorf1s2[0],colorf1s2[1],colorf1s2[2]);
    glVertex2f(modex*(startx+0.09),modey*(starty+0.075));
    glVertex2f(modex*(startx+0.07),modey*(starty+0.02));

  glEnd();

  glBegin(GL_TRIANGLES);                //Create Fin2 of the fish
  
    glColor3f(colorf2s1[0],colorf2s1[1],colorf2s1[2]);
    glVertex2f(modex*(startx+0.05),modey*(starty-0.043));

    glColor3f(colorf2s2[0],colorf2s2[1],colorf2s2[2]);
    glVertex2f(modex*(startx+0.095),modey*(starty-0.085));
    glVertex2f(modex*(startx+0.07),modey*(starty-0.03));

  glEnd();


  glColor3f(0.0,0.0,0.0);
  glPointSize(4.0);
  glBegin(GL_POINTS);                   //Create Eye of the fish
    glVertex2f(modex*(startx+0.03),modey*(starty+0.015));
  glEnd();

  if(anim==1)
  glPopMatrix();                        //Ensure The Animations are popped out
}

//Draw plants
void plant()
{
  glColor3f(0.0,1.0,0.0); 											// Set Color to Green.
  glLineWidth(4.0);												// Increase the Width of each line.		
  for(int i=0;i<5;i++)												// Creates Five plant mimicking Lines with equal spacing
  {																          // and alternating plants up and down 
    glBegin(GL_LINES);
      
    glVertex2f(0.9-(i*0.4),-0.8-((i%2)*0.015)+0.065);
    glVertex2f(0.8-(i*0.4),-0.9-((i%2)*0.015)+0.065);
    glVertex2f(0.8-(i*0.4),-0.8-((i%2)*0.015)+0.065);
    glVertex2f(0.8-(i*0.4),-0.9-((i%2)*0.015)+0.065);
    glVertex2f(0.7-(i*0.4),-0.8-((i%2)*0.015)+0.065);
    glVertex2f(0.8-(i*0.4),-0.9-((i%2)*0.015)+0.065);
    glVertex2f(0.75-(i*0.4),-0.8-((i%2)*0.015)+0.065);
    glVertex2f(0.8-(i*0.4),-0.9-((i%2)*0.015)+0.065);
    glVertex2f(0.85-(i*0.4),-0.8-((i%2)*0.015)+0.065);
    glVertex2f(0.8-(i*0.4),-0.9-((i%2)*0.015)+0.065);
    glVertex2f(0.725-(i*0.4),-0.8-((i%2)*0.015)+0.065);
    glVertex2f(0.8-(i*0.4),-0.9-((i%2)*0.015)+0.065);
    glVertex2f(0.775-(i*0.4),-0.8-((i%2)*0.015)+0.065);
    glVertex2f(0.8-(i*0.4),-0.9-((i%2)*0.015)+0.065);
    glVertex2f(0.825-(i*0.4),-0.8-((i%2)*0.015)+0.065);
    glVertex2f(0.8-(i*0.4),-0.9-((i%2)*0.015)+0.065);
    glVertex2f(0.875-(i*0.4),-0.8-((i%2)*0.015)+0.065);
    glVertex2f(0.8-(i*0.4),-0.9-((i%2)*0.015)+0.065);

    glEnd();
  }

}
//Draw a Sand object
void sand()
{
  glPushMatrix();
  glTranslatef(2*sandf,0,0);
  glColor3f(1.0,1.0,0.7);
  glBegin(GL_POLYGON);
  glVertex2f(-1.6,-1.0);
  glVertex2f(-1.6,-0.700);
  glVertex2f(-0.8,-0.800);
  glVertex2f(-0.2,-0.850);
  glVertex2f(0,-0.800);
  glVertex2f(0.4,-0.850);
  glVertex2f(0.8,-0.800);
  glVertex2f(1.4,-0.800);
  glVertex2f(1.4,-1.0);
  glEnd();
  glFlush();
  glPopMatrix();
}


void myinit()
{
  glClearColor(0.4,1.0,1.0,0.0);
  glColor3f(1.0,1.0,0.0);
}

//Idle function to Process Animation variables continuously
void idle()
{
  h+=0.0002;
  i-=0.00024;
  k+=0.00009;
  l+=0.0002;
  m+=0.000055;
  n+=0.0002;
  p+=0.00007;
  q+=0.0001;
  x-=0.0001;
  y+=0.0002;
  glutPostRedisplay();
}

//Display Function for First Frame
void disp2(void)
{
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glColor3f(1.0,0.0,0.0);
  glPointSize(2.0);

  if(a>=-1.02)
  a=a-0.0005;
  else
  a=0;

  if(f>=-1.02)
  f=f-0.0005;
  else
  f=0;

  if(sandf>=-0.2)
  sandf=sandf-0.0005;
  else
  sandf=0;

  bubbles_1(0.7,0.5);
  bubbles_1(1,0.3);
  bubbles_1(1.3,0.64);

  plant();
  sand();

  translation[1]=translation[2]=0; translation[0]=2*a;
  scale[0]=scale[1]=scale[2]=1;

  colorb[0]=colorb[2]=0;
  colorb[1]=1;

  colort[0]=colort[1]=0;
  colort[2]=1;

  colorf1s1[0]=colorf1s1[1]=1;
  colorf1s1[2]=0;

  colorf1s2[1]=colorf1s2[2]=0;
  colorf1s2[0]=1;

  colorf2s1[0]=colorf2s1[1]=1;
  colorf2s1[2]=0;

  colorf2s2[1]=colorf2s2[2]=0;
  colorf1s2[0]=1;

  fish1(0.7,0.05,translation,scale,colorb,colort,colorf1s1,colorf1s2,colorf2s1,colorf2s2,1,1,1);  
  translation[1]=translation[2]=0; translation[0]=3*f;
  scale[0]=scale[1]=scale[2]=2;

  colorb[0]=colorb[2]=1;
  colorb[1]=0;
  fish1(0.7,0.25,translation,scale,colorb,colort,colorf1s1,colorf1s2,colorf2s1,colorf2s2,1,1,1);
  fish1(0.7,-0.25,translation,scale,colorb,colort,colorf1s1,colorf1s2,colorf2s1,colorf2s2,-1,1,1);

  glutPostRedisplay();
  glutSwapBuffers();
}

//Create a yellow fish 
void split_fish()
{
  glColor3f(1.0,1.0,0.0);
  glBegin(GL_POLYGON);
    glVertex2f(-0.7+y,-0.05);
    glVertex2f(-0.75+y,-0.1);
    glVertex2f(-0.85+y,-0.05);
    glVertex2f(-0.75+y,0.0);
  glEnd();

  glBegin(GL_TRIANGLES);
    glColor3f(0.8,0.5,0.0);
    glVertex2f(-0.83+y,-0.05);
    glVertex2f(-0.9+y,-0.09);
    glVertex2f(-0.9+y,-0.01);
  glEnd();

  glBegin(GL_TRIANGLES);
    glColor3f(0.8,0.5,0.0);
    glVertex2f(-0.75+y,-0.095);
    glVertex2f(-0.79+y,-0.125);
    glVertex2f(-0.77+y,-0.07);
  glEnd();

  glBegin(GL_TRIANGLES);
    glColor3f(0.8,0.5,0.0);
    glVertex2f(-0.75+y,-0.007);
    glVertex2f(-0.795+y,0.035);
    glVertex2f(-0.77+y,-0.02);
  glEnd();

  glColor3f(0.0,0.0,0.0);
  glPointSize(4.0);
  glBegin(GL_POINTS);
    glVertex2f(-0.73+y,-0.035);
  glEnd();
}

void set_all(float c1,float c2,float c3)
{
  colorb[0]=c1;colorb[1]=c2;colorb[2]=c3;
  colort[0]=c1;colort[1]=c2;colort[2]=c3;
  colorf1s1[0]=c1;colorf1s1[1]=c2;colorf1s1[2]=c3;
  colorf1s2[0]=c1;colorf1s2[1]=c2;colorf1s2[2]=c3;
  colorf2s1[0]=c1;colorf2s1[1]=c2;colorf2s1[2]=c3;
  colorf2s2[0]=c1;colorf2s2[1]=c2;colorf2s2[2]=c3;
}

//Display Function for Poison Animation
void disp3(void)
{
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glColor3f(1.0,0.0,0.0);

  //Create Poison Animation
  glPushMatrix();
  if(x>-0.8)
  {
    glColor3f(1.0,0.0,0.0);
    glPointSize(10.0);
    glBegin(GL_POINTS);
      glVertex2f(0.0,0.30);
    glEnd();
    glTranslatef(x,0.35,0);
  }
  else
  {
    glTranslatef(x,1.95-y,0.0);
    glPointSize(8);
    glBegin(GL_POINTS);
  }

  split_fish();
  glPopMatrix();

  if(a>=-1.99)
  a=a-0.0005;
  else
  a=0;
  
  if(f>=-1.99)
    f=f-0.0002;
  else
    f=0;
  if(sandf>=-0.2)
    sandf=sandf-0.0005;
  else
    sandf=0;

  bubbles_1(0.7,0.5);
  bubbles_1(1,0.3);
  bubbles_1(1.3,0.64);

  plant();
  sand();

  translation[1]=translation[2]=0; translation[0]=2*a;
  scale[0]=scale[1]=scale[2]=1;

  colorb[0]=colorb[2]=0;
  colorb[1]=1;

  colort[0]=colort[1]=0;
  colort[2]=1;

  colorf1s1[0]=colorf1s1[1]=1;
  colorf1s1[2]=0;

  colorf1s2[1]=colorf1s2[2]=0;
  colorf1s2[0]=1;

  colorf2s1[0]=colorf2s1[1]=1;
  colorf2s1[2]=0;

  colorf2s2[1]=colorf2s2[2]=0;
  colorf1s2[0]=1;

  fish1(0.7,0.05,translation,scale,colorb,colort,colorf1s1,colorf1s2,colorf2s1,colorf2s2,1,1,1);  

  translation[1]=translation[2]=0; translation[0]=3*f;
  scale[0]=scale[1]=scale[2]=2;
  colorb[0]=colorb[2]=1;colorb[1]=0;

  fish1(0.7,0.25,translation,scale,colorb,colort,colorf1s1,colorf1s2,colorf2s1,colorf2s2,1,1,1);
  fish1(0.7,-0.25,translation,scale,colorb,colort,colorf1s1,colorf1s2,colorf2s1,colorf2s2,-1,1,1);

  glutPostRedisplay();
  glFlush();
  glutSwapBuffers();
}

//Display Function for Food Animation
void disp1(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glColor3f(1.0,0.0,0.0);

  //Fish 1 Food Animation
  glPushMatrix();
	if(l<0.35)
	{
		draw_pixel(-0.65,0.5,0.5,0.9,0.3,8);
    translation[0]=-k;translation[1]=l;translation[2]=0;
	}
	else
	{
    translation[0]=-k;translation[1]=0.35;translation[2]=0;
	}
  scale[0]=1;scale[1]=1;scale[2]=1;

  set_all(0,1,0);
  fish1(0.8,0.15,translation,scale,colorb,colort,colorf1s1,colorf1s2,colorf2s1,colorf2s2,-1,1,0);  
  glPopMatrix();

  //Fish 2 Food Animation
  glPushMatrix();
	if(n<=0.8)
	{
		draw_pixel(0.235,0.4,1.0,0.0,1.0,8);
    translation[0]=-m;translation[1]=n;translation[2]=0;
  }
	else
	{
    translation[0]=-m;translation[1]=0.8;translation[2]=0;
	}
  set_all(0.5,0.6,0.0);
  fish1(0.7,-0.15,translation,scale,colorb,colort,colorf1s1,colorf1s2,colorf2s1,colorf2s2,1,1,0);  
	glPopMatrix();

  //Fish 3 Food Animation
	glPushMatrix();
	if(q<0.65)
	{
		draw_pixel(0.48,0.66,1.0,0.0,0.0,8);
    translation[0]=-p;translation[1]=q;translation[2]=0;
	}
	else
	{
    translation[0]=-p;translation[1]=0.65;translation[2]=0;
	}
  set_all(0,0,1);
  fish1(0.7,-0.25,translation,scale,colorb,colort,colorf1s1,colorf1s2,colorf2s1,colorf2s2,1,1,0);  
	glPopMatrix();

 if(a>=-1.99)
	 a=a-0.0005;
 else
   a=0;

  if(f>=-1.99)
  f=f-0.0002;
  else
    f=0;

  if(sandf>=-0.2)
    sandf=sandf-0.0005;
  else
    sandf=0;

  bubbles_1(0.7,0.5);
  bubbles_1(1,0.3);
  bubbles_1(1.3,0.64);

  plant();
  sand();

  translation[1]=translation[2]=0; translation[0]=2*a;
  scale[0]=scale[1]=scale[2]=1;
  
  colorb[0]=colorb[2]=0;
  colorb[1]=1;

  colort[0]=colort[1]=0;
  colort[2]=1;

  colorf1s1[0]=colorf1s1[1]=1;
  colorf1s1[2]=0;

  colorf1s2[1]=colorf1s2[2]=0;
  colorf1s2[0]=1;

  colorf2s1[0]=colorf2s1[1]=1;
  colorf2s1[2]=0;

  colorf2s2[1]=colorf2s2[2]=0;
  colorf1s2[0]=1;
   
  fish1(0.7,0.05,translation,scale,colorb,colort,colorf1s1,colorf1s2,colorf2s1,colorf2s2,1,1,1);  

  translation[1]=translation[2]=0; translation[0]=3*f;
  scale[0]=scale[1]=scale[2]=2;

  colorb[0]=colorb[2]=1;
  colorb[1]=0;
  fish1(0.7,0.25,translation,scale,colorb,colort,colorf1s1,colorf1s2,colorf2s1,colorf2s2,1,1,1);
  fish1(0.7,-0.25,translation,scale,colorb,colort,colorf1s1,colorf1s2,colorf2s1,colorf2s2,-1,1,1);

  glutPostRedisplay();
  glFlush();
  glutSwapBuffers();

}
//Menu Function
void menu(int val)
{
  switch (val)
  {
    case 1:
        a=0,d=0,f=0,h=0,i=0,k=0,l=0,m=0,n=0,p=0,q=0,x=0,y=0,sandf=0;;
        glutDisplayFunc(disp1);
        break;
    case 2:
        a=0,d=0,f=0,h=0,i=0,k=0,l=0,m=0,n=0,p=0,q=0,x=0,y=0,sandf=0;
        glutDisplayFunc(disp2);
        break;
    case 3:
        a=0,d=0,f=0,h=0,i=0,k=0,l=0,m=0,n=0,p=0,q=0,x=0,y=0,sandf=0;
        glutDisplayFunc(disp3);
        break;
    case 4: 
        exit(0);
        break;
  }
}
//Display Function for First Frame
void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glColor3f(1.0,0.0,0.0);

  if(sandf>=-0.2)
    sandf=sandf-0.0005;
  else
    sandf=0;

  plant();
  sand();

  glutPostRedisplay();
  glFlush();
  glutSwapBuffers();
}

void create_menu(void)
{
  glutCreateMenu(menu);
  glutAddMenuEntry("Food Animation", 1);
  glutAddMenuEntry("Play Animation", 2);
  glutAddMenuEntry("Poison Food Animation", 3);
  glutAddMenuEntry("Exit Animation", 4);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc,char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

  glutInitWindowPosition(0,0);
  glutInitWindowSize(800,800);
  glutCreateWindow("CED18I049-ICG PROJECT");

  myinit();
  create_menu();
  glutIdleFunc(idle);

  glutDisplayFunc(display);

  glutMainLoop();
}
