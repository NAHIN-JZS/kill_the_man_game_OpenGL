#include <bits/stdc++.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include "BmpLoader.h"
#include<iostream>
#include<Windows.h>
#include<MMSystem.h>

#define PI 3.1416

using namespace std;

double Txval=0,Tyval=0,Tzval=0;
double windowHeight=1000, windowWidth=1000;
//GLfloat alpha = 0.0, theta = 0.0, axis_x=0.0, axis_y=0.0, lpan = 0.0, rpan = 0.0, fdist=0.0,yaw = 0.0, dx = 0.0,dy = 0.0,dz = 0.0,roll=0.0,pitch = 0.0,cdist = 0.0,xaxis = 0.0, yaxis=1.0,zaxis=0.0;
GLfloat alpha = 0.0, theta = 0.0,bita = 0.0, axis_x=0.0, axis_y=0.0;

GLfloat up_x = 0,up_y = 1,up_z = 0,dx,dy,dz;
int theta_x=0, theta_y=0, theta_z=0;

GLboolean bRotate = false, uRotate = false;

GLfloat theta_pakha =0;
//
double wall_length = 20.0,wall_width = 0.5, wall_height = 10.0;
double Loop, LoopAll = 0;
GLfloat eyeX =wall_length/2;// 2;
GLfloat eyeY =wall_height/2;// 3;
GLfloat eyeZ = 1.5 * wall_length;

GLfloat nearP = 4, farP = 250;

GLfloat lookX = wall_length / 2;
GLfloat lookY = wall_height/2;
GLfloat lookZ = wall_length/2;


GLfloat x_look = lookX;
GLfloat y_look = lookY;
GLfloat z_look = lookZ;
bool l_on1 = true;
bool l_on2 = true;
bool l_on3 = true;
bool ambflag=true;
bool difflag=true;
bool specflag=true;
bool game_over = false;
bool win = false;
bool loose = false;
bool day = false;
bool makeSound = true;
bool bomb_sound = false;

bool ambient0 = true, diffuse0 = true, specular0 = true;
bool ambient1 = true, diffuse1 = true, specular1 = true;

float length = 1.0;

double const pi = acos(-1), d=0.05;
double const sn = sin(pi/180), cs=cos(pi/180);
GLfloat sx, cx;

float redish[] = {0.5020, 0.0000, 0.0000};
float deep_ash[] = {0.4392, 0.5020, 0.5647};
float blue[] = {0.0,0.0,1.0};
float white[] = {1.0,1.0,1.0};
float ash[] = {0.6627, 0.6627, 0.6627};
float green[] = {0.0,1.0,0.0};
float red[] = {1.0,0.0000, 0.0000};
float brown[] = {0.5451, 0.2706, 0.0745};
float black[] = {0.0, 0.0, 0.0};

bool car_running = true;
float car_x =-30.0f ,car_y=2.5,car_z=5.5;

vector<int> v;
unsigned int ID;


    static GLfloat v_cube[8][3] =
{
    {0.0, 0.0, 0.0}, //0
    {0.0, 0.0, length}, //1
    {length, 0.0, 1.0}, //2
    {length, 0.0, 0.0}, //3
    {0.0, length, 0.0}, //4
    {0.0, length, length}, //5
    {length, length, length}, //6
    {length, length, 0.0}  //7
};

    static GLubyte quadIndices[6][4] =
    {
        {0, 1, 2, 3}, //bottom
        {4, 5, 6, 7}, //top
        {5, 1, 2, 6}, //front
        {0, 4, 7, 3}, // back is clockwise
        {2, 3, 7, 6}, //right
        {1, 5, 4, 0}  //left is clockwise
    };



void LoadTexture(const char*filename)
{
    /*glBindTexture(GL_TEXTURE_2D, TextureColorbufferName);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, 0);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 1000);
 glBindTexture(GL_TEXTURE_2D, 0);*/



    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);
    glPixelStorei(GL_UNPACK_ALIGNMENT, ID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    BmpLoader bl(filename);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, bl.iWidth, bl.iHeight, GL_RGB, GL_UNSIGNED_BYTE, bl.textureData );
}
void texture_image()
{
    LoadTexture("F:\\4.2\\kill_the_man_game_OpenGL\\treeside.bmp"); //0
    v.push_back(ID);
    LoadTexture("F:\\4.2\\kill_the_man_game_OpenGL\\grass.bmp"); //0
    v.push_back(ID);
    LoadTexture("F:\\4.2\\kill_the_man_game_OpenGL\\soil_grass3.bmp");
    v.push_back(ID);

    LoadTexture("F:\\4.2\\kill_the_man_game_OpenGL\\road.bmp");
    v.push_back(ID);

    LoadTexture("F:\\4.2\\kill_the_man_game_OpenGL\\backglas.bmp");
    v.push_back(ID);

    LoadTexture("F:\\4.2\\kill_the_man_game_OpenGL\\tire.bmp");
    v.push_back(ID);

    LoadTexture("F:\\4.2\\kill_the_man_game_OpenGL\\car_body.bmp");
    v.push_back(ID);

    LoadTexture("F:\\4.2\\kill_the_man_game_OpenGL\\redlight.bmp");
    v.push_back(ID);

    LoadTexture("F:\\4.2\\kill_the_man_game_OpenGL\\number_plate.bmp");
    v.push_back(ID);

    LoadTexture("F:\\4.2\\kill_the_man_game_OpenGL\\head_light.bmp");
    v.push_back(ID);

    LoadTexture("F:\\4.2\\kill_the_man_game_OpenGL\\head_light_on.bmp");
    v.push_back(ID);

    LoadTexture("F:\\4.2\\kill_the_man_game_OpenGL\\fire.bmp");
    v.push_back(ID);

    LoadTexture("F:\\4.2\\kill_the_man_game_OpenGL\\car_fire.bmp");
    v.push_back(ID);

    LoadTexture("F:\\4.2\\kill_the_man_game_OpenGL\\soil.bmp");
    v.push_back(ID);

    LoadTexture("F:\\4.2\\kill_the_man_game_OpenGL\\moon.bmp");
    v.push_back(ID);

}


