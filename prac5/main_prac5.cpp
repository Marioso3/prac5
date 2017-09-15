//Semestre 2018 - 2
////Visual Studio 2015

//************************************************************//

//************************************************************//

//************** Alumno (s):Sotres Cataño Mario ****************//

//*************											******//

//*************											******//

//************************************************************//

#include "Main.h"

float transZ = -5.0f;

float transX = 0.0f;

float angleX = 0.0f;

float angleY = 0.0f;

int screenW = 0.0;

int screenH = 0.0;
float angHombro = 0.0f;
float angCodo = 0.0f;
float angPalma = 0.0f;
float angPulgar1 = 0.0f;
float angPulgar2 = 0.0f;
float angDedos1 = 0.0f;
float angDedos2 = 0.0f;
float angDedos3 = 0.0f;




void InitGL ( void )     // Inicializamos parametros

{



	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer

	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

	//glEnable(GL_LIGHTING);

	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar

	//glEnable ( GL_COLOR_MATERIAL );

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}



void prisma(void)

{

	GLfloat vertice [8][3] = {

				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0

				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1

				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2

				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3

				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4

				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5

				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6

				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7

				};



		glBegin(GL_POLYGON);	//Front

			//glColor3f(1.0,0.0,0.0);

			glVertex3fv(vertice[0]);

			glVertex3fv(vertice[4]);

			glVertex3fv(vertice[7]);

			glVertex3fv(vertice[1]);

		glEnd();



		glBegin(GL_POLYGON);	//Right

			glColor3f(0.0,0.0,1.0);

			glVertex3fv(vertice[0]);

			glVertex3fv(vertice[3]);

			glVertex3fv(vertice[5]);

			glVertex3fv(vertice[4]);

		glEnd();



		glBegin(GL_POLYGON);	//Back

			glColor3f(0.0,1.0,0.0);

			glVertex3fv(vertice[6]);

			glVertex3fv(vertice[5]);

			glVertex3fv(vertice[3]);

			glVertex3fv(vertice[2]);

		glEnd();



		glBegin(GL_POLYGON);  //Left

			glColor3f(1.0,1.0,1.0);

			glVertex3fv(vertice[1]);

			glVertex3fv(vertice[7]);

			glVertex3fv(vertice[6]);

			glVertex3fv(vertice[2]);

		glEnd();



		glBegin(GL_POLYGON);  //Bottom

			glColor3f(0.4,0.2,0.6);

			glVertex3fv(vertice[0]);

			glVertex3fv(vertice[1]);

			glVertex3fv(vertice[2]);

			glVertex3fv(vertice[3]);

		glEnd();



		glBegin(GL_POLYGON);  //Top

			glColor3f(0.8,0.2,0.4);

			glVertex3fv(vertice[4]);

			glVertex3fv(vertice[5]);

			glVertex3fv(vertice[6]);

			glVertex3fv(vertice[7]);

		glEnd();

}



void display ( void )   // Creamos la funcion donde se dibuja

