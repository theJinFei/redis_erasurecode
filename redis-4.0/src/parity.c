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

# ifdef _ERASURE_CODE_

	# ifdef _IS_PARITY_
	#	include "parity.h"
	// 重新组织一个struct？

	// 开启校验，遍历上步处理的set参数，解析client中的argc argv命令
	dictEntry* doParity(client* c){
		dictEntry* entry;
		entry = zmalloc(sizeof(*entry));
		entry -> cnt = c -> argv[1] -> cnt; // 取 value 中的 cnt
		entry -> key = createObject(c -> argv[0]);
		entry -> value = createObject(c -> argv[1]);
		encodeParity(dic* d, entry -> cnt);

		return entry;
	}

	dictEntry* encodeParity(dictEntry* head, dictEntry* target){
		dictEntry* node = head;
		while(node){
			if(node -> cnt == target -> cnt){
				//将key，value分别做异或操作
				node -> key ^= target -> key;
				node -> val ^= target -> val;
				break;
			}
			node = node -> next;
		}
	}

	// 校验节点通知其他master进行恢复 
	// 通知的过程 flag // 表示这是编码还是解码以及恢复过程中的状态
	parityToMaster(){
		// 其实传一个flag表示这是传输数据的一个阶段，
		// cnt 传过去
		flag = 
		struct robj o = {flag, NULL, NULL};
		sendInputBuffer();
	}

	// 启动恢复这个过程
	// 其他的数据节点 都应该把指定cnt命令传给校验节点

    // 同组传输数据流程
    bool transformData(int cnt){
		dictEntry* repairentry;
		repairentry = zmalloc(sizeof(*repairentry));
		// 遍历此时的服务器，将数据发往校验节点
		/* Send it to parity. */
        // 遍历除了本身的
		dict* node = server.cluster.nodes; // name -> dict 	
		// 得到服务器的listDict
		for(auto& i : listDict){
			if(i != server.cluster.myserf){	// 除了自身故障的节点之外 myself
				dictEntry* entry = dictFind(i, value -> cnt); // i is a dict 
				assert(entry == NULL);
				// 需不需要做序列化？ 然后再做异或运算 直接entry做异或可靠吗？
				// 写缓冲区
				inputbuffer(tagetEntry);
			}
		}
		return true;
     }

	// 进行恢复
	void restoreData(){
		// 读取客户端的查询缓冲区内容
		readQueryFromClient
		// 进行重新异或就行
		
		obj* key
		obj* value
		// 把恢复好的数据传输过去 故障节点 flag 表示这是用于恢复的数据
	}
	# endif


	# ifdef _DATA_NODE_
		void readInputBuffer(){
			// 首先判断这个是flag
			// 去读修复后的数据
			processBuffer(repairentry);
			// 恢复数据
			dictAdd(d, repairyentry);
		}
	# endif

# endif