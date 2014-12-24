/**
 * spaintgui: Application.h
 */

#ifndef H_SPAINTGUI_APPLICATION
#define H_SPAINTGUI_APPLICATION

#include <SDL.h>

#include <spaint/SpaintEngine.h>
#include <spaint/input/InputState.h>

#include "Renderer.h"

/**
 * \brief The main application class for spaintgui.
 */
class Application
{
  //#################### TYPEDEFS ####################
private:
  typedef boost::shared_ptr<Renderer> Renderer_Ptr;

  //#################### PRIVATE VARIABLES ####################
private:
  /** The current state of the keyboard and mouse. */
  spaint::InputState m_inputState;

  /** The current renderer. */
  Renderer_Ptr m_renderer;

  /** The spaint engine that the application should use. */
  spaint::SpaintEngine_Ptr m_spaintEngine;

  //#################### CONSTRUCTORS ####################
public:
  /**
   * \brief Constructs the application.
   *
   * \param spaintEngine The spaint engine that the application should use.
   */
  explicit Application(const spaint::SpaintEngine_Ptr& spaintEngine);

  //#################### PUBLIC MEMBER FUNCTIONS ####################
public:
  /**
   * \brief Runs the application.
   */
  void run();

  //#################### PRIVATE MEMBER FUNCTIONS ####################
private:
  /**
   * \brief Handle key down events.
   *
   * \param keysym  A representation of the key that has been pressed.
   */
  void handle_key_down(const SDL_Keysym& keysym);

  /**
   * \brief Handle key up events.
   *
   * \param keysym  A representation of the key that has been released.
   */
  void handle_key_up(const SDL_Keysym& keysym);

  /**
   * \brief Handle mouse button down events.
   *
   * \param e   The mouse button down event.
   */
  void handle_mousebutton_down(const SDL_MouseButtonEvent& e);

  /**
   * \brief Handle mouse button up events.
   *
   * \param e   The mouse button up event.
   */
  void handle_mousebutton_up(const SDL_MouseButtonEvent& e);

  /**
   * \brief Processes any SDL events (e.g. those generated by user input).
   *
   * \return true, if the application should continue running, or false otherwise.
   */
  bool process_events();

  /**
   * \brief Takes action as relevant based on the current input state.
   */
  void process_input();
};

#endif
