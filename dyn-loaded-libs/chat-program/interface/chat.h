#ifndef CHAT_H
#define CHAT_H

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
    CHAT_CLIENT_COULD_NOT_OPEN_CHANNEL,
    CHAT_CLIENT_ERROR,
    CHAT_CLIENT_LEAVE
  };

#endif /* CHAT_H */