void bombBlustSound()
        {
            PlaySound(NULL, 0, 0);
            PlaySound(TEXT("F://4.2//kill_the_man_game_OpenGL//bomb.wav"), NULL, SND_ASYNC | SND_FILENAME);
            std::this_thread::sleep_for(std::chrono::milliseconds(3000));
            PlaySound(NULL, 0, 0);
        }
void carSound()
{
    PlaySound(NULL, 0, 0);
    if(makeSound) PlaySound(TEXT("F://4.2//kill_the_man_game_OpenGL//car_passing.wav"), NULL, SND_ASYNC | SND_FILENAME);
    else PlaySound(NULL,0,0);
}

void looseSound()
{
    PlaySound(NULL, 0, 0);
    PlaySound(TEXT("F://4.2//kill_the_man_game_OpenGL//loose.wav"), NULL, SND_ASYNC | SND_FILENAME);
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    PlaySound(NULL, 0, 0);
}

void winSound()
{
    PlaySound(NULL, 0, 0);
    PlaySound(TEXT("F://4.2//kill_the_man_game_OpenGL//win.wav"), NULL, SND_ASYNC | SND_FILENAME);
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    PlaySound(NULL, 0, 0);
}


void light0(float x,float y,float z)
{
    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[]  = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_diffuse[]  = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { x, y, z, 1.0 };

    glEnable( GL_LIGHT0);
    if (ambient0)
    {
        glLightfv( GL_LIGHT0, GL_AMBIENT, light_ambient);
    }
    else
    {
        glLightfv( GL_LIGHT0, GL_AMBIENT, no_light);
    }
    if (diffuse0)
    {

        glLightfv( GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    }
    else
    {

        glLightfv( GL_LIGHT0, GL_DIFFUSE, no_light);
    }
    if(specular0)
    {

        glLightfv( GL_LIGHT0, GL_SPECULAR, light_specular);
    }
    else
    {

        glLightfv( GL_LIGHT0, GL_SPECULAR, no_light);
    }
    glLightfv( GL_LIGHT0, GL_POSITION, light_position);

    /*  GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };
      glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
      glLightf( GL_LIGHT0, GL_SPOT_CUTOFF, 10.0); */
}

void light1()
{
    glPushMatrix();
    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[]  = {0.5, 0.5, 0.5, 1.0};
    GLfloat light_diffuse[]  = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { 200, 9.5, -15 };  //0.7, 1.5, 9.0

    glEnable( GL_LIGHT1);

    if(ambient1)
    {
        glLightfv( GL_LIGHT1, GL_AMBIENT, light_ambient);
    }
    else
    {
        glLightfv( GL_LIGHT1, GL_AMBIENT, no_light);
    }

    if(diffuse1)
    {
        glLightfv( GL_LIGHT1, GL_DIFFUSE, light_diffuse);
    }
    else
    {
        glLightfv( GL_LIGHT1, GL_DIFFUSE, no_light);
    }

    if(specular1)
    {
        glLightfv( GL_LIGHT1, GL_SPECULAR, light_specular);
    }
    else
    {
        glLightfv( GL_LIGHT1, GL_SPECULAR, no_light);
    }

    glLightfv( GL_LIGHT1, GL_POSITION, light_position);
//    GLfloat spot_direction[] = { 0.3, -1, -0.8 };
    GLfloat spot_direction[] = { -1.0, -1.0, 0.0 };
//    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
//    glLightf( GL_LIGHT1, GL_SPOT_CUTOFF, 10.0);

    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 0.0);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
//    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);

    glPopMatrix();

    /*GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
    glLightf( GL_LIGHT1, GL_SPOT_CUTOFF, 10.0);*/
}

static void getNormal3p
(GLfloat x1, GLfloat y1,GLfloat z1, GLfloat x2, GLfloat y2,GLfloat z2, GLfloat x3, GLfloat y3,GLfloat z3)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2-x1;
    Uy = y2-y1;
    Uz = z2-z1;

    Vx = x3-x1;
    Vy = y3-y1;
    Vz = z3-z1;

    Nx = Uy*Vz - Uz*Vy;
    Ny = Uz*Vx - Ux*Vz;
    Nz = Ux*Vy - Uy*Vx;

    glNormal3f(Nx,Ny,Nz);
}

void drawcube(float am_r, float am_g, float am_b, float df_r,float df_g,float df_b,float sp_r=1.0,float sp_g=1.0,float sp_b=1.0,float shininess = 60)
{
//    glColor3f(1,0,0);
    //glBegin(GL_TRIANGLES);

    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
//    GLfloat mat_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { am_r, am_g, am_b, 1.0 };

//    GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_diffuse[] = { df_r, df_g, df_b, 1.0 };
//    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_specular[] = { sp_r, sp_g, sp_b, 1.0 };
//    GLfloat mat_shininess[] = {60};
    GLfloat mat_shininess[] = {shininess};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);

    glBegin(GL_QUADS);
    for (GLint i = 0; i <6; i++)
    {
        getNormal3p(v_cube[quadIndices[i][0]][0], v_cube[quadIndices[i][0]][1], v_cube[quadIndices[i][0]][2],
                    v_cube[quadIndices[i][1]][0], v_cube[quadIndices[i][1]][1], v_cube[quadIndices[i][1]][2],
                    v_cube[quadIndices[i][2]][0], v_cube[quadIndices[i][2]][1], v_cube[quadIndices[i][2]][2]);
//        glVertex3fv(&v_cube[quadIndices[i][0]][0]);
//        glVertex3fv(&v_cube[quadIndices[i][1]][0]);
//        glVertex3fv(&v_cube[quadIndices[i][2]][0]);
//        glVertex3fv(&v_cube[quadIndices[i][3]][0]);

        glVertex3fv(&v_cube[quadIndices[i][0]][0]);glTexCoord2f(0,1);
        glVertex3fv(&v_cube[quadIndices[i][1]][0]);glTexCoord2f(0,0);
        glVertex3fv(&v_cube[quadIndices[i][2]][0]);glTexCoord2f(1,0);
        glVertex3fv(&v_cube[quadIndices[i][3]][0]);glTexCoord2f(1,1);
    }
    glEnd();


}