{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer

	//glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();


	glTranslatef(transX, 0.0f, transZ);

	glRotatef(angleY, 0.0, 1.0, 0.0);

	glRotatef(angleX, 1.0, 0.0, 0.0);

		//Poner Código Aquí.

		glPushMatrix();
			
			//*****************CABEZA**********************

			glPushMatrix();
				//(0,0,0)--->pivote
				glColor3f(1.0, 0.0, 0.0);
				prisma();
			glPopMatrix();

			//**********************CUELLO**************************
			glPushMatrix();
				//(0,-0.75,0)--->pivote de cuello
				glTranslatef(0.0,-0.75,0.0);
				glScalef(0.5,0.5,1.0);  //escalamos el cuello
				glColor3f(0.0,1.0,0.0);
				prisma();
			glPopMatrix();

			//***********************TORSO***************************
			glPushMatrix();
				//(0,-2.5,0)--->pivote del torso
				glTranslatef(0.0, -2.5, 0.0);
				glScalef(3.0,3.0,1.0);
				glColor3f(0.0,0.0,1.0);
				prisma();
			glPopMatrix();

			//*********************BRAZO IZQUIERDO***************************
			glPushMatrix();
			//(3,-1.5,0)--->pivote del torso
			glTranslatef(3.0, -1.5, 0.0);
			glScalef(3.0, 0.5, 1.0);
			glColor3f(1.0, 1.0, 0.0);
			prisma();
			glPopMatrix();

			//***********************MANO IZQUIERDA DEL MUÑECO*********************
			glPushMatrix();
			//(5.5,-1.5,0)--->pivote del torso
			glTranslatef(5.0, -1.5, 0.0);
			glScalef(1.0, 1.0, 1.0);
			glColor3f(0.8, 0.8, 0.0);
			prisma();
			glPopMatrix();

			//**********************PIERNA DERECHA******************
			glPushMatrix();
			//(-1,-7.5,0)--->pivote del torso
			glTranslatef(-1, -7.0, 0.0);
			glScalef(1.0, 6.0, 1.0);
			glColor3f(0.0, 0.8, 0.8);
			prisma();
			glPopMatrix();

			//*******************PIE DERECHO***********************
			glPushMatrix();
			//(-1,-7.5,0)--->pivote del torso
			glTranslatef(-1, -10.5, 0.0);
			glScalef(1.5, 1.0, 1.0);
			glColor3f(0.2, 0.2, 0.0);
			prisma();
			glPopMatrix();


			//*********************PIERNA IZQUIERDA********************
			glPushMatrix();
			//(1,-7.5,0)--->pivote del torso
			glTranslatef(1, -7.0, 0.0);
			glScalef(1.0, 6.0, 1.0);
			glColor3f(0.0, 0.8, 0.8);
			prisma();
			glPopMatrix();

			//*********************PIE IZQUIERDO*****************
			glPushMatrix();
			//(1,-7.5,0)--->pivote del torso
			glTranslatef(1, -10.5, 0.0);
			glScalef(1.5, 1.0, 1.0);
			glColor3f(0.2, 0.2, 0.0);
			prisma();
			glPopMatrix();

			//************************BRAZO DERECHO******************
			glTranslatef(-1.75, -2.5, 0.0);

			//**********hombro
			glRotatef(angHombro, 0.0, 0.0, 1.0); //Rotación del hombro. Sólo rota en z
			glPushMatrix();
				//(0,0,0)
				glColor3f(1.0, 0.0, 0.0);
				glScalef(0.5, 0.5, 1.0);
				prisma();
			glPopMatrix();

			//***********bícep (0,-0.75,0)
			glTranslatef(0.0, -0.75, 0.0);
			glPushMatrix();
				glScalef(0.5, 1.0, 1.0);
				glColor3f(0.0, 1.0, 0.0);
				prisma();
			glPopMatrix();

			//************codo
			glTranslatef(0.0, -0.75, 0.0);
			glRotatef(angCodo, 0.0, 0.0, 1.0); //Generalmente los rotate se ponen después de un traslado
			glPushMatrix();
				//(0,-0.75,0)
				glScalef(0.5, 0.5, 1.0);
				glColor3f(0.0, 0.0, 1.0);
				prisma();
			glPopMatrix();

			//**************antebrazo
			glTranslatef(0.0, -0.75, 0.0);
			glPushMatrix();
				//(0,-0.75,0)
				glScalef(0.5, 1.0, 1.0);
				glColor3f(0.4, 0.0, 0.0);
				prisma();
			glPopMatrix();

			//***********palma   (0,-3.0,0)	
			glTranslatef(0.0, -0.75, 0.0);
			glRotatef(angPalma, 0.0, 0.0, 1.0);
			glPushMatrix();
				glScalef(0.5, 0.5, 1.0);
				glColor3f(1.0, 1.0, 0.0);
				prisma();
			glPopMatrix();

			//**************pulgar. 
			//dedo 1
			glPushMatrix();
				glTranslatef(0.25, 0.0, 0.0);
				glRotatef(angPulgar1, 0.0, 0.0, 1.0);
				glTranslatef(0.1, 0.0, 0.0);

				glColor3f(0.3, 0.5, 0.0);
				glPushMatrix();
					glScalef(0.2, 0.1, 0.3);
					prisma();
				glPopMatrix();

				//dedo2	
				glTranslatef(0.1, 0.0, 0.0);
				glRotatef(angPulgar2, 0.0, 0.0, 1.0);
				glTranslatef(0.1, 0.0, 0.0);
		
				glColor3f(1.0, 0.87, 0.55);
				glScalef(0.2, 0.1, 0.3);
				prisma();
			glPopMatrix();

			//***************meñique
			//dedo1
			glPushMatrix();
				glTranslatef(-0.2, -0.25, 0.0);
				glRotatef(angDedos1, 1.0, 0.0, 0.0);
				glTranslatef(0.0, -0.05, 0.0);

				glColor3f(0.3, 0.5, 0.0);
				glPushMatrix();
					glScalef(0.1, 0.1, 0.3);
					prisma();
				glPopMatrix();

				//dedo2	
				glTranslatef(0.0, -0.05, 0.0);
				glRotatef(angDedos2, 1.0, 0.0, 0.0);
				glTranslatef(0.0, -0.05, 0.0);

				glColor3f(1.0, 0.87, 0.55);
				glPushMatrix();
					glScalef(0.1, 0.1, 0.3);
					prisma();
				glPopMatrix();
				//dedo	3
				glTranslatef(0.0, -0.05, 0.0);
				glRotatef(angDedos3, 1.0, 0.0, 0.0);
				glTranslatef(0.0, -0.05, 0.0);

				glColor3f(0.23, 0.67, 1.0);
				glPushMatrix();
					glScalef(0.1, 0.1, 0.3);
					prisma();
				glPopMatrix();

			glPopMatrix();


			//***************Anular
			//dedo1
			glPushMatrix();
				glTranslatef(-0.067, -0.25, 0.0);
				glRotatef(angDedos1, 1.0, 0.0, 0.0);
				glTranslatef(0.0, -0.1, 0.0);

				glColor3f(0.3, 0.5, 0.0);
				glPushMatrix();
					glScalef(0.1, 0.2, 0.3);
				prisma();
				glPopMatrix();

				//dedo2	
				glTranslatef(0.0, -0.1, 0.0);
				glRotatef(angDedos2, 1.0, 0.0, 0.0);
				glTranslatef(0.0, -0.1, 0.0);

				glColor3f(1.0, 0.87, 0.55);
				glPushMatrix();
					glScalef(0.1, 0.2, 0.3);
					prisma();
				glPopMatrix();
				//dedo	
				glTranslatef(0.0, -0.1, 0.0);
				glRotatef(angDedos3, 1.0, 0.0, 0.0);
				glTranslatef(0.0, -0.1, 0.0);

				glColor3f(0.23, 0.67, 1.0);
				glPushMatrix();
					glScalef(0.1, 0.2, 0.3);
					prisma();
				glPopMatrix();

			glPopMatrix();


			//************Medio
			//dedo1
			glPushMatrix();
				glTranslatef(0.067, -0.25, 0.0);
				glRotatef(angDedos1, 1.0, 0.0, 0.0);
				glTranslatef(0.0, -0.15, 0.0);

				glColor3f(0.3, 0.5, 0.0);
				glPushMatrix();
					glScalef(0.1, 0.3, 0.3);
					prisma();
				glPopMatrix();

				//dedo2	
				glTranslatef(0.0, -0.15, 0.0);
				glRotatef(angDedos2, 1.0, 0.0, 0.0);
				glTranslatef(0.0, -0.15, 0.0);

				glColor3f(1.0, 0.87, 0.55);
				glPushMatrix();
					glScalef(0.1, 0.3, 0.3);
					prisma();
				glPopMatrix();
				//dedo	
				glTranslatef(0.0, -0.15, 0.0);
				glRotatef(angDedos3, 1.0, 0.0, 0.0);
				glTranslatef(0.0, -0.15, 0.0);

				glColor3f(0.23, 0.67, 1.0);
				glPushMatrix();
					glScalef(0.1, 0.3, 0.3);
					prisma();
				glPopMatrix();

			glPopMatrix();

			//***********Índice
			//dedo1
			glPushMatrix();
				glTranslatef(0.2, -0.25, 0.0);
				glRotatef(angDedos1, 1.0, 0.0, 0.0);
				glTranslatef(0.0, -0.1, 0.0);

				glColor3f(0.3, 0.5, 0.0);
				glPushMatrix();
					glScalef(0.1, 0.2, 0.3);
					prisma();
				glPopMatrix();

				//dedo2	
				glTranslatef(0.0, -0.1, 0.0);
				glRotatef(angDedos2, 1.0, 0.0, 0.0);
				glTranslatef(0.0, -0.1, 0.0);

				glColor3f(1.0, 0.87, 0.55);
				glPushMatrix();
					glScalef(0.1, 0.2, 0.3);
					prisma();
				glPopMatrix();
				//dedo	
				glTranslatef(0.0, -0.1, 0.0);
				glRotatef(angDedos3, 1.0, 0.0, 0.0);
				glTranslatef(0.0, -0.1, 0.0);

				glColor3f(0.23, 0.67, 1.0);
				glPushMatrix();
					glScalef(0.1, 0.2, 0.3);
					prisma();
				glPopMatrix();

			glPopMatrix();

		glPopMatrix();

	
		
									

  glutSwapBuffers ( );

  // Swap The Buffers

}



