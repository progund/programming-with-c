#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

/**
 * @file chat.h
 * @author Henrik Sandklef, Rikard Fröberg
 * @date 1 March 2018
 */

/**
 * @brief Return values
 *
 * Return values used by the chat API.
 */
enum
  {
    CHAT_CLIENT_OK,
    CHAT_CLIENT_BAD_ARG,
    CHAT_CLIENT_SETUP_FAILED,
    CHAT_CLIENT_COULD_NOT_OPEN_SOCKET,
    CHAT_CLIENT_ERROR,
    CHAT_CLIENT_LEAVE
  };

/**
 * @brief Function pointer for feedback
 *
 * Function pointer for feedback. You can make the chat API feedback
 * your code by registering a function using.
 */
typedef int (*input_handler_ptr)(const char *str, void *cc);


/** 
 * @brief Initialise the struct with hostname and port number.
 *
 * This function sets up the struct, using hostname and port number. 
 *
 * @param cc - a pointer to chat_client
 * @param hostname - name of the server to connect to
 * @param port - port number of the server to tonnect to
 * @return an integer idicating success (CHAT_CLIENT_OK e(0)) or error
 */
typedef void* (*chat_init_ptr)(const char *str, int port);

/** 
 * @brief Closes the chat session pointed to by the struct.
 *
 * This function closes the chat associated with the struct.
 *
 * @param cc - a pointer to chat_client
 * @return void
 */
typedef void (*chat_close_ptr)(void *data);

/** 
 * @brief Start the chat
 *
 * This function starts up the chat client. It will listen for input
 * from user on stdin and provide feedback to the user via stdout.
 *
 * @param cc - a pointer to chat_client
 * @return an integer idicating success (CHAT_CLIENT_OK e(0)) or error
 */
typedef int (*chat_loop_ptr)(void *data);


/** 
 * @brief Sets the feedback funtion used to give feedback to the user.
 *
 * You can change the built in printer (stdout) to any function you want.
 *
 * @param cc - a pointer to chat_client
 * @param fun - a pointer to a function (input_handler - see above)
 * @return void
 */
typedef void (*chat_set_feedback_fun_ptr)(void *data, input_handler_ptr fun);


/** 
 * @brief handke user input
 *
 * This function either writes a message to the chat server or handles
 * internal commands:
 *  .quit - for leaving the chat session
 *
 * @param cc - a pointer to chat_client
 * @param msg - string to handle
 * @return an integer idicating success (CHAT_CLIENT_OK e(0)) or error
 */
typedef int (*chat_handle_input_ptr)(void *data, char *msg);

typedef struct _chat_functions {
  input_handler_ptr input_handler;
  chat_init_ptr chat_init;
  chat_close_ptr chat_close;
  chat_handle_input_ptr chat_handle_input;
  chat_set_feedback_fun_ptr chat_set_feedback_fun;
  chat_loop_ptr chat_loop;
} chat_functions;