void Cylinder3D(double a1,double b1,double c1)
{

    GLfloat mat_ambient[] = { 1, 1, 1, 1.0 };
    GLfloat mat_diffuse[] = { 1, 1, 1, 1.0 };
    GLfloat mat_specular[] = { 1,1,1, 1.0 };
    GLfloat mat_shininess[] = {90};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);




    GLUquadricObj *quadratic;


    quadratic = gluNewQuadric();
    gluQuadricTexture(quadratic, GL_TRUE);
    glRotatef(-90.0f, 1.0f,0.0f, 0.0f);
    gluCylinder(quadratic,a1,b1,c1,32,32);
    //gluQuadricTexture(quadratic, TRUE);
    gluDeleteQuadric(quadratic);

}


void circle_3D(GLdouble radius)
{
    GLfloat mat_ambient[] = { 1, 1, 1, 1.0 };
    GLfloat mat_diffuse[] = { 1, 1, 1, 1.0 };
    GLfloat mat_specular[] = { 1,1,1, 1.0 };
    GLfloat mat_shininess[] = {90};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);




    GLUquadric *qobj = gluNewQuadric();
    gluQuadricTexture(qobj, GL_TRUE);

    glRotatef(270, 1, 0, 0);
    gluSphere(qobj, radius, 20, 20);
    gluDeleteQuadric(qobj);

}

/// fire start
//GLfloat texture[10];

const static int ParticleCount = 1000;

typedef struct
{
double Xpos;
double Ypos;
double Zpos;
double Xmov;
double Zmov;
double Red;
double Green;
double Blue;
double Direction;
double Acceleration;
double Deceleration;
double Scalez;
bool Visible;
}PARTICLES;

PARTICLES Particle[ParticleCount];

//GLuint LoadTextureRAW( const char * filename, int width,
//int height);
//void FreeTexture( GLuint texturez );

void glCreateParticles (void) {
int i;
for (i = 1; i < ParticleCount; i++)
{
Particle[i].Xpos = 0;
Particle[i].Ypos = -5;
Particle[i].Zpos = -5;
Particle[i].Xmov = (((((((2 - 1 + 1) * rand()%11) + 1) - 1 + 1) *
rand()%11) + 1) * 0.005) - (((((((2 - 1 + 1) * rand()%11) + 1) - 1 + 1
) * rand()%11) + 1) * 0.005);
Particle[i].Zmov = (((((((2 - 1 + 1) * rand()%11) + 1) - 1 + 1) *
rand()%11) + 1) * 0.005) - (((((((2 - 1 + 1) * rand()%11) + 1) - 1 + 1
) * rand()%11) + 1) * 0.005);
Particle[i].Red = 1;
Particle[i].Green = 1;
Particle[i].Blue = 1;
Particle[i].Scalez = 0.25;
Particle[i].Direction = 0;
Particle[i].Acceleration = ((((((8 - 5 + 2) * rand()%11) + 5
) - 1 + 1) * rand()%11) + 1) * 0.02;
Particle[i].Deceleration = 0.0025;
}
}

void glUpdateParticles (void) {
int i;
for (i = 1; i < ParticleCount; i++)
{

glColor3f (Particle[i].Red, Particle[i].Green,
Particle[i].Blue);

Particle[i].Ypos = Particle[i].Ypos + Particle[i]
.Acceleration - Particle[i].Deceleration;
Particle[i].Deceleration = Particle[i].Deceleration +
0.0025;

Particle[i].Xpos = Particle[i].Xpos + Particle[i].Xmov;
Particle[i].Zpos = Particle[i].Zpos + Particle[i].Zmov;

Particle[i].Direction = Particle[i].Direction + ((((((int
)(0.5 - 0.1 + 0.1) * rand()%11) + 1) - 1 + 1) * rand()%11) + 1);

if (Particle[i].Ypos < -5)
{
Particle[i].Xpos = 0;
Particle[i].Ypos = -5;
Particle[i].Zpos = -5;
Particle[i].Red = 1;
Particle[i].Green = 1;
Particle[i].Blue = 1;
Particle[i].Direction = 0;
Particle[i].Acceleration = ((((((8 - 5 + 2) * rand()%11) + 5
) - 1 + 1) * rand()%11) + 1) * 0.02;
Particle[i].Deceleration = 0.0025;
}

}
}

void glDrawParticles (void) {
int i;
for (i = 1; i < ParticleCount; i++)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,v[12]);
glPushMatrix();

    glTranslatef (Particle[i].Xpos, Particle[i].Ypos, Particle[i].Zpos);
    glRotatef (Particle[i].Direction - 90, 0, 0, 1);

    glScalef (Particle[i].Scalez, Particle[i].Scalez, Particle[i].Scalez);

    glDisable (GL_DEPTH_TEST);


//    drawcube(1,1,1,1,1,1);
    circle_3D(1);
//    drawcube(1,1,1,1,1,1);

    glEnable(GL_DEPTH_TEST);

glPopMatrix();
glDisable(GL_TEXTURE_2D);

}
}


void fire(float fire_x = 0.0,float fire_y = 0.0,float fire_z = 0.0){

    glEnable(GL_DEPTH_TEST);
    glPushMatrix();
    glTranslatef (fire_x,fire_y,fire_z);
    glUpdateParticles();
    glDrawParticles();
    glPopMatrix();

}



///Fire end





void textDisplay(string str,int x,int y,int z)
{

    GLfloat mat_ambient[] = { 1, 1, 0, 1.0 };
    GLfloat mat_diffuse[] = { 1, 1, 0, 1.0 };
    GLfloat mat_specular[] = { 1,1,1, 1.0 };
    GLfloat mat_shininess[] = {100};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    glEnable(GL_LINE_SMOOTH);
    glLineWidth(3);
    //glColor3b(1,0,0);
    glPushMatrix();
    glTranslatef(x, y,z);
    glScalef(0.03f,0.02f,1);

    for (int i=0; i<str.size(); i++)
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, str[i]);
    }
    glPopMatrix();
}



void tric(double deg)
{
    deg = deg * pi / 180;
    sx=sin(deg);
    cx=cos(deg);
}


