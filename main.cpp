#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

using namespace std;


static void error_callback(int error, const char* description) {
  cout << "Error " << error << " : " << description << endl;
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GL_TRUE);
}

int main() {
  // glfwSetErrorCallback(error_callback);

  // Inititalization
  if (!glfwInit()) {
    cout << "Could not load GLFW." << endl;
    exit(1);
  }
  cout << "GLFW loaded." << endl;

  // Create a window
  GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
  if (!window) {
     cout << "Could not create the window." << endl;
    glfwTerminate();
    exit(1);
  }
  cout << "Window created." << endl;

  // OpenGL context
  glfwMakeContextCurrent(window);
  cout << "OpenGL context created." << endl;

  const GLubyte* renderer = glGetString(GL_RENDERER);
  const GLubyte* version = glGetString(GL_VERSION);
  cout << "Renderer: " << renderer << endl;
  cout << "OpenGL version supported: " << version << endl;

  //start GLEW extension handler
  //glewExperimental = GL_TRUE;
  //glewInit();
  //get version info

  glfwSetKeyCallback(window, key_callback);

  // Main loop
  while (!glfwWindowShouldClose(window)) {
    float ratio;
    int width, height;

    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float) height;

    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);

    glBegin(GL_TRIANGLES);
    glColor3f(1.f, 0.f, 0.f);
    glVertex3f(-0.6f, -0.4f, 0.f);
    glColor3f(0.f, 1.f, 0.f);
    glVertex3f(0.6f, -0.4f, 0.f);
    glColor3f(0.f, 0.f, 1.f);
    glVertex3f(0.f, 0.6f, 0.f);
    glEnd();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // Termination
  glfwDestroyWindow(window);
  glfwTerminate();

  exit(0);
}
