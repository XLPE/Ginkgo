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
 * /Claims/scheduler/serialized_scheduler.h
 *
 *  Created on: Oct 12, 2016
 *      Author: fzh
 *		   Email: fzhedu@gmail.com
 *
 * Description:
 *
 */

#ifndef SCHEDULER_SERIALIZED_SCHEDULER_H_
#define SCHEDULER_SERIALIZED_SCHEDULER_H_

#include "scheduler_base.h"

namespace claims {
namespace scheduler {
class SerializedScheduler : public scheduler::SchedulerBase {
 public:
  SerializedScheduler(PipelineJob* const dag_root, StmtExecStatus* exec_status);

  virtual ~SerializedScheduler();
  static void ScheduleJob(caf::event_based_actor* self,
                          SerializedScheduler* scheduler);
  void CreateActor();

 private:
  RetCode ComputeJobRank();
};
}  // namespace scheduler
}  // namespace claims

#endif  //  SCHEDULER_SERIALIZED_SCHEDULER_H_