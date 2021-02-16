#include <stdio.h>
#include <stdlib.h>

#include <glut.h>

static void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // draw commands
    // ...

    glutSwapBuffers();
}

static void keyboard(unsigned char key, int x, int y) {
    printf("Pressed %c key\n", key);

    if(key == 'q') {
        exit(0);
    }
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    // Create a window with an OpenGL context
    glutCreateWindow("Glut Demo");

    // Print the default OpenGL context
    printf("OpenGL version = %s\n", glGetString(GL_VERSION));

    // Register GLUT callbacks
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    // Clear the screen with red
    glClearColor(1.0, 0.0, 0.0, 1.0);

    glutMainLoop();
}
