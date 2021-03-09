#include "stdlib.h"
#include "gl/glut.h"
#include "math.h"

const double PI = 3.141592653589793;
int i;

void back(){
glBegin(GL_QUADS);
glColor3f(1,1,1);
  glVertex2d (-150,150);
  glVertex2d(150,150);
  glVertex2d(150,-150);
  glVertex2d (-150,-150);
glEnd();
}


void lingkaran(int radius, int jumlah_titik, int x_tengah, int y_tengah) {
 glBegin(GL_POLYGON);
 for (i=0;i<=360;i++){
        float sudut=i*(2*PI/jumlah_titik);
        float x=x_tengah+radius*cos(sudut);
        float y=y_tengah+radius*sin(sudut);
  glVertex2f(x,y);
 }
 glEnd();
}

void ellips(float rx, float ry, float xc, float yc, int n){
	glBegin( GL_POLYGON);
            double t;
            for  (int i=0;  i < n;  ++i) {
                	t = i * 2.0 * 3.14159 / n;
                	glVertex2f( rx*cos(t)+xc, ry*sin(t)+yc );
            }
  	glEnd();
}

void Draw() {
 glClear(GL_COLOR_BUFFER_BIT);
 back();

 //Badan
 glColor3f(0.0, 0.0, 1.0);
 lingkaran(7,70,0,0);

 //Kepala
     glColor3f(1.0,1.0,1.0);
     ellips(4.0,5.5,0.0,6.0,36.0);
 glColor3f(0.0, 0.0, 1.0);
 ellips(3.8,5.3,0.0,6.0,36.0);

    //Mata Kiri
     glColor3f(1.0, 1.0, 1.0);
     ellips(0.7,1.0, -1.6,7.5,36.0);
     glColor3f(0.0, 0.0, 0.0); //Bola mata
     ellips(0.4,0.5, -1.6,7.1,36.0);
     //Mata Kanan
     glColor3f(1.0, 1.0, 1.0);
     ellips(0.7,1.0, 1.6,7.5,36.0);
     glColor3f(0.0, 0.0, 0.0); //Bola mata
     ellips(0.4,0.5, 1.6,7.1,36.0);

//Hidung
glColor3f(0.0, 0.0, 0.0); //Kanan
     ellips(0.2,0.3, -0.3 , 5.6,36.0);
glColor3f(0.0, 0.0, 0.0); //Kiri
     ellips(0.2,0.3, 0.3 , 5.6,36.0);

//Mulut
glColor3f(1.0, 1.0, 1.0);
     ellips(1.0,0.7, 0.0 , 3.4,36.0);

//Telinga
glColor3f(0.0, 0.0, 1.0); //Kanan
     ellips(2.0,0.5, 2.5 , 11.1,36.0);
glColor3f(0.0, 0.0, 1.0); //Kiri
     ellips(2.0,0.5, -2.5 , 11.1,36.0);

//kaku
glColor3f(0.0, 0.0, 1.0); //Kiri
     ellips(0.5,2.5, -2.5 , -8.1,36.0);
glColor3f(0.0, 0.0, 1.0); //Kiri
     ellips(0.5,2.5, 2.5 , -8.1,36.0);
 glFlush();
}


int main(int argc, char **argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(600, 600);
 glutInitWindowPosition(300, 300);
 glutCreateWindow("Lingkaran Titik Pusat ");
 gluOrtho2D(-15., 15., -15., 15.);
 glutDisplayFunc(Draw);
 glutMainLoop();
 return 0;
}
