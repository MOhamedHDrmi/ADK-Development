//
// Created by HDrmi on 8/26/2019.
//
#include <string.h>
#include "connection.h"

#ifndef INITPROGRAM_QUERIES_H
#define INITPROGRAM_QUERIES_H

#define FIRSTNAME_LEN 256
#define LASTNAME_LEN 256
#define ADDRESS_LEN 256
#define CITY_LEN 256

void TestTBL1Save(char* FirstName, char* LastName, char* Address, char* City) {

    // Statement handle
    SQLHSTMT hstmt = SQL_NULL_HSTMT;

    // query statement
    SQLCHAR *stmt = (SQLCHAR *) "INSERT INTO TestTBL1  (FirstName, LastName, Address, City)  VALUES (?,?,?,?)";

    // Allocate statement handle.
    // hdbc declare in connection.h
    SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);

    // Bind array values of parameters 1-4
    SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR,
                     SQL_VARCHAR, 2, 0, FirstName, 2, NULL);
    SQLBindParameter(hstmt, 2, SQL_PARAM_INPUT, SQL_C_CHAR,
                     SQL_VARCHAR, 2, 0, LastName, 2, NULL);
    SQLBindParameter(hstmt, 3, SQL_PARAM_INPUT, SQL_C_CHAR,
                     SQL_VARCHAR, 2, 0, Address, 2, NULL);
    SQLBindParameter(hstmt, 4, SQL_PARAM_INPUT, SQL_C_CHAR,
                     SQL_VARCHAR, 2, 0, City, 2, NULL);

    // execute stmt
    SQLExecDirect(hstmt, stmt, SQL_NTS);
}

void TestTBL1Update(char* conditionValue, char* FirstName, char* LastName, char* Address, char* City) {

    // Statement handle
    SQLHSTMT hstmt = SQL_NULL_HSTMT;

    // query statement
    SQLCHAR *stmt = (SQLCHAR *) "UPDATE TestTBL1  SET FirstName=?, LastName=?, [Address]=?, City=? WHERE FirstName=?";

    // Allocate statement handle.
    // hdbc declare in connection.h
    SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);

    // Bind array values of parameters 1-4
    SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR,
                     SQL_VARCHAR, 2, 0, FirstName, 2, NULL);
    SQLBindParameter(hstmt, 2, SQL_PARAM_INPUT, SQL_C_CHAR,
                     SQL_VARCHAR, 2, 0, LastName, 2, NULL);
    SQLBindParameter(hstmt, 3, SQL_PARAM_INPUT, SQL_C_CHAR,
                     SQL_VARCHAR, 2, 0, Address, 2, NULL);
    SQLBindParameter(hstmt, 4, SQL_PARAM_INPUT, SQL_C_CHAR,
                     SQL_VARCHAR, 2, 0, City, 2, NULL);
    SQLBindParameter(hstmt, 5, SQL_PARAM_INPUT, SQL_C_CHAR,
                     SQL_VARCHAR, 2, 0, conditionValue, 2, NULL);

    // execute stmt
    SQLExecDirect(hstmt, stmt, SQL_NTS);
}

void TestTBL1Get(){

    // Statement handle
    SQLHSTMT hstmt = SQL_NULL_HSTMT;

    // Select statement to return person details from TestTBL2
    SQLCHAR	*stmt = (SQLCHAR*)"SELECT FirstName, LastName, Address, City FROM TestTBL1";

    // Allocate statement handle.
    // hdbc declare in connection.h
    SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);

    // Column binding variables
    SQLCHAR     FirstName [FIRSTNAME_LEN];
    SQLLEN      FirstName_l;
    SQLCHAR     LastName [LASTNAME_LEN];
    SQLLEN      LastName_l;
    SQLCHAR     Address [ADDRESS_LEN];
    SQLLEN      Address_l;
    SQLCHAR     City [CITY_LEN];
    SQLLEN      City_l;

    // Bind columns 1-4
    SQLBindCol(hstmt, 1, SQL_C_CHAR,   FirstName, FIRSTNAME_LEN, &FirstName_l);
    SQLBindCol(hstmt, 2, SQL_C_CHAR,   LastName, LASTNAME_LEN,  &LastName_l);
    SQLBindCol(hstmt, 3, SQL_C_CHAR,   Address, ADDRESS_LEN,   &Address_l);
    SQLBindCol(hstmt, 4, SQL_C_CHAR,   City, CITY_LEN,      &City_l);

    // execute stmt
    SQLExecDirect (hstmt, stmt, SQL_NTS);

    do {
        SQLRETURN retcode=SQL_SUCCESS;
        while (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
            retcode = SQLFetch (hstmt);
            if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
                printf ("\n  - %.10s %.10s %.10s %.10s",
                        FirstName, LastName, Address, City);
            }
        }
        // We would expect to finish with a status of SQL_NO_DATA
        if (retcode != SQL_NO_DATA) {
            printf("NO DATA");
        }
    } while (SQLMoreResults(hstmt) == SQL_SUCCESS);

}

#endif //INITPROGRAM_QUERIES_H