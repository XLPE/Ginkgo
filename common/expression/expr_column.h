/*
 * expr_column.h
 *  Created on: May 30, 2015
 *      Author: fzh
 *       Email: fzhedu@gmail.com
 *   Copyright: Copyright (c) @ ECNU.DaSE
 * Description:
 */

#ifndef COMMON_EXPRESSION_EXPR_COLUMN_H_
#define COMMON_EXPRESSION_EXPR_COLUMN_H_

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include "../../common/Schema/Schema.h"
#include "./expr_type_cast.h"
#include "./expr_node.h"

class ExprColumn : public ExprNode {
 public:
    int attr_id_;
    std::string table_name_;
    std::string column_name_;
    int table_id_;
    ExprColumn(ExprNodeType expr_node_type, data_type actual_type,
               const char* alias, const char* table_name,
               const char* column_name);
    explicit ExprColumn(ExprColumn* expr_column);
    ~ExprColumn() {
    }
    void* ExprEvaluate(void *tuple, Schema *schema);
    void InitExprAtLogicalPlan(data_type return_type,
                               const std::map<std::string, int>&column_index,
                               Schema* schema);
    void InitExprAtPhysicalPlan();
    ExprNode* ExprCoyp();

 private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(const Archive &ar, const unsigned int version) {
        ar & boost::serialization::base_object<ExprNode>(*this) & table_name_
                & column_name_;
    }
};
#endif /* COMMON_EXPRESSION_EXPR_COLUMN_H_ */