void wcsAlign()
{
    lookX=lookX-eyeX;
    lookY=lookY-eyeY;
    lookZ=lookZ-eyeZ;

    tric(-theta_x);//X axix
    dy = lookY*cx-lookZ*sx;
    dz = lookY*sx+lookZ*cx;

    lookY=dy;
    lookZ=dz;

    tric(-theta_y);//Y axix
    dx = lookX*cx+lookZ*sx;
    dz = -lookX*sx+lookZ*cx;

    lookX = dx;
    lookZ = dz;

    tric(-theta_z);//Z axix

    dx = lookX*cx-lookY*sx;
    dy = lookX*sx+lookY*cx;

    lookX = dx;
    lookY = dy;

//    cout << "WCS:" << endl;
//    cout << lookX << " " << lookY << " " << lookZ << endl;
}

void retransform()
{
    tric(theta_z);//Z axix

    dx = lookX*cx-lookY*sx;
    dy = lookX*sx+lookY*cx;

    lookX = dx;
    lookY = dy;

    tric(theta_y);//Y axix
    dx = lookX*cx+lookZ*sx;
    dz = -lookX*sx+lookZ*cx;

    lookX = dx;
    lookZ = dz;

    tric(theta_x);//X axix
    dy = lookY*cx-lookZ*sx;
    dz = lookY*sx+lookZ*cx;

    lookY=dy;
    lookZ=dz;


//    cout << "VCS:" << endl;
//    cout << lookX << " " << lookY << " " << lookZ << endl;

    lookX=lookX+eyeX;
    lookY=lookY+eyeY;
    lookZ=lookZ+eyeZ;

}



void FrustumChange(bool positive = true)
{
    if(positive)nearP++;
    else nearP--;
}

void Pitch(bool clock = true)
{
    // Translate to origin
//    if(clock)bita++;
//    else bita--;
//    GLfloat dx = 0 ;
//    GLfloat dy = 0;
//    GLfloat dz = -eyeZ;
//
//    GLfloat new_x = dx;
//    GLfloat new_y = dy*cos(bita*PI/180.0)-dz*sin(bita*PI/180.0);
//    GLfloat new_z = dy*sin(bita*PI/180.0) +dz*cos(bita*PI/180.0);
//
//    lookX = new_x;
//    lookY = new_y;
//    lookZ = new_z-dz;


    if(clock){
        wcsAlign();
        theta_x += 1;
        retransform();
    }
    else{
        wcsAlign();
        theta_x -= 1;
        retransform();
    }

}



void Roll(bool clock = true)
{
//    if(clock)alpha++;
//    else alpha--;
//    up_x = -sin(PI*alpha/180.0);
//    up_y = cos(PI*alpha/180);


    if(clock){
        dx = up_x*cs+up_y*sn;
            dy = -up_x*sn+up_y*cs;

            up_x=dx;
            up_y=dy;

            theta_z -= 1;
    }
    else{
        dx = up_x*cs-up_y*sn;
            dy = up_x*sn+up_y*cs;

            up_x=dx;
            up_y=dy;

            theta_z += 1;
    }
}

void Yaw(bool clock = true)
{
//    if(clock) theta++;
//    else theta--;
//    GLfloat dx =0;
//    GLfloat dy = 0;
//    GLfloat dz = -eyeZ;
//
//    GLfloat new_x = dx*cos(theta*PI/180.0)+dz*sin(theta*PI/180.0);
//    GLfloat new_y = dy;
//    GLfloat new_z = -dx*sin(theta*PI/180.0) +dz*cos(theta*PI/180.0);
//
//    lookX = new_x;
//    lookY = new_y;
//    lookZ = -dz+new_z;

    if(clock){
        wcsAlign();
        theta_y += 1;
        retransform();
    }
    else{

        wcsAlign();
            theta_y -= 1;
            retransform();
    }
}


void zoom(bool positive = true)
{
    float dx = lookX - eyeX;
    float dy = lookY - eyeY;
    float dz = lookZ - eyeZ;
    float unit_dist = sqrt(dx*dx+dy*dy+dz*dz);
    if(unit_dist<=.1 && positive)return;
    if(!positive)unit_dist*=-1;
    eyeX+=dx/unit_dist;
    eyeY+=dy/unit_dist;
    eyeZ+=dz/unit_dist;
    lookX+=dx/unit_dist;
    lookY+=dy/unit_dist;
    lookZ+=dz/unit_dist;

}

void drawaxes()
{
    glPushMatrix();// axis drawing
//        c = 9;

//        glColor3f(colors[c][0],colors[c][1],colors[c][2]);
        glColor3f(redish[0],redish[1],redish[2]);
        glBegin(GL_LINES);
        glVertex3f(-wall_length,0,0);
        glVertex3f(wall_length, 0, 0);//x axis
        glEnd();

//        c = 8;
//        glColor3f(colors[c][0],colors[c][1],colors[c][2]);
        glColor3f(redish[0],redish[1],redish[2]);
        glBegin(GL_LINES);
        glVertex3f(0,0,0);
        glVertex3f(0, wall_length, 0);//y axis
        glEnd();

//        c = 1;
//        glColor3f(colors[c][0],colors[c][1],colors[c][2]);

        glColor3f(redish[0],redish[1],redish[2]);
        glBegin(GL_LINES);
        glVertex3f(0,0,0);
        glVertex3f(0, 0, wall_length);//z axis
        glEnd();


    glPopMatrix();

}

// bomb
float currentX = 0, currentY = 0, currentZ = 0;
float destionationX = 25, destionationY = 0, destionationZ = 0;

float getPt( float n1 , float n2 , float perc ) {
    float diff = n2 - n1;
    return n1 + ( diff * perc );
}

struct Point{
    float x,y,z;
};

GLfloat xTarget = 0, yTarget = 0, zTarget = 0;
bool canChangeTheTarget = true;
void put_mine()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,v[13]);

    glPushMatrix();
        glScalef(1, 0.1, 1);
        glTranslatef(xTarget, yTarget, zTarget);
//        glColor3f(green[0], green[1], green[2]);
        circle_3D(1);
//        drawcube(green[0], green[1], green[2], 1, 1, 1);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

vector<Point>missile_v;

int pos;
bool shouldThrow;
float bomb_effect = 10.0;
//float xMissile, yMissile, zMissile;

