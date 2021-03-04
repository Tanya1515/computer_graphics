#include "common.h"
#include "Image.h"
#include "Player.h"
#include "labyrinth.h"
#include "unistd.h"

#define GLFW_DLL
#include <GLFW/glfw3.h>

constexpr GLsizei WINDOW_WIDTH = 1024, WINDOW_HEIGHT = 1024;

struct InputState
{
  bool keys[1024]{};                //массив состояний кнопок - нажата/не нажата
  GLfloat lastX = 400, lastY = 300; //исходное положение мыши
  bool firstMouse = true;
  bool captureMouse = true; // Мышка захвачена нашим приложением или нет?
  bool capturedMouseJustNow = false;
} static Input;

GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;

void OnKeyboardPressed(GLFWwindow *window, int key, int scancode, int action, int mode)
{
  switch (key)
  {
  case GLFW_KEY_ESCAPE:
    if (action == GLFW_PRESS)
      glfwSetWindowShouldClose(window, GL_TRUE);
    break;
  case GLFW_KEY_1:
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    break;
  case GLFW_KEY_2:
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    break;
  default:
    if (action == GLFW_PRESS)
      Input.keys[key] = true;
    else if (action == GLFW_RELEASE)
      Input.keys[key] = false;
  }
}

// движение объекта и кнопки на клавиатуре
int processPlayerMovement(Player &player, Image &screen)
{
  if (Input.keys[GLFW_KEY_W])
    return player.ProcessInput(MovementDir::UP, screen);
  else if (Input.keys[GLFW_KEY_S])
    return player.ProcessInput(MovementDir::DOWN, screen);
  if (Input.keys[GLFW_KEY_A])
    return player.ProcessInput(MovementDir::LEFT, screen);
  else if (Input.keys[GLFW_KEY_D])
    return player.ProcessInput(MovementDir::RIGHT, screen);
}

