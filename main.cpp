#include <GL/glut.h>
#include <cmath>


float buildingHeight = 1.2f; //adjusted building height to have two equal floors
float spaceHeight = 0.02f; //adjust the height of the space between floors

void drawBuilding() {
    
    //draw first floor
    glColor3f(0.7f, 0.7f, 0.7f); //light Gray
    glBegin(GL_QUADS);
    // Front face
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, 0.0f, 1.0f);
    // Back face
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 0.0f, -1.0f);
    glVertex3f(1.0f, 0.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    // Right face
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, 0.0f, -1.0f);
    glVertex3f(1.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    // Left face
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, 0.0f, -1.0f);
    glEnd();


    //draw second floor
    glColor3f(0.7f, 0.7f, 0.7f);
    glBegin(GL_QUADS);
    // Front face
    glVertex3f(-1.0f, spaceHeight, 1.0f); 
    glVertex3f(1.0f, spaceHeight, 1.0f); 
    glVertex3f(1.0f, buildingHeight + spaceHeight, 1.0f); 
    glVertex3f(-1.0f, buildingHeight + spaceHeight, 1.0f); 
    // Back face
    glVertex3f(-1.0f, spaceHeight, -1.0f);
    glVertex3f(1.0f, spaceHeight, -1.0f); 
    glVertex3f(1.0f, buildingHeight + spaceHeight, -1.0f); 
    glVertex3f(-1.0f, buildingHeight + spaceHeight, -1.0f); 
    // Right face
    glVertex3f(1.0f, spaceHeight, -1.0f); 
    glVertex3f(1.0f, spaceHeight, 1.0f);
    glVertex3f(1.0f, buildingHeight + spaceHeight, 1.0f); 
    glVertex3f(1.0f, buildingHeight + spaceHeight, -1.0f); 
    // Left face
    glVertex3f(-1.0f, spaceHeight, -1.0f); 
    glVertex3f(-1.0f, spaceHeight, 1.0f);
    glVertex3f(-1.0f, buildingHeight + spaceHeight, 1.0f); 
    glVertex3f(-1.0f, buildingHeight + spaceHeight, -1.0f); 
    glEnd();
}

void drawRoof() {
    // Front face
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f(-1.1f, buildingHeight + spaceHeight, 1.1f);
    glVertex3f(1.1f, buildingHeight + spaceHeight, 1.1f);
    glVertex3f(0.0f, buildingHeight + spaceHeight + 0.2f, 1.0f);
    glEnd();
    // Right face
    glBegin(GL_TRIANGLES);
    glVertex3f(1.1f, buildingHeight + spaceHeight, 1.1f);
    glVertex3f(1.1f, buildingHeight + spaceHeight, -1.1f);
    glVertex3f(0.0f, buildingHeight + spaceHeight + 0.2f, 0.0f);
    glEnd();
    // Back face
    glBegin(GL_TRIANGLES);
    glVertex3f(1.1f, buildingHeight + spaceHeight, -1.1f);
    glVertex3f(-1.1f, buildingHeight + spaceHeight, -1.1f);
    glVertex3f(0.0f, buildingHeight + spaceHeight + 0.2f, -1.0f);
    glEnd();
    // Left face
    glBegin(GL_TRIANGLES);
    glVertex3f(-1.1f, buildingHeight + spaceHeight, -1.1f);
    glVertex3f(-1.1f, buildingHeight + spaceHeight, 1.1f);
    glVertex3f(0.0f, buildingHeight + spaceHeight + 0.2f, 0.0f);
    glEnd();
    // Base
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-1.1f, buildingHeight + spaceHeight, 1.1f);
    glVertex3f(1.1f, buildingHeight + spaceHeight, 1.1f);
    glVertex3f(1.1f, buildingHeight + spaceHeight, -1.1f);
    glVertex3f(-1.1f, buildingHeight + spaceHeight, -1.1f);
    glEnd();
}


float doorAngle = 1.0f;