/*void bomb()
{
    glPushMatrix();
        missile_v.clear();
//        cout<<"eyeX "<<eyeX<<' '<<eyeY<<' '<<eyeZ<<endl;
//        float x1=0, y1=0, z1=0, x3=xTarget, y3=yTarget, z3=zTarget;
        float x1=eyeX+0.5, y1=eyeY+0.5, z1=eyeZ, x3=xTarget, y3=yTarget, z3=zTarget;
//        float x1=eyeX+5, y1=eyeY, z1=eyeZ, x3=xTarget, y3=yTarget, z3=zTarget;
        float x2=(x1+x3)/2, y2=max(y1,y3) + 1, z2=(z1+z3)/2;
        for( float i = 0 ; i < 1 ; i += 0.01 ) {
            float xa = getPt(x1, x2, i);
            float ya = getPt(y1, y2, i);
            float za = getPt(z1, z2, i);
            float xb = getPt(x2, x3, i);
            float yb = getPt(y2, y3, i);
            float zb = getPt(z2, z3 ,i);

            float x = getPt(xa, xb, i);
            float y = getPt(ya, yb, i);
            float z = getPt(za, zb, i);

            Point point3d;
            point3d.x = x;
            point3d.y = y;
            point3d.z = z;
            missile_v.push_back(point3d);
        }

        glPushMatrix();
            glBegin(GL_POINTS);
            for(auto it:missile_v){
                glColor3f(1, 1, 1);
                glVertex3f(it.x,it.y,it.z);
            }
            glEnd();
        glPopMatrix();

        if(shouldThrow==true){
            glPushMatrix();
                glScalef(1,1,1);
                glTranslatef(missile_v[pos].x, missile_v[pos].y, missile_v[pos].z);
                glColor3f(1,1,1);
                drawcube(white[0],white[1],white[2],1,1,1);

//                std::this_thread::sleep_for(std::chrono::milliseconds(17));

                pos+=5;

                if(pos>=missile_v.size()){
//                        if((xTarget < (car_x +bomb_effect) || xTarget > (car_x -bomb_effect)) && (yTarget < (car_y +bomb_effect) || yTarget >(car_y -bomb_effect)) && (zTarget < (car_z +bomb_effect) || zTarget > (car_z -bomb_effect))){
                        if(abs(xTarget-car_x)<bomb_effect && abs(yTarget-car_y)<bomb_effect && abs(zTarget-car_z)<bomb_effect){
                            car_running = false;
                            game_over = true;
                            win = true;

                        }
                        else{
                            car_running = false;
                            game_over = true;
                            loose = true;
                        }
                    pos = 0;
                    shouldThrow=false;
                    canChangeTheTarget = true;

                }

            glPopMatrix();
        }
    glPopMatrix();
}

void throwTheMissile()
{
    shouldThrow = true;
    canChangeTheTarget = false;
}*/

void blust_mine(){
    if(!bomb_sound){
        bombBlustSound();
        bomb_sound = true;
    }
    if(abs(xTarget-car_x)<bomb_effect && abs(yTarget-car_y)<bomb_effect && abs(zTarget-car_z)<bomb_effect){

                            car_running = false;
                            game_over = true;
                            win = true;
                            loose = false;


                        }
    else{

        car_running = false;
        game_over = true;
        loose = true;
        win = false;
    }
}





void spotlight(float x,float y, float z,float spt_cutoff)
{
    /*GLfloat l_no[] = {0, 0, 0, 1.0};
    GLfloat l_amb[] = {0.1, 0.1, 0.1, 1.0};
    GLfloat l_dif[] = {1,1,1,1};
    GLfloat l_spec[] = {0.2,0.2,0.2,1};*/

    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[]  = {0.5, 0.5, 0.5, 1.0};
    GLfloat light_diffuse[]  = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//    GLfloat light_position[] = { 200, 9.5, -15 };  //0.7, 1.5, 9.0

    GLfloat l_pos3[] = {x,y,z,1.0};
    glEnable(GL_LIGHT2);
    glLightfv(GL_LIGHT2,GL_AMBIENT,light_ambient);
    glLightfv(GL_LIGHT2,GL_DIFFUSE,light_diffuse);
    glLightfv(GL_LIGHT2,GL_SPECULAR,light_specular);
    glLightfv(GL_LIGHT2,GL_POSITION,l_pos3);
//    GLfloat l_spt[] = {0,0,-1,1};
//    GLfloat spt_ct[] = {spt_cutoff};
//    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, l_spt);
//    glLightfv(GL_LIGHT2, GL_SPOT_CUTOFF, spt_ct);

    if(l_on3)
    {

        if(ambflag)
        {
            glLightfv(GL_LIGHT2,GL_AMBIENT,light_ambient);
        }
        else
        {
            glLightfv(GL_LIGHT2,GL_AMBIENT,no_light);
        }
        if(difflag)
        {
            glLightfv(GL_LIGHT2,GL_DIFFUSE,light_diffuse);
        }
        else
        {
            glLightfv(GL_LIGHT2,GL_DIFFUSE,no_light);
        }
        if(specflag)
        {
            glLightfv(GL_LIGHT2,GL_SPECULAR,light_specular);
        }
        else
        {
            glLightfv(GL_LIGHT2,GL_SPECULAR,no_light);
        }
    }
    else
    {
        glLightfv(GL_LIGHT2,GL_AMBIENT,no_light);
        glLightfv(GL_LIGHT2,GL_DIFFUSE,no_light);
        glLightfv(GL_LIGHT2,GL_SPECULAR,no_light);
    }

//    GLfloat l_spt[] = {0,0,-1,1};

    GLfloat l_spt[] = {0,0,-1,1};
    GLfloat spt_ct[] = {spt_cutoff};
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, l_spt);
    glLightfv(GL_LIGHT2, GL_SPOT_CUTOFF, spt_ct);


}


void Tire()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,v[5]);

    glPushMatrix();
    GLfloat mat_ambient[] = { 1, 1, 1, 1.0 };
    GLfloat mat_diffuse[] = { 1, 1, 1, 1.0 };
    GLfloat mat_specular[] = { 0.1,0.1,0.1, 1.0 };
    GLfloat mat_shininess[] = {90};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    glutSolidTorus(0.2, 0.8, 5, 50);
    glPopMatrix();




    glPushMatrix();
    glTranslated(0,-0.8,0);
    glScaled(0.1,1.5,0.1);
    drawcube(1,1,1,1,1,1);
    glPopMatrix();




    glPushMatrix();
    glTranslated(0.8,0.0,0);
    glRotatef(90,0,0,1);
    glScaled(0.1,1.5,0.1);
    drawcube(1,1,1,1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.1,0.0,0);
    glRotatef(45,0,0,1);
    glPushMatrix();
    glTranslated(0.8,0.0,0);
    glRotatef(90,0,0,1);
    glScaled(0.1,1.5,0.1);
    drawcube(1,1,1,1,1,1);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    //glTranslated(0.0,0.0,0);
    glRotatef(-45,0,0,1);
    glPushMatrix();
    glTranslated(0.8,0.0,0);
    glRotatef(90,0,0,1);
    glScaled(0.1,1.5,0.1);
    drawcube(1,1,1,1,1,1);
    glPopMatrix();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);


}


