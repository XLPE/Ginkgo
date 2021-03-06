/*
 * Copyright [2012-2015] DaSE@ECNU
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * /CMySQL/mysql_result_set.h
 *
 *  Created on: Oct 14, 2015
 *      Author: chenlingyun,yukai
 *       Email: geekchenlingyun@outlook.com
 *
 * Description:
 *
 */

#include "../mysql/packet/mysql_row_packet.h"

namespace claims {
namespace mysql {
MysqlRowPacket::MysqlRowPacket(){

}
MysqlRowPacket::MysqlRowPacket(MysqlRow* row) {
	row_ = row;
}
int MysqlRowPacket::serialize(char* buffer, int64_t length, int64_t& pos) {
	return row_->serialize(buffer, length, pos);
}
int MysqlRowPacket::setRow(const char* content) {

	void* value = malloc(sizeof(char)*20);

	row_->schema_->columns[0].operate->toValue(value,content);
}
uint64_t MysqlRowPacket::get_serialize_size() {
	return 0;
}
}  // namespace mysql
}  // namespace claims
