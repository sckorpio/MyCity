#include <GL/glut.h>
#include <iostream>
#include <math.h>

using namespace std;

//-----------------------------------------VIEWING VARIABLES------------------------------
GLfloat d=10;

GLfloat X=0;
GLfloat Y=0;
GLfloat Z=-800;

GLfloat A=0;
GLfloat B=0;

GLfloat p=0;
GLfloat q=0;
GLfloat r=1;

GLfloat dw=0.5;

GLfloat R=100;

GLfloat X2=0;
GLfloat Y2=0;
GLfloat Z2=1000;

GLfloat FXmin;
GLfloat FXmax;
GLfloat FYmin;
GLfloat FYmax;

GLfloat angle=0;

GLfloat angley=0;

GLfloat C1[3];
GLfloat C2[3];

GLfloat WC[3];

GLfloat W;
GLfloat dW;


int M=-1;
int ax=-1;
int N=-1;


//--------------------------------utility functions-------------------------------------

void RECT(float l,float b)
{
  glBegin(GL_POLYGON);
  glVertex3f(-b,0,l);
  glVertex3f(b,0,l);
  glVertex3f(b,0,-l);
  glVertex3f(-b,0,-l);
  glEnd();
}

void Cuboid(float b,float l,float h)
{
   glColor3fv(C1);

   glBegin(GL_POLYGON);            //bottom
   glVertex3f(l/2,0,b/2);
   glVertex3f(l/2,0,-b/2);
   glVertex3f(-l/2,0,-b/2);
   glVertex3f(-l/2,0,+b/2);
   glEnd();


   glBegin(GL_POLYGON);                 //front
   glVertex3f(l/2,h,-b/2);
   glVertex3f(l/2,0,-b/2);
   glVertex3f(-l/2,0,-b/2);
   glVertex3f(-l/2,h,-b/2);
   glEnd();

   
   glBegin(GL_POLYGON);                  //left
  glVertex3f(-l/2,h,-b/2);
   glVertex3f(-l/2,h,b/2);
   glVertex3f(-l/2,0,b/2);
   glVertex3f(-l/2,0,-b/2);
   glEnd();

   
   glBegin(GL_POLYGON);                //back
   glVertex3f(-l/2,h,b/2);
   glVertex3f(l/2,h,b/2);
   glVertex3f(l/2,0,b/2);
   glVertex3f(-l/2,0,b/2);
   glEnd();

   
   glBegin(GL_POLYGON);             //right
   glVertex3f(l/2,h,b/2);
   glVertex3f(l/2,0,b/2);
   glVertex3f(l/2,0,-b/2);
   glVertex3f(l/2,h,-b/2);
   glEnd();

   glColor3fv(C2);
   glBegin(GL_POLYGON);         //top
   glVertex3f(l/2,h,b/2);
   glVertex3f(l/2,h,-b/2);
   glVertex3f(-l/2,h,-b/2);
   glVertex3f(-l/2,h,b/2);
   glEnd();

  

}



//--------------------------------BUILDING FUNCTIONS-----------------------------------------------

void WinXZf(float l,float b,float h)
{
    float i,j;

   for(i=h-2;i>0;i=i-dW)
    {
        for(j=-l/2+2;j<(l/2);j=j+dW)
        {
          
          glColor3fv(WC);
      glBegin(GL_POLYGON);
      glVertex3f(j-W,i+W,-b/2-0.3);
      glVertex3f(j+W,i+W,-b/2-0.3);
      glVertex3f(j+W,i-W,-b/2-0.3);
       glVertex3f(j-W,i-W,-b/2-0.3);
       glEnd();

  

           //cout<<j<<" "<<i<<" "<<endl;
        }
    }

}


void WinXZb(float l,float b,float h)
{
    float i,j;

   for(i=h-2;i>0;i=i-dW)
    {
        for(j=-l/2+2;j<(l/2);j=j+dW)
        {
          
          glColor3fv(WC);
      glBegin(GL_POLYGON);
      glVertex3f(j-W,i+W,b/2+0.3);
      glVertex3f(j+W,i+W,b/2+0.3);
      glVertex3f(j+W,i-W,b/2+0.3);
       glVertex3f(j-W,i-W,b/2+0.3);
       glEnd();
       
       

           //cout<<j<<" "<<i<<" "<<endl;
        }
    }

}