void car_body(void)
{
    //glRotatef(rot,0,1,0);

    ///CAR nicher body
    if(win){
            glBindTexture(GL_TEXTURE_2D,v[12]);
    }
    else{
        glBindTexture(GL_TEXTURE_2D,v[6]);
    }

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-0.1-1+x_look,-2,-2+z_look);

    //glRotatef(rot,0,1,0);

    glScaled(2.2,1,4);
    drawcube(1,1,1,1,1,1);
    glDisable(GL_TEXTURE_2D);
    //glRotatef(rot,0,1,0);
    glPopMatrix();



    ///Red light1
    if(win){
            glBindTexture(GL_TEXTURE_2D,v[12]);
    }
    else{
        glBindTexture(GL_TEXTURE_2D,v[7]);
    }

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-1+x_look,-1.25,-1.9+z_look);
    //reff();
    glScaled(.4,.2,4);
    drawcube(1,1,1,1,1,1);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    ///red light 2
    if(win){
            glBindTexture(GL_TEXTURE_2D,v[12]);
    }
    else{
        glBindTexture(GL_TEXTURE_2D,v[7]);
    }

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0.6+x_look,-1.25,-1.9+z_look);
    glScaled(.4,.2,4);
    drawcube(1,1,1,1,1,1);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    ///head light3
    if(l_on3){
        glBindTexture(GL_TEXTURE_2D,v[10]);
    }
    else{
        glBindTexture(GL_TEXTURE_2D,v[9]);
    }

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-1+x_look,-1.25,1.9+z_look);
    //reff();
    glScaled(.4,.2,-4);
    drawcube(1,1,1,1,1,1);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    ///head light 4
    if(l_on3){
        glBindTexture(GL_TEXTURE_2D,v[10]);
    }
    else{
        glBindTexture(GL_TEXTURE_2D,v[9]);
    }
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0.6+x_look,-1.25,1.9+z_look);
    glScaled(.4,.2,-4);
    drawcube(1,1,1,1,1,1);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();




    ///numberplate
    if(win){
            glBindTexture(GL_TEXTURE_2D,v[12]);
    }
    else{
        glBindTexture(GL_TEXTURE_2D,v[8]);
    }

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-.3+x_look,-1.6,-1.9+z_look);
    glScaled(.6,.4,4);
    drawcube(1,1,1,1,1,1);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    /*///BUMPER
    glPushMatrix();
    glTranslatef(-1+x_look,-1.8,-1.9+z_look);
    glScaled(2,.1,4);
    drawcube(255.1/255,255.1/255,255.1/255,1,1,1);
    glPopMatrix();*/

    ///CAR TOP
    if(win){
            glBindTexture(GL_TEXTURE_2D,v[12]);
    }
    else{
        glBindTexture(GL_TEXTURE_2D,v[6]);
    }

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-1+.05+x_look,-1,-1.1+z_look);
    glScaled(1.9,.7,2);
    drawcube(1,1,1,1,1,1);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    ///back glass
    if(win){
            glBindTexture(GL_TEXTURE_2D,v[12]);
    }
    else{
        glBindTexture(GL_TEXTURE_2D,v[4]);
    }

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslated(-1+.15+.05+x_look,-1+.07,-1.1+z_look);
    glScaled(1.6,.6,2.1);
    drawcube(1,1,1,1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    ///Tyre
    glPushMatrix();
    glTranslatef(0.3-1.5+x_look,-1.9,-1.4+z_look);
    glRotatef(90,0,1,0);
    glScaled(0.5,0.5,0.5);
    Tire();
    glPopMatrix();
    ///Tyre
    glPushMatrix();
    glTranslatef(-0.25+1.5+x_look,-1.9,-1.4+z_look);
    glRotatef(90,0,1,0);
    glScaled(0.5,0.5,0.5);
    Tire();
    glPopMatrix();


    float dist=2.2;
    ///Tyre
    glPushMatrix();
    glTranslatef(0.3-1.5+x_look,-1.9,-1.4+z_look+dist);
    glRotatef(90,0,1,0);
    glScaled(0.5,0.5,0.5);
    Tire();
    glPopMatrix();
    ///Tyre
    glPushMatrix();
    glTranslatef(-0.25+1.5+x_look,-1.9,-1.4+z_look+dist);
    glRotatef(90,0,1,0);
    glScaled(0.5,0.5,0.5);
    Tire();
    glPopMatrix();
}

//float moving = 0.0f;

void car()
{
    glPushMatrix();

//        glTranslatef(0, 0, -150);
        glTranslatef(car_x, car_y, car_z);
        glRotatef(90, 0, -1, 0);
        glPushMatrix();
//        glTranslatef(-1+x_look,-1.25,1.9+z_look);
        spotlight(x_look,-1.25,1.9+z_look,20);
        glPopMatrix();
        glScalef(1.0,1.0,1.0);

        if (car_running){
            car_x += 0.3f;
        if(car_x>100){
            car_x=0.0f;
        }
        }

        car_body();
//        glRotatef(Loop, 0.9, 4.0, 0.6);a

    glPopMatrix();
}






