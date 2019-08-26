//
// Created by HDrmi on 8/26/2019.
//
#include <Windows.h>
#include <stdio.h>
#include "include/connection.h"
#include "include/queries.h"

int main() {
	connectDataBase();
	insert();
	printf("\nComplete.\n");
	disconnectDataBase();
	return 0;
}