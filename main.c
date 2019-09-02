//
// Created by HDrmi on 8/26/2019.
//
#include <Windows.h>
#include <stdio.h>
#include "include/connection.h"
#include "include/TestTBL1.h"

int main() {
    connectDataBase();
    printf("\nComplete.\n");
    disconnectDataBase();
    return 0;
}