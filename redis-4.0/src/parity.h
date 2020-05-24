/*
 * Copyright (c) 2017, Andreas Bluemle <andreas dot bluemle at itxperts dot de>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of Redis nor the names of its contributors may be used
 *     to endorse or promote products derived from this software without
 *     specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __PARITY_H
#define __PARITY_H

#include "server.h"
#include "dict.h"


# ifdef _ERASURE_CODE_

# define PARITY_NORMAL_PROCESS 0   // 正常过程

// ENCODE
# define PARITY_READ_BUFFER_AND_ENCODE 1   // 编码过程

# define PARITY_READ_BUFFER_AND_UPDATE 2

// DECODE
# define PARITY_NOTIFY_DATANODE 3   // 校验节点 通知其他数据节点 启动恢复
# define PARIYT_DATANODE_TRANSFORM_DATA 4  // 数据节点 收到这个标志 表示要传输特定位置的数据
# define PARIYT_READ_BUFFER_AND_DECODE 5 // 校验节点 收到标志 表示读缓冲区 进行解码

// 传输给故障节点
# define PARITY_TRANFORM_GOOD_DATA 6   // 校验节点传输恢复好的数据 然后故障节点进行重新读缓冲区即可

# endif

// 函数声明
// dictEntry* doParity(client* c);
// dictEntry* encodeParity(dictEntry* head, dictEntry* target);



#endif
