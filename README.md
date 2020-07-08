# Persistent + Eresurecode Redis

## 0524两个问题
### 哈希表 key value 组织插入 dictEntry？？
### set命令 set同一个值，不应该累加，封装到dictEntry？？？


## 0608
### complete the question of ‘\0’
### complete the question of parity hash table


## 0708
### 将奇偶校验换成RS(3,2)

#### 完成1：添加RScode开源库Jerasure，修改Makefile
#### 完成2：7002的编码and更新

#### 待办1：添加另一个校验节点7003（只剩数据结点向7003的发送待修改）
#### 待办2：降级读，集群failed之后，由7002进行单个value的恢复
#### 待办3：全量恢复，由7002做恢复的leader，需要区分data node的value和7003的parity data