void WinYZl(float l,float b,float h)
{
    float i,j;

   for(i=h-2;i>0;i=i-dW)
    {
        for(j=-b/2+2;j<(b/2);j=j+dW)
        {
          
          glColor3fv(WC);
      glBegin(GL_POLYGON);
      glVertex3f(-l/2-0.3,i+W,j-W);
      glVertex3f(-l/2-0.3,i+W,j+W);
      glVertex3f(-l/2-0.3,i-W,j+W);
       glVertex3f(-l/2-0.3,i-W,j-W);
       glEnd();

      
        }
    }

}


void WinYZr(float l,float b,float h)
{
    float i,j;

   for(i=h-2;i>0;i=i-dW)
    {
        for(j=-b/2+2;j<(b/2);j=j+dW)
        {
          
          glColor3fv(WC);
      glBegin(GL_POLYGON);
      glVertex3f(l/2+0.3,i+W,j-W);
      glVertex3f(l/2+0.3,i+W,j+W);
      glVertex3f(l/2+0.3,i-W,j+W);
       glVertex3f(l/2+0.3,i-W,j-W);
       glEnd();

       
        }
    }

}



void SetC1(float x,float y,float z)
{
   C1[0]=x;
   C1[1]=y;
   C1[2]=z;
}

void SetC2(float x,float y,float z)
{
   C2[0]=x;
   C2[1]=y;
   C2[2]=z;
}

void SetWin(float x,float y,float z,float p,float q)
{
   WC[0]=x;
   WC[1]=y;
   WC[2]=z;

   W=p;  dW=q;
}




void Building(float l,float b,float h)
{
  
   glColor3f(1,0,0);
   glBegin(GL_POLYGON);            //bottom
   glVertex3f(l/2,0,b/2);
   glVertex3f(l/2,0,-b/2);
   glVertex3f(-l/2,0,-b/2);
   glVertex3f(-l/2,0,+b/2);
   glEnd();


   glColor3fv(C1);
   glBegin(GL_POLYGON);                 //front
   glVertex3f(l/2,h,-b/2);
   glVertex3f(l/2,0,-b/2);
   glVertex3f(-l/2,0,-b/2);
   glVertex3f(-l/2,h,-b/2);
   glEnd();

   
   WinXZf(l,b,h);


   glColor3fv(C2);
   glBegin(GL_POLYGON);                  //left
  glVertex3f(-l/2,h,-b/2);
   glVertex3f(-l/2,h,b/2);
   glVertex3f(-l/2,0,b/2);
   glVertex3f(-l/2,0,-b/2);
   glEnd();

   WinYZl(l,b,h);

   glColor3fv(C1);
   glBegin(GL_POLYGON);                //back
   glVertex3f(-l/2,h,b/2);
   glVertex3f(l/2,h,b/2);
   glVertex3f(l/2,0,b/2);
   glVertex3f(-l/2,0,b/2);
   glEnd();

   WinXZb(l,b,h);

   glColor3fv(C2);
   glBegin(GL_POLYGON);             //right
   glVertex3f(l/2,h,b/2);
   glVertex3f(l/2,0,b/2);
   glVertex3f(l/2,0,-b/2);
   glVertex3f(l/2,h,-b/2);
   glEnd();

   WinYZr(l,b,h);

   glColor3f(0,0,1);
   glBegin(GL_POLYGON);         //top
   glVertex3f(l/2,h,b/2);
   glVertex3f(l/2,h,-b/2);
   glVertex3f(-l/2,h,-b/2);
   glVertex3f(-l/2,h,b/2);
   glEnd();

  

}



//-----------------------------BUILDING TYPES SKYSCRAPERS---------------------------------



void twistsearsTower(float l,float b,int blocks,float h,float d,float dangle)
{

  int i=1;

  
  float th;

  th=0;  float ax=0;

  for(i=0;i<blocks;i++)
  {   
    glPushMatrix();
    glTranslatef(0,th,0);
    glRotatef(ax,0,1,0);
      Building(l,b,h);
      //cout<<l<<" "<<b<<" "<<BH[i]<<endl;
      glPopMatrix();
      th=th+h;
      l=l-d;  b=b-d;

      ax=ax+dangle;
  }
}

void searsTower(float l,float b,int blocks,float BH[20],float d)
{

  int i=1;

  
  float th;

  th=0;  
  for(i=0;i<blocks;i++)
  {   
    glPushMatrix();
    glTranslatef(0,th,0);
    //glRotatef(ax,0,1,0);
      Building(l,b,BH[i]);
      cout<<l<<" "<<b<<" "<<BH[i]<<endl;
      glPopMatrix();
      th=th+BH[i];
      l=l-d;  b=b-d;

  }
}


