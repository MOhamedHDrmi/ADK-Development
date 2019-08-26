//
// Created by HDrmi on 8/26/2019.
//
#include <string.h>
#include "connection.h"

#ifndef INITPROGRAM_QUERIES_H
#define INITPROGRAM_QUERIES_H

#define PARAM_ARRAY_SIZE 10

void insert() {
    // Statement handle
    SQLHSTMT hstmt = SQL_NULL_HSTMT;

    // query statement
    SQLCHAR *stmt = (SQLCHAR *) "INSERT INTO TestTBL1  (FirstName, LastName, Address, City)  VALUES (?,?,?,?)";

    // Arrays of data
    SQLCHAR ArrFirstNames[PARAM_ARRAY_SIZE][2] =
            {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
    SQLCHAR ArrLastNames[PARAM_ARRAY_SIZE][2] =
            {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
    SQLCHAR ArrAddress[PARAM_ARRAY_SIZE][2] =
            {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
    SQLCHAR ArrCity[PARAM_ARRAY_SIZE][2] =
            {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};

    SQLUSMALLINT ParamStatusArray[PARAM_ARRAY_SIZE];
    SQLLEN ParamsProcessed = 0;

    // Allocate statement handle.
    SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);

    // Set parameter set size, status array and params processed pointers
    SQLSetStmtAttr(hstmt, SQL_ATTR_PARAM_BIND_TYPE, SQL_PARAM_BIND_BY_COLUMN, 0);
    SQLSetStmtAttr(hstmt, SQL_ATTR_PARAMSET_SIZE, (SQLPOINTER) PARAM_ARRAY_SIZE, 0);
    SQLSetStmtAttr(hstmt, SQL_ATTR_PARAM_STATUS_PTR, ParamStatusArray, PARAM_ARRAY_SIZE);
    SQLSetStmtAttr(hstmt, SQL_ATTR_PARAMS_PROCESSED_PTR, &ParamsProcessed, 0);

    // Bind array values of parameters 1-4
    SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR,
                     SQL_VARCHAR, 2, 0, ArrFirstNames, 2, NULL);
    SQLBindParameter(hstmt, 2, SQL_PARAM_INPUT, SQL_C_CHAR,
                     SQL_VARCHAR, 2, 0, ArrLastNames, 2, NULL);
    SQLBindParameter(hstmt, 3, SQL_PARAM_INPUT, SQL_C_CHAR,
                     SQL_VARCHAR, 2, 0, ArrAddress, 2, NULL);
    SQLBindParameter(hstmt, 4, SQL_PARAM_INPUT, SQL_C_CHAR,
                     SQL_VARCHAR, 2, 0, ArrCity, 2, NULL);

    // execute stmt
    SQLExecDirect(hstmt, stmt, SQL_NTS);
}

#endif //INITPROGRAM_QUERIES_H