void drawDoor(float xOffset, float yOffset, float zOffset) {
    glPushMatrix();
    glTranslatef(-0.3f + xOffset, -1.0f + yOffset, 1.01f + zOffset); //translate to the hinge of the door
    glRotatef(-doorAngle, 0.0f, 1.0f, 0.0f); //rotate the door
    glTranslatef(0.3f, 2.0f, 0.0f); //translate back to the center of the door
    glColor3f(0.5f, 0.35f, 0.05f); //brown
    glBegin(GL_QUADS);
    glVertex3f(-0.3f, -1.0f, -0.01f); // Lower left
    glVertex3f(0.3f, -1.0f, -0.01f);  // Lower right
    glVertex3f(0.3f, 0.0f, -0.01f);    // Upper right
    glVertex3f(-0.3f, 0.0f, -0.01f);   // Upper left
    glEnd();
    glPopMatrix();
}


float windowAngle = 0.0f;

void drawWindow(float xOffset, float yOffset, float zOffset) {
    // Draw left part of the window
    glPushMatrix();
    glTranslatef(-0.2f + xOffset, 0.4f + yOffset, 1.01f + zOffset);     //translate to the hinge of the left part
    glRotatef(-windowAngle, 0.0f, 1.0f, 0.0f);  // Rotate left part of the window
    glTranslatef(0.2f, 0.0f, 0.0f);     //translate back to the center of the left part
    glColor3f(0.0f, 0.5f, 0.7f);    //light Blue
    glBegin(GL_QUADS);
    glVertex3f(-0.2f, -0.2f, 0.0f); // Lower left
    glVertex3f(0.0f, -0.2f, 0.0f);  // Lower right
    glVertex3f(0.0f, 0.2f, 0.0f);   // Upper right
    glVertex3f(-0.2f, 0.2f, 0.0f);  // Upper left
    glEnd();
    glPopMatrix();

    // Draw right part of the window
    glPushMatrix();
    glTranslatef(0.2f + xOffset, 0.4f + yOffset, 1.01f + zOffset);      //translate to the hinge of the right part
    glRotatef(windowAngle, 0.0f, 1.0f, 0.0f);   //rotate right part of the window
    glTranslatef(-0.2f, 0.0f, 0.0f);    //translate back to the center of the right part
    glColor3f(0.0f, 0.5f, 0.7f); 
    glBegin(GL_QUADS);
    glVertex3f(0.0f, -0.2f, 0.0f);  // Lower left
    glVertex3f(0.2f, -0.2f, 0.0f);   // Lower right
    glVertex3f(0.2f, 0.2f, 0.0f);    // Upper right
    glVertex3f(0.0f, 0.2f, 0.0f);   // Upper left
    glEnd();
    glPopMatrix();
}

void drawBelt() {
    glColor3f(0.3f, 0.3f, 0.3f); //dark Gray
    glBegin(GL_QUADS);
    // Front face
    glVertex3f(-1.0f, 0.82f, 1.02f); // Top left
    glVertex3f(1.0f, 0.82f, 1.02f);  // Top right
    glVertex3f(1.0f, 0.88f, 1.02f); // Bottom right
    glVertex3f(-1.0f, 0.88f, 1.02f); // Bottom left
    glEnd();

}

void drawBeltBack() {
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
    // Front face
    glVertex3f(-1.0f, 0.82f, -1.02f); // Top left
    glVertex3f(1.0f, 0.82f, -1.02f);  // Top right
    glVertex3f(1.0f, 0.88f, -1.02f); // Bottom right
    glVertex3f(-1.0f, 0.88f, -1.02f); // Bottom left
    glEnd();
}

void drawBeltRight() {
    glColor3f(0.3f, 0.3f, 0.3f); 
    glBegin(GL_QUADS);
    // Front face
    glVertex3f(1.02f, 0.82f, -1.0f); // Top left
    glVertex3f(1.02f, 0.82f, 1.0f);  // Top right
    glVertex3f(1.02f, 0.88f, 1.0f); // Bottom right
    glVertex3f(1.02f, 0.88f, -1.0f); // Bottom left
    glEnd();
}

void drawBeltLeft() {
    glColor3f(0.3f, 0.3f, 0.3f); 
    glBegin(GL_QUADS);
    // Front face
    glVertex3f(-1.02f, 0.82f, 1.0f); // Top left
    glVertex3f(-1.02f, 0.82f, -1.0f);  // Top right
    glVertex3f(-1.02f, 0.88f, -1.0f); // Bottom right
    glVertex3f(-1.02f, 0.88f, 1.0f); // Bottom left
    glEnd();
}