void petronas()
{  
   float arr[20]={40,30,28,26,25,24,23,20,19,18,17,15,14,11,10,12,16,18,20,21};

   glPushMatrix();
   glTranslatef(-50,0,0);
   glRotatef(45,0,1,0);
    searsTower(40,40,20,arr,2);
    glPopMatrix();

    glPushMatrix();
   glTranslatef(50,0,0);
   glRotatef(45,0,1,0);
    searsTower(40,40,20,arr,2);
    glPopMatrix();

    glPushMatrix();
   glTranslatef(0,120,0);
    Building(105,8,8);
    glPopMatrix();




}


//--------------------------ROAD--------------------------------------------------




void makeRoadSlab()
{
    float L=20;
    float B=20;
    float b=0.5;
    float l=4;
    float fh=0.7;

    glColor3f(0,0,0);             //Concrete
    RECT(L,B+6);

    glPushMatrix();
    glTranslatef(0,0.5,0);
    glColor3f(1,1,0);          //Middle Yellow Strip
    RECT(L,b);
    glPopMatrix();

    glColor3f(1,1,1);       //WhiteStrips

    glPushMatrix();
    glTranslatef(-B/2,0.5,0);
    RECT(l,b);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(B/2,0.5,0);
    RECT(l,b);
    glPopMatrix();

    SetC2(0.871,0.722,0.529);
     SetC1(0.804,0.522,0.247);     //Footpath1
   
    glPushMatrix();
    glTranslatef(-(5*B/4),0,L/2);
   Cuboid(L,B/3,fh);
    glPopMatrix();

    glPushMatrix();
    glTranslatef((5*B/4),0,L/2);
    Cuboid(L,B/3,fh);
    glPopMatrix();
    
    SetC2(0.957,0.643,0.376); 
    SetC1(0.804,0.522,0.247);         //Footpath2

    glPushMatrix();
    glTranslatef(-(5*B/4),0,-L/2);
    Cuboid(L,B/3,fh);
    glPopMatrix();

    glPushMatrix();
    glTranslatef((5*B/4),0,-L/2);
    Cuboid(L,B/3,fh);
    glPopMatrix();

   







}



void RoadXc(float Xc,float Z1,float Z2)
{
   float i;

   for(i=Z1;i<=Z2;i=i+40)
   {
       glPushMatrix();
       glTranslatef(Xc,0.5,i);
       makeRoadSlab();
       glPopMatrix();
   }
}


void RoadZc(float Zc,float X1,float X2)
{
   float i;

   for(i=X1;i<=X2;i=i+40)
   {
       glPushMatrix();
       glTranslatef(i,0.5,Zc);
       glRotatef(90,0,1,0);
       makeRoadSlab();
       glPopMatrix();
   }
}


void FixJunction(float a,float b)
{
    SetC1(0,0,0);
   SetC2(0,0,0);
   glPushMatrix();
   glTranslatef(a,1,b);
   glRotatef(45,0,1,0);
   Cuboid(70,70,1);
   glPopMatrix();
   
}



//---------------------------EVENT CONTROL----------------------------------------

void keyboard(unsigned char key,int x,int y)
{
    switch(key)
   {
     
      case 'A': angle=angle+1; break;

      case 'D': angle=angle-1; break;

      case 'W': angley=angley+1; break;

      case 'S': angley=angley-1; break;

      case 'T': Y=Y+15; break;

      case 'G': Y=Y-15; break;

      case 'N': N=-N;  break;

      case 32: M=-M;  break;

      case 9  : ax=-ax;
   }

   //cout<<"A="<<A<<" "<<"B="<<B<<endl;


   
  // updateUnitVector();
  // updateView();
   glutPostRedisplay();
}

void special(int key,int x,int y)
{
   

   switch(key)
   {
      case GLUT_KEY_LEFT:  ;  { X=X-20; } break;

      case GLUT_KEY_RIGHT:  { X=X+20; };   break;

      case  GLUT_KEY_DOWN:  { Z=Z-20; }  break;

      case GLUT_KEY_UP:  { Z=Z+20; }   break;
      
   }

    //cout<<X<<" "<<Y<<" "<<Z<<endl;

   //updateView();
   glutPostRedisplay();
}


