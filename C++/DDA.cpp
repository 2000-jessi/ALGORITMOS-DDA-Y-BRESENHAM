#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <GL/glut.h>  // GLUT

using namespace std;


double x_1, y_1, x_2, y_2, steps, dy, dx;
double xinc,yinc;

void Display(){
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	glLoadIdentity();
	
	//PLANO CARTESIANO
	glLineWidth(12.0);
	glColor3f(0.0f, 0.0f, 0.0f);//Black
	glBegin(GL_LINES);
		glVertex2d(-30,0); 
		glVertex2d(30,0);
		glVertex2d(0,30);
		glVertex2d(0,-30);
	glEnd();
	
	//LINEAS CUADRICULADAS
	glLineWidth(2.0);
	glColor3f(0.1f, 0.1f, 0.1f);//Dark grey
	
	glBegin(GL_LINES);
		for(int j=31;j>-30;j--){ //LINEAS HORIZONTALES
			glVertex2f(-30,j+0.5);
			glVertex2f(30,j+0.5);
		}
		for(int j=31;j>-30;j--){ //LINEAS VERTICALES
			glVertex2f(j+0.5, -30);
			glVertex2f(j+0.5, 30);
		}
	glEnd();
	
	glPointSize(14);
	glBegin(GL_POINTS);
		glColor3f(1.0f, 5.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f); //ORIGEN
		glColor3f(0.0f, 0.5f, 0.5f);//Blue-Green
		//ALGORITMO DDA
		dx=(x_2 - x_1);
		dy=(y_2 - y_1);
	
		cout << "dx= " << dx << "\n";
		cout << "dy= " << dy << "\n";
		
		if(dx>dy){
			steps=dx;
			cout << "steps= " << steps << "\n";
		}
		else{
			steps=dy;
			cout << "steps= " << steps << "\n";
		}
		
		yinc=(dy/steps);
		xinc=(dx/steps);
		
		for(int k=0;k<steps+1;k++){
			glVertex2d(round(x_1),round(y_1));
			x_1= x_1 + xinc;
			y_1= y_1 + yinc;
			cout <<"===>(" << x_1 <<","<< y_1 <<")" "\n";
		}
		
	glEnd();
	
	glFlush();
}

void Init(){
	glClearColor(1,1,1,0); //Color blanco
}

void reshape(int width, int height){
	glViewport(0,0,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-30,30,-30,30,-1,1);
	glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char *argv[]){
	cout <<"Ingrese x1: "; cin >> x_1;
	cout <<"Ingrese y1: "; cin >> y_1;
	cout <<"Ingrese x2: "; cin >> x_2;
	cout <<"Ingrese y2: "; cin >> y_2;
	
	
	glutInit(& argc, argv); //Inicializacion de de biblioteca GLUT
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); //Modo de display con el se creara las ventanas
	glutInitWindowSize(800,800); //Tamanio de la ventana de grafica
	glutInitWindowPosition(0,0);
	glutCreateWindow("Algoritmo DDA"); //Le damos titulo a nuestra ventana 
	Init(); //Se ejecuta la inicializacion
	glutDisplayFunc(Display); //Asigna la imagen a la ventana de visualización 
	//Especifica que va a contener la ventana de visualización y envia los graficos a la ventana de visualizacion 
	glutReshapeFunc(reshape); //Cambio de tamanio de la ventana actual 
	glutMainLoop(); 
	return 0;
}