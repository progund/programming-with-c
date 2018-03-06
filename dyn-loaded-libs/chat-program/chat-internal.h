#ifndef CHAT_INTERNAL_H
#define CHAT_INTERNAL_H

#include "interface/chat.h"

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
 * @param hostname - name of the server to connect to
 * @param port - port number of the server to tonnect to
 * @return a pointer to the implementing software's own structure
 */
typedef void* (*chat_init_ptr)(const char *str, int port);

/** 
 * @brief Closes the chat session pointed to by the struct.
 *
 * This function closes the chat associated with the struct.
 *
 * @param data a pointer to the implementing software's own structure
 * @return void
 */
typedef void (*chat_close_ptr)(void *data);

/** 
 * @brief Start the chat
 *
 * This function starts up the chat client. It will listen for input
 * from user on stdin and provide feedback to the user via stdout.
 *
 * @param data a pointer to the implementing software's own structure
 * @return an integer idicating success (CHAT_CLIENT_OK e(0)) or error
 */
typedef int (*chat_loop_ptr)(void *data);


/** 
 * @brief Sets the feedback funtion used to give feedback to the user.
 *
 * You can change the built in printer (stdout) to any function you want.
 *
 * @param data a pointer to the implementing software's own structure
 * @param fun - a pointer to a function (input_handler - see above)
 * @return void
 */
typedef void (*chat_set_feedback_fun_ptr)(void *data, input_handler_ptr fun);


/** 
 * @brief handle user input
 *
 * This function either writes a message to the chat server or handles
 * internal commands:
 *  .quit - for leaving the chat session
 *
 * @param data a pointer to the implementing software's own structure
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


#endif /* CHAT_INTERNAL_H */