void Axes()
{   
    glLineWidth(10);
     
    glColor3f(1,0,0);

    glBegin(GL_LINES);      //Z
    glVertex3f(0,1,5000);
    glVertex3f(0,1,-5000);
    glEnd();



     glColor3f(1,0,1);

    glBegin(GL_LINES);     //Y
    glVertex3f(0,5000,0);
    glVertex3f(0,-5000,0);
    glEnd();

     glColor3f(0,0,1);

    glBegin(GL_LINES);        //X
    glVertex3f(5000,1,0);
    glVertex3f(-5000,1,0);
    glEnd();

    glLineWidth(2.5);


    for(int i=-5000;i<=5000;i+=100)
    {
       glColor3f(1,0,0);
     glBegin(GL_LINES);      //Z
    glVertex3f(i,1,5000);
    glVertex3f(i,1,-5000);
    glEnd();

    }

    for(int i=-5000;i<=5000;i+=100)
    {
      glColor3f(0,0,1);
     glBegin(GL_LINES);        //X
    glVertex3f(5000,1,i);
    glVertex3f(-5000,1,i);
    glEnd();

    }

    
}


void ALLROADS()
{
    RoadZc(200,-200,200);     // R1
    RoadZc(-200,-200,200);    //R2
    RoadXc(200,-200,200);     //R3
    RoadXc(-200,-200,200);    //R4

    RoadXc(0,200,600);         //R5
    RoadXc(0,-600,-200);       //R6
    RoadXc(0,-200,0);         //R7

    RoadZc(0,200,800);   //R8

    RoadZc(-600,-600,800);  //R9

    RoadXc(800,-600,600);  //R10
   
    RoadZc(600,-600,800);   //R11

    RoadXc(-600,-600,600);   //R12

    RoadXc(400,-600,600);  //R13

    RoadXc(-300,-600,600);  //R13

    FixJunction(0,-200);



}


void PALACE()
{
     SetC1(0.914,0.588,0.478);               //PALCE
  SetC2(1.0,0.627,0.478);
  SetWin(0.698,0.133,0.133,5,15);
   
   
   glPushMatrix();
   glTranslatef(0,0,0);
   Building(200,200,70);

   glPopMatrix();

 



   glPushMatrix();
   glTranslatef(100,0,100);
   Building(50,50,100);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(100,0,-100);
   Building(50,50,100);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-100,0,100);
   Building(50,50,100);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-100,0,-100);
   Building(50,50,100);
   glPopMatrix();

  
//----------------------------------

   SetWin(0.698,0.133,0.133,3,8);

    glPushMatrix();
   glTranslatef(0,70,0);
   twistsearsTower(100,100,20,10,5,0);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(100,100,100);
  twistsearsTower(50,50,10,10,5,0);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(100,100,-100);
   twistsearsTower(50,50,10,10,5,0);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-100,100,100);
   twistsearsTower(50,50,10,10,5,0);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-100,100,-100);
   twistsearsTower(50,50,10,10,5,0);
  glPopMatrix();

  //------------------------------------------------------
    
     glPushMatrix();
   glTranslatef(0,25,-102);
   glRotatef(90,1,0,0);
   SetC1(0.698,0.133,0.133);
   SetC2(0.698,0.133,0.133);
   Cuboid(50,50,4);
   glPopMatrix();

}

void palacecones()
{
   SetWin(0.698,0.133,0.133,1,3);
    SetC1(0.914,0.588,0.478);               //PALCE CONES
  SetC2(1.0,0.627,0.478);
  
    glPushMatrix();
   glTranslatef(-60,0,-250);
  twistsearsTower(25,25,10,5,2.5,0);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(60,0,-250);
  twistsearsTower(25,25,10,5,2.5,0);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-60,0,-350);
  twistsearsTower(25,25,10,5,2.5,0);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(60,0,-350);
   twistsearsTower(25,25,10,5,2.5,0);
   glPopMatrix();

    glPushMatrix();
   glTranslatef(-60,0,-450);
  twistsearsTower(25,25,10,5,2.5,0);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(60,0,-450);
   twistsearsTower(25,25,10,5,2.5,0);
   glPopMatrix();



   
  
}