double movX = 0.0, movY = 3.0, movZ = 8.0; //initial camera position
double lX = 0.0, lY = 0.0; //initial look-at position

void Camera(double posX, double posY, double posZ, double lookAtX, double lookAtY, double lookAtZ) {
    gluLookAt(posX, posY, posZ, lookAtX, lookAtY, lookAtZ, 0.0, 1.0, 0.0);
}

void resetCamera(){
    movX = 0.0;
    movY = 3.0;
    movZ = 8.0;
    lX = 0.0;
    lY = 0.0;
}

float bikePosX = 0.0f;          
float bikePosZ = 0.0f;           
float bikeMoveSpeed = 0.1f;      //speed of bike movement
float angle = 0.0;



void drawWheel() {
    glColor3f(0.0, 0.0, 0.0); //black
    glPushMatrix();
    glTranslatef(0.0, 0.0, bikePosZ); //apply the translation based on bikePosZ
    glutSolidTorus(0.025, 0.3, 15, 30); //wheel with inner radius 0.025 and outer radius 0.3
    glPopMatrix();
}

void drawFrame() {
    glColor3f(0.0, 0.0, 0.0); //black

    //adjust the height to place the frame above the wheels
    float frameHeight = -0.2;

    glPushMatrix();
    glTranslatef(0.0, 0.0, bikePosZ); //apply the translation based on bikePosZ
    glBegin(GL_LINES);

    //bottom bracket to rear dropout
    glVertex3f(-0.5, frameHeight, 0.0);
    glVertex3f(0.0, frameHeight, 0.0);

    //seat tube
    glVertex3f(0.0, frameHeight, 0.0);
    glVertex3f(0.0, frameHeight + 0.2, 0.0);

    //seat stays
    glVertex3f(0.0, frameHeight, 0.0);
    glVertex3f(-0.1, frameHeight, 0.0);

    //fork
    glVertex3f(0.0, frameHeight, 0.0);
    glVertex3f(0.75, frameHeight, 0.0);

    //handlebar
    glVertex3f(0.75, frameHeight, 0.0);
    glVertex3f(0.75, frameHeight + 0.1, 0.0);

    glEnd();
    glPopMatrix(); // Restore the previous matrix
}


void drawSeat() {
    glColor3f(0.0, 0.0, 0.0); //black
    glPushMatrix();
    glTranslatef(0.0, 0.0, bikePosZ); //apply the translation based on bikePosZ
    glScalef(0.3, 0.04, 0.2); //scale for a smaller seat shape
    glutSolidCube(1.0); //draw a cube as the seat
    glPopMatrix();
}

void drawHandlebars() {
    glColor3f(0.0, 0.0, 0.0); //black

    glPushMatrix();
    glTranslatef(0.0, 0.0, bikePosZ); //apply the translation based on bikePosZ

    glBegin(GL_LINES);

    glVertex3f(0.75, -0.2, 0.0);
    glVertex3f(0.75, 0.35, 0.0);

    glVertex3f(0.75, 0.35, 0.0);
    glVertex3f(0.95, 0.35, 0.0);

    glVertex3f(0.75, 0.35, 0.0);
    glVertex3f(0.55, 0.35, 0.0);

    glEnd();
    glPopMatrix();
}

bool animationEnabled = false; //variable to control animation state
float rotationAngle = 0.0; //initial rotation angle

void mouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        animationEnabled = true; //enable animation on left mouse button click
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        animationEnabled = false; //disable animation on right mouse button click
    }
}