void jhop(double pos_x=6.0,double pos_y=0.0,double pos_z =0.0)
{
        glPushMatrix();
    glTranslatef(pos_x,pos_y+4,pos_z+0);
    glBindTexture(GL_TEXTURE_2D,2);
    glEnable(GL_TEXTURE_2D);
    circle_3D(1.0);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(pos_x-0.8,pos_y+4.3,pos_z+0);
    glBindTexture(GL_TEXTURE_2D,2);
    glEnable(GL_TEXTURE_2D);
    circle_3D(1.0);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(pos_x+0.8,pos_y+4.3,pos_z-0.2);
    glBindTexture(GL_TEXTURE_2D,2);
    glEnable(GL_TEXTURE_2D);
    circle_3D(1.0);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    /*glPushMatrix();
    glTranslatef(pos_x+0.8,pos_y+4.3,pos_z+0.2);
    glBindTexture(GL_TEXTURE_2D,2);
    glEnable(GL_TEXTURE_2D);
    circle_3D(1.0);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();*/
}

void Tree(double pos_x=0.4,double pos_y=0.3,double pos_z =10)
//void Tree()
{




    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,v[0]);

    glPushMatrix();
    Cylinder3D(pos_x,pos_y,pos_z);
//    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);


    glPushMatrix();
    glTranslatef(0,pos_z+1,0);
    glBindTexture(GL_TEXTURE_2D,2);
    glEnable(GL_TEXTURE_2D);
    circle_3D(2.3);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-0.8,pos_z-0.3,0);
    glBindTexture(GL_TEXTURE_2D,2);
    glEnable(GL_TEXTURE_2D);
    circle_3D(2.3);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8,pos_z-0.3,-0.2);
    glBindTexture(GL_TEXTURE_2D,2);
    glEnable(GL_TEXTURE_2D);
    circle_3D(2.3);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();




}


void piler()
{
    for(int i=-10; i<10; i ++)
    for(double j = 0;j<5; j=j+1.8){
    {


        glPushMatrix();
        glTranslatef(8.5*i,-2.9,10+j);


        glPushMatrix();
        glTranslatef(3.7*i,0,10+j);
        glScaled(1,1,1);
        Tree(0.4,0.3,10);
        jhop();
        glPopMatrix();

        GLfloat mat_ambient[] = { 1, 1, 1, 1.0 };
        GLfloat mat_diffuse[] = { 1, 1, 1, 1.0 };
        GLfloat mat_specular[] = { 0.1,0.1,0.1, 1.0 };
        GLfloat mat_shininess[] = {90};

        glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
        glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
        glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
        glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);



        /*glBindTexture(GL_TEXTURE_2D,6);
        glEnable(GL_TEXTURE_2D);

        glPushMatrix();
        //glColor3d(1,0,0);

        GLUquadricObj *quadratic;

        quadratic = gluNewQuadric();
        gluQuadricTexture(quadratic, GL_TRUE);
        glRotatef(-90.0f, 1.0f,0.0f, 0.0f);
        gluCylinder(quadratic,0.2f,0.2f,3.0f,32,32);
        //gluQuadricTexture(quadratic, TRUE);
        gluDeleteQuadric(quadratic);
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);*/
        glPopMatrix();
    }
    }
    for(int i=-10; i<10; i++)
        for(double j = 0;j<5; j=j+2){
    {

        glPushMatrix();
        glTranslatef(10*i,-2.9,5-j);


        //glPushMatrix();
        glPushMatrix();
        glTranslatef(2.8*i,0,5-j);
        //glScaled(1,1,1);
        Tree(0.4,0.3,10);
        jhop();
        glPopMatrix();
        //glPopMatrix();

        GLfloat mat_ambient[] = { 1, 1, 1, 1.0 };
        GLfloat mat_diffuse[] = { 1, 1, 1, 1.0 };
        GLfloat mat_specular[] = { 0.1,0.1,0.1, 1.0 };
        GLfloat mat_shininess[] = {80};

        glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
        glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
        glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
        glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);




        /*glBindTexture(GL_TEXTURE_2D,6);
        glEnable(GL_TEXTURE_2D);
        glPushMatrix();
        //glColor3d(1,0,0);
        GLUquadricObj *quadratic;
        quadratic = gluNewQuadric();
        gluQuadricTexture(quadratic, GL_TRUE);
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
        gluCylinder(quadratic,0.2f,0.2f,3.0f,32,32);
        //gluQuadricTexture(quadratic, TRUE);
        gluDeleteQuadric(quadratic);
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);*/
        glPopMatrix();
    }

        }
}

void drawRoad()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,v[3]);
    glPushMatrix();
    glTranslatef(-100,0.01,10);
    glScalef(200,0,10);

    drawcube(black[0],black[1],black[2],1,1,1);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

}
void drawRoom()
{
    //floor
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,v[2]);
    glPushMatrix();
    glTranslatef(-100,0,0);
    glScalef(200,0,30);

    drawcube(brown[0],brown[1],brown[2],1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

}

void board(float x, float y,float z)
{
    //floor
//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D,v[2]);
    glPushMatrix();
    glTranslatef(x,y,z);
    glScalef(20,20,0);

    drawcube(brown[0],brown[1],brown[2],1,1,1);
    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);

}


void sun_moon(){

    if(day){

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,v[11]);
    glPushMatrix();
    light0(30,30,0);
    glTranslatef(30,30,0);
//    glScalef(200,0,30);
    circle_3D(2);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    }

    else{

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,v[13]);
    glPushMatrix();
    light0(30,30,0);
    glTranslatef(30,30,0);
//    glScalef(200,0,30);
    circle_3D(2);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    }
}


void drawSphere(float am_r, float am_g, float am_b, float df_r, float df_g, float df_b )
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
//    GLfloat mat_ambient[] = { 0.0, 0.5, 0.0, 1.0 };
    GLfloat mat_ambient[] = { am_r, am_g, am_b, 1.0 };

//    GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_diffuse[] = { df_r, df_g, df_b, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);



//    glPushMatrix();
//    glTranslatef(155, 0, -15);
//    glScalef(0.6, 1, .4);
    glutSolidSphere (2.0, 20, 16);
//    glPopMatrix();

}


/*void init (void) {
//    glEnable( GL_TEXTURE_2D );
//    glEnable(GL_DEPTH_TEST);

    glCreateParticles();

//    texture[0] = LoadTextureRAW( "F://4.2//academic//Graphics//fire//particle_mask.raw",256,256); //load our texture
//    texture[1] = LoadTextureRAW( "F://4.2//academic//Graphics//fire//particle.raw",256,256);
//load our texture
}*/