void display(void)
 {
 if(N==-1)
 glClearColor(1,1,1,0);
else
  glClearColor(0,0,0,0);

   glClearDepth(1);
   glClear(GL_COLOR_BUFFER_BIT);
   glClear(GL_DEPTH_BUFFER_BIT);

   glEnable(GL_DEPTH_TEST);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();

  gluPerspective(45,16/9,1,10000);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();



  
  gluLookAt(X,Y,Z,X2,Y2,Z2,0,1,0);

 

  glColor3f(1.0,1.0,1.0);

  glRotatef(angle,0,1,0);
  glRotatef(angley,1,0,0);
  
//-------------------------------------------
    //TEMPORARY AXES
     if(ax==1)
     Axes();
//-------------------------------------------

   

   glColor3f(0,1,0);    //GROUND
   glBegin(GL_POLYGON);
   glVertex3f(-1000,0,-1000);
   glVertex3f(-1000,0,1000);
   glVertex3f(1000,0,1000);
   glVertex3f(1000,0,-1000);
   glEnd();

   glColor3f(0.957,0.643,0.376);    //BEACH
   glBegin(GL_POLYGON);
   glVertex3f(-1000,0,-1000);
   glVertex3f(1000,0,-1000);
   glVertex3f(1300,-25,-1300);
   glVertex3f(-1300,-25,-1300);
   glEnd();

   glBegin(GL_POLYGON);
   glVertex3f(1000,0,1000);
   glVertex3f(1000,0,-1000);
   glVertex3f(1300,-25,-1300);
   glVertex3f(1300,-25,1300);
   glEnd();


  glBegin(GL_POLYGON);
   glVertex3f(-1000,0,1000);
   glVertex3f(1000,0,1000);
   glVertex3f(1300,-25,1300);
   glVertex3f(-1300,-25,1300);
   glEnd();


   glBegin(GL_POLYGON);
   glVertex3f(-1000,0,1000);
   glVertex3f(-1000,0,-1000);
   glVertex3f(-1300,-25,-1300);
   glVertex3f(-1300,-25,1300);
   glEnd();


   




   glColor3f(0.529,0.808,0.922);    //WATER
   glBegin(GL_POLYGON);
   glVertex3f(-5000,-50,-5000);
   glVertex3f(-5000,-50,5000);
   glVertex3f(5000,-50,5000);
   glVertex3f(5000,-50,-5000);
   glEnd();

   //-----------------------------------------------------------------------------

 glPushMatrix();
 glScalef(1,2,1);

   glPushMatrix();
   glScalef(0.5,0.5,0.5);
   PALACE();
   glPopMatrix();

   palacecones();

   ALLROADS();

   //---------------------------------------------

   SetC1(0.69,0.769,0.871);               //CADET BLUE
  SetC2(0.373,0.620,0.627);
  SetWin(0.118,0.565,1.0,1,4);
   glPushMatrix();
  glTranslatef(500,0,-500);
   twistsearsTower(70,70,20,20,3.5,8);          //TWISTED
   glPopMatrix();


   //-------------------------------------------------------


SetC1(0.69,0.769,0.871);               //CADET BLUE         PETRONAS
  SetC2(0.373,0.620,0.627);
  SetWin(0,0,1,0.8,4);
   glPushMatrix();
  glTranslatef(-300,0,-300);
   petronas();
   glPopMatrix();

   
   //-----------------------------------------------------------


  SetC1(0.741,0.718,0.420);               //OLIVE -B1               
  SetC2(0.502,0.502,0.000);                 
  SetWin(0.373,0.620,0.627,1.5,5);
  float arr[10]={30,30,28,4};

   glPushMatrix();
  glTranslatef(-140,0,460);
   searsTower(200,200,4,arr,4);
   glPopMatrix();


   //----------------------------------------------------------------

    SetC1(0.545,0.271,0.075);               //GOLD -B2            
  SetC2(0.627,0.322,0.176);                 
  SetWin(0.855,0.647,0.125,2,6);
    

    float arr2[10]={50,40,30,20};

    glPushMatrix();
  glTranslatef(300,0,-100);
   searsTower(100,100,4,arr2,4);
   glPopMatrix();


   //------------------------------------------------------------------

   SetC1(0.69,0.769,0.871);               //STEEL BLUE  B3
  SetC2(0.678,0.847,0.902);
  SetWin(0,0,0,2,10); 
  glPushMatrix();
  glTranslatef(300,0,200);
   Building(100,200,60);
   glPopMatrix();

   //--------------------------------------------------------------

 

    SetC1(0.69,0.769,0.871);               //CADET BLUE
  SetC2(0.373,0.620,0.627);
  SetWin(0,0,1,0.8,4);
  float arr3[10]={50,50,40,30,20};

   glPushMatrix();
  glTranslatef(500,0,100);
   searsTower(120,120,5,arr3,10);
   glPopMatrix();

//----------------------------------------------------------------------------

    SetC1(0.69,0.769,0.871);               //CADET BLUE   BIG LEFT
  SetC2(0.373,0.620,0.627);
  SetWin(0.529,0.808,0.922,3,9);
   glPushMatrix();
  glTranslatef(900,0,-200);
  glRotatef(90,0,1,0);
   Building(300,100,100);
   glPopMatrix();

   //----------------------------------------------------------------------------

    SetC1(0.741,0.718,0.420);               //OLIVE -BIG LEFT UP              
  SetC2(0.502,0.502,0.000);                 
  SetWin(0.373,0.620,0.627,4,12);
   glPushMatrix();
  glTranslatef(900,0,200);
  glRotatef(90,0,1,0);
   Building(300,100,200);
   glPopMatrix();


   //---------------------------------------------------------------------------



     SetC1(0.275,0.510,0.706);               //CADET+STEEL-   TWIN
  SetC2(0.373,0.620,0.627);
    SetWin(0,0,1,0.8,4);
   glPushMatrix();
   glTranslatef(-470,0,-525);
  //glRotatef(90,0,1,0);
   Building(50,50,250);
   glPopMatrix();


//-------------------------------------------------------------------------------


    SetC1(0.275,0.510,0.706);               //CADET+STEEL-  TWIN
  SetC2(0.373,0.620,0.627);
  SetWin(0,0,1,0.8,4);
   glPushMatrix();
  glTranslatef(-540,0,-500);
  glRotatef(90,0,1,0);
   Building(50,50,250);
   glPopMatrix();

//-------------------------------------------------------------------------




    SetC1(0.741,0.718,0.420);               //OLIVE -B1               
  SetC2(0.502,0.502,0.000);                 
  SetWin(0.373,0.620,0.627,1.5,5);
   glPushMatrix();
  glTranslatef(550,0,-150);
  //glRotatef(90,0,1,0);
   Building(100,50,100);
   glPopMatrix();


//--------------------------------------------------------------------------


   SetC1(0.275,0.510,0.706);               //CADET+STEEL-B7       45 WALI
  SetC2(0.373,0.620,0.627);
  SetWin(0.0,0.808,0.820,3,8);
   glPushMatrix();
  glTranslatef(730,0,500);
  glRotatef(45,0,1,0);
   Building(50,50,250);
   glPopMatrix();

   //----------------------------------------------------------------------

   SetC1(0.275,0.510,0.706);               //CADET+STEEL-B4
  SetC2(0.373,0.620,0.627);
  SetWin(0.0,0.808,0.820,3,8);

  float arr4[10]={80,60,40,20,10};

   glPushMatrix();                                    // INSERTED
  glTranslatef(710,0,-150);
  glRotatef(90,0,1,0);
   searsTower(100,100,5,arr4,5);
   glPopMatrix();

    SetC1(0.275,0.510,0.706);               //CADET+STEEL-B4
  SetC2(0.373,0.620,0.627);
  SetWin(0.0,0.808,0.820,3,8);
   glPushMatrix();
  glTranslatef(710,0,-150);
  glRotatef(90,0,1,0);
   Building(100,50,250);
   glPopMatrix();


//------------------------------------------------------------------
   


   SetC1(0.275,0.510,0.706);               //CADET+STEEL-B7       45 WALI
  SetC2(0.373,0.620,0.627);
  SetWin(0.0,0.808,0.820,3,8);
   glPushMatrix();
  glTranslatef(150,0,500);
  glRotatef(45,0,1,0);
   Building(50,50,250);
   glPopMatrix();
//-------------------------------------------------------------------------
  
  SetC1(0.741,0.718,0.420);               //OLIVE -BIG LEFT UP              
  SetC2(0.502,0.502,0.000);                 
  SetWin(0.373,0.620,0.627,4,12);
   glPushMatrix();
  glTranslatef(-450,0,500);
  //glRotatef(90,0,1,0);
   Building(200,100,200);
   glPopMatrix();


glPopMatrix();

  glutSwapBuffers();
  glFlush();
 
}

void FUN()
{
    if(M==1)
      angle=angle+1;

    glutPostRedisplay();
}

int main(int argc, char **argv) 
{
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);  
  glutInitWindowPosition(200,200);
  glutInitWindowSize(1366,768);
  glutCreateWindow("Test");
  glutDisplayFunc(display);
  glutSpecialFunc(special);
  glutKeyboardFunc(keyboard);
  glutIdleFunc(FUN);
  glutMainLoop();

  return 0;
}