void update(int value) {
    if (animationEnabled) {
        rotationAngle += 0.5; 
        if (rotationAngle >= 360.0) {
            rotationAngle -= 360.0; // Reset rotation angle after completing one full rotation
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // Call update function again after 16 milliseconds
}



void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    //set background color to green
    glClearColor(0.0f, 0.5f, 0.0f, 1.0f);

    //set up camera
    Camera(movX, movY, movZ, lX, lY, 0.0);

    //draw first floor
    drawBuilding();

    //draw door
    drawDoor(0.0f, -1.0f, 0.0f);

    //draw dicoration belt
    drawBelt();
    drawBeltLeft();
    drawBeltRight();
    drawBeltBack();

    //draw windows on the first floor
    drawWindow(0.6f, -0.1f, 0.0f); //first window (moved further to the right)
    drawWindow(-0.6f, -0.1f, 0.0f); //second window (mirrored on the other side)

    //draw second floor
    glTranslatef(0.0f, 0.6f, 0.0f); //translate up for the second floor
    drawBuilding();

    //draw windows on the second floor
    drawWindow(0.6f, 0.5f, 0.0f); //third window (same side as first floor)
    drawWindow(-0.6f, 0.5f, 0.0f); //fourth window (opposite side)

    //draw roof
    drawRoof();


    //apply rotation transformation based on animation state
    if (animationEnabled) {
        glRotatef(rotationAngle, 0.0, 1.0, 0.0); //rotate around y-axis
    }

    glTranslatef(-0.5f, -0.5f, 4.0f); //move the bicycle in front of the building
    glTranslatef(bikePosX, 0.0f, 0.0f);

    glPushMatrix();
    glTranslatef(-0.5f, -0.5f, 0.0f);    //draw rear wheel
    drawWheel();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.75f, -0.5f, 0.0f);   //draw front wheel
    drawWheel();
    glPopMatrix();

    glPushMatrix();
    drawFrame();
    glPopMatrix();

    glPushMatrix();
    drawSeat();
    glPopMatrix();

    glPushMatrix();
    drawHandlebars();
    glPopMatrix();


    glutSwapBuffers();
}

void openDoor() {
    if (doorAngle < 90.0f) {
        doorAngle += 1.0f;

    }
}

void closeDoor() {
    if (doorAngle > 1.0f) {
        doorAngle -= 1.0f;
    }
}

void openWindows() {
    if (windowAngle < 180.0f) {
        windowAngle += 1.0f;
    }
}

void closeWindows() {
    if (windowAngle > 0.0f) {
        windowAngle -= 1.0f;
    }
}

void keyboard(unsigned char key, int x, int y) {

    double cameraSpeed = 0.1; 
    double rotationSpeed = 0.1;

    switch (key) {
    case 'o':
        openDoor();
        break;
    case 'c':
        closeDoor();
        break;
    case 'O':
        openWindows();
        break;
    case 'C':
        closeWindows();
        break;
    case 'w': //zoom in
        movX += cameraSpeed * (lX - movX);
        movY += cameraSpeed * (lY - movY);
        movZ += cameraSpeed * (-5.0 - movZ);
        break;
    case 's': //zoom out
        movX -= cameraSpeed * (lX - movX);
        movY -= cameraSpeed * (lY - movY);
        movZ -= cameraSpeed * (-5.0 - movZ);
        break;
    case 'a': //rotate left
    {
        double angle = rotationSpeed;
        double newX = (movX - lX) * cos(angle) - (movZ + 5.0) * sin(angle);
        double newZ = (movX - lX) * sin(angle) + (movZ + 5.0) * cos(angle);
        movX = newX + lX;
        movZ = newZ - 5.0;
    }
    break;
    case 'd': //rotate right
    {
        double angle = -rotationSpeed;
        double newX = (movX - lX) * cos(angle) - (movZ + 5.0) * sin(angle);
        double newZ = (movX - lX) * sin(angle) + (movZ + 5.0) * cos(angle);
        movX = newX + lX;
        movZ = newZ - 5.0;
    }
    break;
    case 'f': //move forward
        bikePosX += bikeMoveSpeed;
        break;
    case 'b': //move backward
        bikePosX -= bikeMoveSpeed;
        break;
    case 'r':
        bikePosZ += 0.1f; //move right
        break;
    case 'l':
        bikePosZ -= 0.1f; //move left
        break;
    case 'h': //reset camera
        resetCamera();
    default:
        break;
    }
    glutPostRedisplay();
}


void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Scene");
    glutKeyboardFunc(keyboard);
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouseClick);
    glutTimerFunc(16, update, 0);
    glutMainLoop();
    return 0;
}