// движения мышки, если правая кнопка - курсор пропадает, если левая - появляется
void OnMouseButtonClicked(GLFWwindow *window, int button, int action, int mods)
{
  if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
    Input.captureMouse = !Input.captureMouse;

  if (Input.captureMouse)
  {
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    Input.capturedMouseJustNow = true;
  }
  else
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

void OnMouseMove(GLFWwindow *window, double xpos, double ypos)
{
  if (Input.firstMouse)
  {
    Input.lastX = float(xpos);
    Input.lastY = float(ypos);
    Input.firstMouse = false;
  }

  GLfloat xoffset = float(xpos) - Input.lastX;
  GLfloat yoffset = Input.lastY - float(ypos);

  Input.lastX = float(xpos);
  Input.lastY = float(ypos);
}

Point Lab_A(char letter, FILE *fp, Image &screenBuffer)
{
  int i = 0;
  int j = 0;
  Point starting_pos_player{.x = i * 54, .y = j * 32};
  Point_s starting_pos_s{.x = i * 54, .y = j * 32};
  for (int j = 0; j < 32; j++)
  {
    for (int i = 0; i < 19; i++)
    {
      if (letter == '.')
      {
        starting_pos_s = {.x = i * 54, .y = j * 32};
        Path_1 path{starting_pos_s};
        path.Draw(screenBuffer);
      }
      if (letter == '#')
      {
        starting_pos_s = {.x = i * 54, .y = j * 32};
        Wall_1 wall{starting_pos_s};
        wall.Draw(screenBuffer);
      }
      if (letter == 'x')
      {
        starting_pos_s = {.x = i * 54, .y = j * 32};
        Door door{starting_pos_s};
        door.Draw(screenBuffer);
      }
      if (letter == '*')
      {
        starting_pos_s = {.x = i * 54, .y = j * 32};
        Bush_1 bush{starting_pos_s};
        bush.Draw(screenBuffer);
      }
      if (letter == ' ')
      {
        starting_pos_s = {.x = i * 54, .y = j * 32};
        nothing no{starting_pos_s};
        no.Draw(screenBuffer);
      }
      if (letter == '@')
      {
        starting_pos_s = {.x = i * 54, .y = j * 32};
        Path_1 path{starting_pos_s};
        path.Draw(screenBuffer);
        starting_pos_player = {.x = i * 54, .y = j * 32};
      }
      if (letter == 'Q')
      {
        starting_pos_s = {.x = i * 54, .y = j * 32};
        end door{starting_pos_s};
        door.Draw(screenBuffer);
      }
      letter = fgetc(fp);
    }
    letter = fgetc(fp);
  }
  return starting_pos_player;
}

Point Lab_B(char letter, FILE *fp, Image &screenBuffer)
{
  int i = 0;
  int j = 0;
  Point starting_pos_player{.x = i * 54, .y = j * 32};
  Point_s starting_pos_s{.x = i * 54, .y = j * 32};
  for (int j = 0; j < 32; j++)
  {
    for (int i = 0; i < 19; i++)
    {

      if (letter == '.')
      {
        starting_pos_s = {.x = i * 54, .y = j * 32};
        Path_2 path{starting_pos_s};
        path.Draw(screenBuffer);
      }
      if (letter == '#')
      {
        starting_pos_s = {.x = i * 54, .y = j * 32};
        Wall_2 wall{starting_pos_s};
        wall.Draw(screenBuffer);
      }
      if (letter == 'x')
      {
        starting_pos_s = {.x = i * 54, .y = j * 32};
        Door door{starting_pos_s};
        door.Draw(screenBuffer);
      }
      if (letter == '*')
      {
        starting_pos_s = {.x = i * 54, .y = j * 32};
        Bush_2 bush{starting_pos_s};
        bush.Draw(screenBuffer);
      }
      if (letter == ' ')
      {
        starting_pos_s = {.x = i * 54, .y = j * 32};
        nothing no{starting_pos_s};
        no.Draw(screenBuffer);
      }
      if (letter == '@')
      {
        starting_pos_s = {.x = i * 54, .y = j * 32};
        Path_2 path{starting_pos_s};
        path.Draw(screenBuffer);
        starting_pos_player = {.x = i * 54, .y = j * 32};
      }
      if (letter == 'Q')
      {
        starting_pos_s = {.x = i * 54, .y = j * 32};
        end door{starting_pos_s};
        door.Draw(screenBuffer);
      }
      letter = fgetc(fp);
    }
    letter = fgetc(fp);
  }
  return starting_pos_player;
}

Point Lab_C(char letter, FILE *fp, Image &screenBuffer)
{
  int i = 0;
  int j = 0;
  Point starting_pos_player{.x = i * 54, .y = j * 32};
  Point_s starting_pos_s{.x = i * 54, .y = j * 32};
  for (int j = 0; j < 32; j++)
  {
    for (int i = 0; i < 19; i++)
    {
      if (letter == '.')
      {
        starting_pos_s = {.x = i * 54, .y = j * 32};
        Path_3 path{starting_pos_s};
        path.Draw(screenBuffer);
      }
      if (letter == '#')
      {
        starting_pos_s = {.x = i * 54, .y = j * 32};
        Wall_3 wall{starting_pos_s};
        wall.Draw(screenBuffer);
      }
      if (letter == '*')
      {
        starting_pos_s = {.x = i * 54, .y = j * 32};
        Bush_3 bush{starting_pos_s};
        bush.Draw(screenBuffer);
      }
      if (letter == 'x')
      {
        starting_pos_s = {.x = i * 54, .y = j * 32};
        Door door{starting_pos_s};
        door.Draw(screenBuffer);
      }
      if (letter == ' ')
      {
        starting_pos_s = {.x = i * 54, .y = j * 32};
        nothing no{starting_pos_s};
        no.Draw(screenBuffer);
      }
      if (letter == '@')
      {
        starting_pos_s = {.x = i * 54, .y = j * 32};
        Path_3 path{starting_pos_s};
        path.Draw(screenBuffer);
        starting_pos_player = {.x = i * 54, .y = j * 32};
      }
      if (letter == 'Q')
      {
        starting_pos_s = {.x = i * 54, .y = j * 32};
        end door{starting_pos_s};
        door.Draw(screenBuffer);
      }
      letter = fgetc(fp);
    }
    letter = fgetc(fp);
  }
  return starting_pos_player;
}

Point Lab_D(char letter, FILE *fp, Image &screenBuffer)
{
  int i = 0;
  int j = 0;
  Point starting_pos_player{.x = i * 54, .y = j * 32};
  Point_s starting_pos_s{.x = i * 54, .y = j * 32};
  for (int j = 0; j < 32; j++)
  {
    for (int i = 0; i < 19; i++)
    {
      if (letter == '.')
      {
        starting_pos_s = {.x = i * 54, .y = j * 32};
        Path_4 path{starting_pos_s};
        path.Draw(screenBuffer);
      }
      if (letter == '#')
      {
        starting_pos_s = {.x = i * 54, .y = j * 32};
        Wall_4 wall{starting_pos_s};
        wall.Draw(screenBuffer);
      }
      if (letter == 'x')
      {
        starting_pos_s = {.x = i * 54, .y = j * 32};
        Door door{starting_pos_s};
        door.Draw(screenBuffer);
      }
      if (letter == '*')
      {
        starting_pos_s = {.x = i * 54, .y = j * 32};
        Bush_4 bush{starting_pos_s};
        bush.Draw(screenBuffer);
      }
      if (letter == ' ')
      {
        starting_pos_s = {.x = i * 54, .y = j * 32};
        nothing no{starting_pos_s};
        no.Draw(screenBuffer);
      }
      if (letter == '@')
      {
        starting_pos_s = {.x = i * 54, .y = j * 32};
        Path_4 path{starting_pos_s};
        path.Draw(screenBuffer);
        starting_pos_player = {.x = i * 54, .y = j * 32};
      }
      if (letter == 'Q')
      {
        starting_pos_s = {.x = i * 54, .y = j * 32};
        end door{starting_pos_s};
        door.Draw(screenBuffer);
      }
      letter = fgetc(fp);
    }
    letter = fgetc(fp);
  }
  return starting_pos_player;
}

Point Draw_Lab(char letter, char check, FILE *fp, Image &screenBuffer)
{
  screenBuffer.ScreenType();
  Point starting_pos_player;
  if (check == 'A')
    starting_pos_player = Lab_A(letter, fp, screenBuffer);
  if (check == 'B')
    starting_pos_player = Lab_B(letter, fp, screenBuffer);
  if (check == 'C')
    starting_pos_player = Lab_C(letter, fp, screenBuffer);
  if (check == 'D')
    starting_pos_player = Lab_D(letter, fp, screenBuffer);
  screenBuffer.ScreenSave();
  return starting_pos_player;
}

void OnMouseScroll(GLFWwindow *window, double xoffset, double yoffset)
{
  // ...
}

int initGL()
{
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cout << "Failed to initialize OpenGL context" << std::endl;
    return -1;
  }

  std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
  std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
  std::cout << "Version: " << glGetString(GL_VERSION) << std::endl;
  std::cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

  std::cout << "Controls: " << std::endl;
  std::cout << "press right mouse button to capture/release mouse cursor  " << std::endl;
  std::cout << "W, A, S, D - movement  " << std::endl;
  std::cout << "press ESC to exit" << std::endl;

  return 0;
}

