//
// Created by HDrmi on 8/26/2019.
//
#include <stdio.h>
#include <sql.h>
#include <sqlext.h>

#ifndef INITPROGRAM_CONNECTION_H
#define INITPROGRAM_CONNECTION_H

SQLCHAR *dataSource = (SQLCHAR *) "DSN=odbcTest;"; //data source configure in odbc driver
SQLHENV henv = SQL_NULL_HENV;   // Environment
SQLHDBC hdbc = SQL_NULL_HDBC;   // Connection

void connectDataBase() {
    // Allocate the ODBC environment and save handle.
    SQLAllocHandle(SQL_HANDLE_ENV, NULL, &henv);

    // Notify ODBC that this is an ODBC 3.0 app.
    SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER) SQL_OV_ODBC3, 0);

    // Allocate ODBC connection handle and connect.
    SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);

    // Connect to DATASOURCE
    SQLDriverConnect(hdbc, NULL, dataSource, SQL_NTS, NULL, 0, NULL, SQL_DRIVER_COMPLETE);
}

void disconnectDataBase() {
    // Free handles
    // Connection
    if (hdbc != SQL_NULL_HDBC) {
        SQLDisconnect(hdbc);
        SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
    }

    // Environment
    if (henv != SQL_NULL_HENV)
        SQLFreeHandle(SQL_HANDLE_ENV, henv);
}

#endif //INITPROGRAM_CONNECTION_H
