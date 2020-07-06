#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>

#pragma warning(disable : 4996)

#define MAX 100

using namespace std;

struct FL {
	char from[20];
	char to[20];
	int distance;
	char skip;
};

struct stack {
	char from[20];
	char to[20];
	int dist;
};
 
struct stack bt_stack[100];

struct FL flight[MAX];

int flight_pos = 0;
int find_pos = 0;
int tos = 0;


void assert_flight(char *from, char *to, int dist)
{
	if (flight_pos < MAX)
	{
		strcpy(flight[flight_pos].from, from);
		strcpy(flight[flight_pos].to, to);
		flight[flight_pos].distance = dist;
		flight[flight_pos].skip = 0;
		flight_pos++;
	}
	else { printf("Flight Database full.\n"); }
}

int match(char *from, char *to) {
	register int t;

	for ( t = flight_pos - 1; t > -1; t--) {
		if (!strcmp(flight[t].from, from) && !strcmp(flight[t].to, to))
			return flight[t].distance;
	}
	return 0;
}

int find(char *from, char *anywhere)
{
	find_pos = 0;
	while (find_pos<flight_pos)
	{
		if (!strcmp(flight[find_pos].from, from) && !flight[find_pos].skip)
		{
			strcpy(anywhere, flight[find_pos].to);
			flight[find_pos].skip = 1;
			return flight[find_pos].distance;
		}
		find_pos++;
	}
	return 0;
}

void setup(void) {
	assert_flight((char*)"New York", (char *)"Chicago", 1000);
	assert_flight((char*)"Chicago", (char *)"Denver", 1000);
	assert_flight((char*)"New York", (char *)"Toronto", 800);
	assert_flight((char*)"New York", (char *)"Denver", 1900);
	assert_flight((char*)"Toronto", (char *)"Calgary", 1500);
	assert_flight((char*)"Toronto", (char *)"Los Angeles", 1800);
	assert_flight((char*)"Toronto", (char *)"Chicago", 500);
	assert_flight((char*)"Denver", (char *)"Urbana", 1000);
	assert_flight((char*)"Denver", (char *)"Houston", 1500);
	assert_flight((char*)"Houston", (char *)"Los Angeles", 1500);
	assert_flight((char*)"Denver", (char *)"Los Angeles", 1000);
}

void push(char *from,char*to,int dist)
{
	if (tos < MAX) {
		strcpy(bt_stack[tos].from, from);
		strcpy(bt_stack[tos].to, to);
		bt_stack[tos].dist = dist;
		tos++;
	}
	else { printf("Stack full"); }
}

void pop(char *from, char*to, int *dist)
{
	if (tos < MAX) {
		tos--;
		strcpy(from, bt_stack[tos].from);
		strcpy(to, bt_stack[tos].to);
		*dist = bt_stack[tos].dist;
	}
	else { printf("Stack underflow"); }
}

void isflight(char *from, char *to) 
{
	int d, dist;
	char anywhere[20];

	if (d = match(from, to)) {
		push(from, to, d);
		return;
	}
	if (dist = find(from, anywhere)) {
		push(from, to, dist);
		isflight(anywhere, to);
	}
	else if (tos > 0) {
		pop(from, to, &dist);
		isflight(from, to);
	}
}

void route(char *to) 
{
	int dist, t;

	dist = 0;
	t = 0;

	while (t < tos) 
	{
		printf("%s to ", bt_stack[t].from);
		dist += bt_stack[t].dist;
		t++;
	}
	printf("%s\n ", to);
	printf("Distance is %d.\n ", dist);
}


int main() 
{
	char from[20], to[20];
	setup();
	printf("From ?");
	gets_s(from);
	printf("To ?");
	gets_s(to);
	

	isflight(from, to);
	route(to);

	return 0;
}

/*
template <class flight> class stack {
	flight stck[MAX];
	int tos;
public:
	stack() {tos = 0;}

	void push(flight ob)
	{
		if (tos == MAX) {
			cout << "Stack is full.\n";
			return;
		}
		stck[tos] = ob;
		tos++;
	}

	flight pop()
	{
		if (tos == 0) {
			cout << "Stack is empty.\n";
			return 0;
		}
		tos--;
		return stck[tos];
	}
};
*/