FILE *file_open(char *name)
{
  FILE *fp;
  fp = fopen(name, "r+");
  return fp;
}

int main(int argc, char **argv)
{
  FILE *fp = file_open("room1");
  char check = 'A';
  char letter = fgetc(fp);
  int amount_rooms = 1;
  //инициализация GLFW
  if (!glfwInit())
    return -1;
  // настройка GLFW, 1ый аргумент - параметр, который будет меняться
  // 2ой - значение измменяемого параметра
  //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  // создание объекта окна
  GLFWwindow *window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "task1 base project", nullptr, nullptr);
  if (window == nullptr)
  {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  // контекст окна
  glfwMakeContextCurrent(window);

  glfwSetKeyCallback(window, OnKeyboardPressed);
  glfwSetCursorPosCallback(window, OnMouseMove);
  glfwSetMouseButtonCallback(window, OnMouseButtonClicked);
  glfwSetScrollCallback(window, OnMouseScroll);

  if (initGL() != 0)
    return -1;

  //Reset any OpenGL errors which could be present for some reason
  GLenum gl_error = glGetError();
  while (gl_error != GL_NO_ERROR)
    gl_error = glGetError();
  Image img("../resources/tex.png");
  Image screenBuffer(WINDOW_WIDTH, WINDOW_HEIGHT, 4);
  Point starting_pos_player;
  screenBuffer.ScreenType();
  Player player{Draw_Lab(letter, check, fp, screenBuffer)};
  glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
  GL_CHECK_ERRORS;
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  GL_CHECK_ERRORS;
  int check_game_over = 0;
  Point_s starting_pose_game;
  float zaya = 0;
  //game loop
  while (!glfwWindowShouldClose(window))
  {
    if (zaya >= 1)
      zaya = 0;
    GLfloat currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    // проверяем события и вызыываем функции обратного вызова
    glfwPollEvents();
    // команды отрисовки

    zaya = zaya + deltaTime;
    check_game_over = processPlayerMovement(player, screenBuffer);
    if ((check_game_over == 2) || (check_game_over == 5))
    {
      starting_pose_game = {250, 400};
      game_over game{starting_pose_game};
      game.Draw(screenBuffer);
    }

    if (check_game_over == 3)
    {
      starting_pose_game = {270, 400};
      win game{starting_pose_game};
      game.Draw(screenBuffer);
    }
    if (check_game_over == 4)
    {
      for (int j = 0; j < 32; j++)
      {
        for (int i = 0; i < 19; i++)
        {
          // starting_pose_game = {.x = i * 54, .y = j * 32};
          // nothing no{starting_pose_game};
          // no.Draw(screenBuffer);
        }
      }
      amount_rooms = amount_rooms + 1;
      if (amount_rooms == 20)
      {
        //player.move_speed = 0;
        check = 'A';
        FILE *fp = file_open("room5");
        letter = fgetc(fp);
        starting_pos_player = Draw_Lab(letter, check, fp, screenBuffer);
        Player player{starting_pos_player};
        player.move_speed = 4;
      }
      if (amount_rooms % 4 == 1)
      {
        //player.move_speed = 0;
        check = 'A';
        FILE *fp = file_open("room1");
        letter = fgetc(fp);
        starting_pos_player = Draw_Lab(letter, check, fp, screenBuffer);
        Player player{starting_pos_player};
        player.move_speed = 4;
      }
      if (amount_rooms % 4 == 2)
      {
        //player.move_speed = 0;x
        check = 'B';
        FILE *fp = file_open("room2");
        letter = fgetc(fp);
        starting_pos_player = Draw_Lab(letter, check, fp, screenBuffer);
        Player player{starting_pos_player};

        player.move_speed = 4;
      }
      if (amount_rooms % 4 == 3)
      {
        //player.move_speed = 0;
        check = 'C';
        FILE *fp = file_open("room3");
        letter = fgetc(fp);
        starting_pos_player = Draw_Lab(letter, check, fp, screenBuffer);
        Player player{starting_pos_player};

        player.move_speed = 4;
      }
      if ((amount_rooms % 4 == 0) && (amount_rooms != 20))
      {
        //player.move_speed = 0;
        check = 'D';
        FILE *fp = file_open("room4");
        letter = fgetc(fp);
        starting_pos_player = Draw_Lab(letter, check, fp, screenBuffer);

        Player player{starting_pos_player};

        player.move_speed = 4;
      }
    }

    player.Draw(screenBuffer, zaya);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    GL_CHECK_ERRORS;
    glDrawPixels(WINDOW_WIDTH, WINDOW_HEIGHT, GL_RGBA, GL_UNSIGNED_BYTE, screenBuffer.Data());
    GL_CHECK_ERRORS;

    // меняем буферы местами

    glfwSwapBuffers(window);
    if ((check_game_over == 2) || (check_game_over == 3) || (check_game_over == 5))
    {
      sleep(5);
      break;
    }
  }
  fclose(fp);
  glfwTerminate();
  return 0;
}