void display(void)
{


    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
//    glFrustum(-5,5, -5, 5, 4, 50);
    glFrustum(-5,5,-5,5,nearP,farP);
    //gluPerspective(60,1,5,100);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    //gluLookAt(eyeX,eyeY,eyeZ, lookX,lookY,lookZ, 0,1,0); // camera , ,
    //gluLookAt(eyeX+cdist,eyeY+cdist,eyeZ+cdist, lookX+dx,lookY+dy,lookZ+dz, xaxis,yaxis,zaxis);
    gluLookAt(eyeX,eyeY,eyeZ,lookX,lookY,lookZ,up_x,up_y,up_z);

//    gluLookAt(eyeX,eyeY,eyeZ, axis_x, axis_y, axis_z, 0,1,0);
    glViewport(0, 0, windowHeight, windowWidth);


    drawaxes();
    sun_moon();

    //drawcube(redish[0],redish[1],redish[2],1,1,1);
//    glutSolidCube(1.0);

    drawRoom();
    drawRoad();
    piler();
    if(makeSound){
        carSound();
        makeSound = false;
    }

    car();
    //bomb();
    put_mine();


//    fire(car_x,car_y,car_z);

//    init();



    if(win){

        string g_msg = "You Win!!!!";
//        board(x_look-5,6,z_look+9);
        textDisplay(g_msg,x_look-5,6,z_look+10);
    }
    else if(loose){
        string g_msg = "You Loose!!!!";
//        board(x_look-5,6,z_look+10);
        textDisplay(g_msg,x_look-5,6,z_look+10);

    }
    if(game_over){
        fire(xTarget,yTarget,zTarget-8);
        string g_over = "Game Over!";
        board(x_look-5,3,z_look+9);
        textDisplay(g_over,x_look-5,3,z_look+10);
        /*if(loose)
        {
            looseSound();
        }
        else{
            winSound();
        }*/
    }



    glFlush();
    glutSwapBuffers();
}


void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {
    //case '1':
    case '1':
        bRotate = !bRotate;
        uRotate = false;
        axis_x=0.0;
        axis_y=1.0;
        break;

    //case '2':
    case '2':
        uRotate = !uRotate;
        bRotate = false;
        axis_x=1.0;
        axis_y=0.0;
        break;


    case '+': //zoom in
        zoom();
        break;
    case '-': //zoom out
        zoom(false);
        break;
    case '*': //zoom up
        eyeY++;
        lookY++;
        break;
    case '/': //zoom down
        eyeY--;
        lookY--;
        break;

    case 'x':
        eyeX++;
        lookX++;
        break;
    case 'z':
        eyeX--;
        lookX--;
        break;
    case 'y':
        Yaw();
        break;
    case 'Y':
        Yaw(false);
        break;

    case 'r':
        Roll();
        break;
    case 'R':
        Roll(false);
        break;

    case 'p':
        Pitch();
        break;

    case 'P':
        Pitch(false);
        break;


    case 'f':
        FrustumChange();
        break;

    case 'F':
        FrustumChange(false);
        break;
    //ambient light handle
    case 'A':
        ambient0 = true;
//        light0();
        break;
    case 'a':
        ambient0 = false;
//        light0();
        break;
    //diffuse light handle
    case 'D':
        diffuse0 = true;
//        light0();
        break;
    case 'd':
        diffuse0 = false;
//        light0();
        break;

    //specular light handle
    case 'S':
        specular0 = true;
//        light0();
        break;
    case 's':
        specular0 = false;
//        light0();
        break;
    case '5':
        day = false;
        ambient0 = false;
        diffuse0 = true;
        specular0 = false;
        break;
    case '6':
        day = true;
        ambient0 = true;
        diffuse0 = true;
        specular0 = true;
        break;

    //ambient light handle
    /*case 'Q':
        ambient1 = true;
        light1();
        break;
    case 'q':
        ambient1 = false;
        light1();
        break;
    //diffuse light handle
    case 'W':
        diffuse1 = true;
        light1();
        break;
    case 'w':
        diffuse1 = false;
        light1();
        break;

    //specular light handle
    case 'E':
        specular1 = true;
        light1();
        break;
    case 'e':
        specular1 = false;
        light1();
        break;*/

    case 'h':
    case 'H':
        l_on3=1-l_on3;
        break;

    /*case 'i':
    case 'I':
        ambflag=1-ambflag;
        break;

    case 't':
    case 'T':
        difflag=1-difflag;
        break;
    case 'u':
    case 'U':
        specflag=1-specflag;
        break;*/

        // throw the missile
        case '4':
//            throwTheMissile();
            blust_mine();
            break;

        // to move the target
        case 'g': // up
            if(canChangeTheTarget==false) break;
            zTarget--;
            break;
        case 'b': // down
            if(canChangeTheTarget==false) break;
            zTarget++;
            break;
        case 'v': // left
            if(canChangeTheTarget==false) break;
            xTarget--;
            break;
        case 'n': // right
            if(canChangeTheTarget==false) break;
            xTarget++;
            break;
        case 'G': // up
            if(canChangeTheTarget==false) break;
            yTarget++;
            break;
        case 'B': // down
            if(canChangeTheTarget==false) break;
            yTarget--;
            break;


    case 27:	// Escape key
        exit(1);
    }
}




void animate()
{
    if (bRotate == true)
    {
        theta += 0.5;
        if(theta > 360.0)
            theta -= 360.0*floor(theta/360.0);
    }

    if (uRotate == true)
    {
        alpha += 0.5;
        if(alpha > 360.0)
            alpha -= 360.0*floor(alpha/360.0);
    }
    glutPostRedisplay();

}




int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(windowHeight, windowWidth);
    glutCreateWindow("Kill The Man");

    texture_image();


    /*int total_tree = 50;
    int tree_position [50][3];
    for(int i = 0; i<50;i++){
        int xx,yy,zz;
        xx = rand()%150;
        yy = rand()%150;
        zz = rand()%150;
        if(i%2 ==0){
            xx = -xx;
            yy = -yy;
            zz = -zz;
        }
        tree_position[i][0] = xx;
        tree_position[i][1] = yy;
        tree_position[i][2] = zz;
    }*/

    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
//    light0();
//    light1();
//    init();
    glCreateParticles();

//    glutReshapeFunc (reshape);
    glutKeyboardFunc(myKeyboardFunc);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();

    return 0;
}

