/*
 * Copyright (C) 2018 Amlogic Corporation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *  DESCRIPTION:
 *      brief  Definitiond Of Audio Dec Types And Structures.
 *
 */

#ifndef ADEC_MESSAGE_H
#define ADEC_MESSAGE_H

#include <pthread.h>

ADEC_BEGIN_DECLS

#define MESSAGE_NUM_MAX    12

typedef enum {
    CMD_START = 1 << 0,
    CMD_PAUSE = 1 << 1,
    CMD_RESUME = 1 << 2,
    CMD_STOP = 1 << 3,
    CMD_MUTE = 1 << 4,
    CMD_SET_VOL = 1 << 5,
    CMD_GET_VOL = 1 << 6,
    CMD_CHANL_SWAP = 1 << 7,
    CMD_LEFT_MONO = 1 << 8,
    CMD_RIGHT_MONO = 1 << 9,
    CMD_STEREO = 1 << 10,
    CMD_SET_LRVOL = 1 << 20,
    CMD_RELEASE = 1 << 31,
} ctrl_cmd_t;


typedef struct {
    int type;               /* 1 = reply; 0 = no reply */
    int has_arg;         /* 1 = value is valid; 0 = value is unvalid */
    ctrl_cmd_t  ctrl_cmd;
    union {
        int en;
        float volume;
    } value;
    union {
        int en;
        float volume;
    } value_ext;
} adec_cmd_t;

typedef struct {
    adec_cmd_t * message_lise[MESSAGE_NUM_MAX + 1];
    int message_in_index;
    int message_out_index;
    int message_num;
    pthread_mutex_t msg_mutex;
} message_pool_t;

ADEC_END_DECLS

#endif