void reshape ( int width , int height )   // Creamos funcion Reshape

{

  if (height==0)										// Prevenir division entre cero

	{

		height=1;

	}



	glViewport(0,0,width,height);	



	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix

	glLoadIdentity();



	// Tipo de Vista

	//glOrtho(-5,5,-5,5,0.2,20);	

	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);



	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix

}



void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function

{

	switch ( key ) {

		//****************Dedos****************

		//parte de arriba de dedos
	case 'r':
		if (angDedos3 <= 47.5) {
			angDedos3 += 0.5f;
		}
		if (angPulgar2 >= -70.0) {
			angPulgar2 -= 0.5f;
		}
		break;
	case 'R':
		if (angDedos3 >= 0) {
			angDedos3 -= 0.5f;
		}
		if (angPulgar2 <= 0) {
			angPulgar2 += 0.5f;
		}
		break;

		//parte de en medio de dedos
	case 'j':
		if (angDedos2 <= 74) {
			angDedos2 += 0.5f;
		}
		if (angPulgar1 >= -48.5) {
			angPulgar1 -= 0.5f;
		}
		break;
	case 'J':
		if (angDedos2 >= 0) {
			angDedos2 -= 0.5f;
		}
		if (angPulgar1 <= 0) {
			angPulgar1 += 0.5f;
		}
		break;

		//parte de en abajo de dedos
	case 'c':
		if (angDedos1 <= 80) {
			angDedos1 += 0.5f;
		}
		break;
	case 'C':
		if (angDedos1 >= 0) {
			angDedos1 -= 0.5f;
		}
		break;

		//*****************manipulación de la mano***************************
	case 'o':
	case 'O':
		if (angPalma <= 19.0) {
			angPalma += 0.5f;
		}
		break;
	case 'p':
	case 'P':
		if (angPalma >= -19.0) {
			angPalma -= 0.5f;
		}
		break;

		//***********manipulación antebrazo/codo**********************
	case 'u':
	case 'U':
		if (angCodo <= 127) {
			angCodo += 0.5f;
		}
		break;
	case 'I':
	case 'i':
		if (angCodo >= 0) {
			angCodo -= 0.5f;
		}
		break;

		//**************manipulación de brazo*********************
	case 't':
	case 'T':
		if (angHombro <= 0) {
			angHombro += 0.5f;
		}
		break;
	case 'Y':
	case 'y':
		if (angHombro >= -90.0) {
			angHombro -= 0.5f;
		}
		break;


		//Acercamiento

	case 'w':
	case 'W':
		transZ += 0.2f;
		break;
	case 's':
	case 'S':
		transZ -= 0.2f;
		break;
	case 'a':
	case 'A':
		transX += 0.2f;
		break;
	case 'd':
	case 'D':
		transX -= 0.2f;
		break;

	case 27:        // Cuando Esc es presionado...

		exit(0);   // Salimos del programa

		break;

	default:        // Cualquier otra

		break;

  }

	glutPostRedisplay();

}



void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)

{

  switch ( a_keys ) {

  case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...

	  angleX += 2.0f;

	  break;

  case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...

	  angleX -= 2.0f;

	  break;

  case GLUT_KEY_LEFT:

	  angleY += 2.0f;

	  break;

  case GLUT_KEY_RIGHT:

	  angleY -= 2.0f;

	  break;

  default:

	  break;

  }

  glutPostRedisplay();

}





int main ( int argc, char** argv )   // Main Function

{

  glutInit            (&argc, argv); // Inicializamos OpenGL

  //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )

  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )

  screenW = glutGet(GLUT_SCREEN_WIDTH);

  screenH = glutGet(GLUT_SCREEN_HEIGHT);

  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana

  glutInitWindowPosition (0, 0);	//Posicion de la Ventana

  glutCreateWindow    ("Practica 4"); // Nombre de la Ventana

  printf("Resolution H: %i \n", screenW);

  printf("Resolution V: %i \n", screenH);

  InitGL ();						// Parametros iniciales de la aplicacion

  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo

  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano

  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado

  glutSpecialFunc     ( arrow_keys );	//Otras

  glutMainLoop        ( );          // 



  return 0;

}






