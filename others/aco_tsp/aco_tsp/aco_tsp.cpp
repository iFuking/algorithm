/*
Description: Solving the Traveling Salesman Problem (TSP) with
Ant Colony Optimization.
Author: chmwang
Date: 2015/04/19
*/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
using namespace std;

typedef struct {
    int x, y;  // x-coordinate and y-coordinate
}LOCATION;
typedef struct {
    int id;             // city's id
    LOCATION location;  // city's location
}CITYINFO;

int city_nums;  // city numbers
CITYINFO *cities;  // cities' information

int ant_nums;  // ant numbers
// tabu table, whether ant i visited city j
bool **tabu;
// ants' location(cityId) of each iteration
int *location;

// alpha beta are the relative importance of \
// pheromones and heuristic information, respectively
const int alpha = 5, beta = 2;

// Q: a constant related to the quantity of trail laid \
// by ants as trail evaporation
const int Q = 88;
// rho: trail persistence
const double rho = 0.941;
// tau0: initial value of tau
const double tau0 = 10.0;

// the relative importance of the trail
double **tau;
// the relative importance of the local benefit
double **eta, **dist; 

void Readin(char *file_path)
{
    FILE *read = NULL;
	if ((read = fopen(file_path, "r")) == NULL) exit(-1);
	fscanf(read, "%d", &city_nums);  // city numbers
	cities = new CITYINFO[city_nums+1];
	for (int i = 0; i < city_nums; i++)  // each city's location
	{
		CITYINFO city;
		fscanf(read, "%d %d %d", &city.id, &city.location.x, &city.location.y);
		cities[city.id] = city;
	}
    return;
}

void Calculate_Distance()
{
	// build distance array dynamicly
	dist = new double*[city_nums+1];
	for (int i = 1; i <= city_nums; i++) {
		dist[i] = new double[city_nums+1];
	}

	// calculate distance between two cities
	for (int i = 1; i <= city_nums; i++) {
		for (int j = 1; j <= city_nums; j++) {
			dist[i][j] = sqrt(1.0*(cities[i].location.x-cities[j].location.x)* \
				(cities[i].location.x-cities[j].location.x) + \
				(cities[i].location.y-cities[j].location.y)* \
				(cities[i].location.y-cities[j].location.y));
		}
	}
	return;
}

void Initilization(char *ant_numbers)
{
	srand((unsigned)time(NULL));
	ant_nums = atoi(ant_numbers);

	// build tabu table dynamicly
	tabu = new bool*[ant_nums];
	for (int k = 0; k < ant_nums; k++) {
		tabu[k] = new bool[city_nums+1];
	}
	// initialize tabu table
	for (int k = 0; k < ant_nums; k++) {
		for (int i = 1; i <= city_nums; i++) {
			tabu[k][i] = false;
		}
	}

	bool *city_visited = new bool[city_nums+1];
	for (int i = 1; i <= city_nums; i++) {
		city_visited[i] = false;
	}
	location = new int[ant_nums];
	// ants must be in the different cities at the beginning
	for (int k = 0; k < ant_nums; )
	{
		int cityId = rand()%city_nums + 1;
		if (!city_visited[cityId])
		{
			city_visited[cityId] = true;
			location[k++] = cityId;
		}
	}

	// initialize **tau
	tau = new double*[city_nums+1];
	for (int i = 0; i <= city_nums; i++) {
		tau[i] = new double[city_nums+1];
	}
	for (int i = 1; i <= city_nums; i++) {
		for (int j = 1; j <= city_nums; j++) {
			tau[i][j] = tau0;
		}
	}

	// calculate distance between two cities (initialize **dist)
	Calculate_Distance();
	return;
}

double Distance(int cityId1, int cityId2)
{
	return dist[cityId1][cityId2];
}

double Eta(int cityId1, int cityId2)
{
	return 1.0 / Distance(cityId1, cityId2);
}

double Select_possibility(int antId, int cityId1, int cityId2)
{
	if (tabu[antId][cityId2]) return 0.0;  // city has been in tabu table
	double numerator = pow(tau[cityId1][cityId2], alpha) * pow(Eta(cityId1,cityId2), beta);
	double denominator = 0.0;
	// for all cities that are not in tabu table
	for (int i = 1; i <= city_nums; i++) {
		if (!tabu[antId][i]) {
			denominator += pow(tau[cityId1][i], alpha) * pow(Eta(cityId1,i), beta);
		}
	}
	return numerator / denominator;
}

// Ant 'antId' at city 'ant_location', return the cityId ant goes
void Select_Next_City(int antId, int ant_location)
{
	double *possibility = new double[city_nums+1];
	for (int i = 1; i <= city_nums; i++) {
		possibility[i] = Select_possibility(antId, ant_location, i);
	}
	//int *interval = new int[city_nums+1];
	return;
}

void Iteration(char *iterations)
{
	int iter = 0;  // iteration process
	while (iter++ < atoi(iterations)) {
		for (int k = 0; k < ant_nums; k++) {
			// for ant k, travel all cities
			for (int i = 1; i < city_nums; i++) {
				tabu[k][location[k]] = true;
				Select_Next_City(k, location[k]);
			}
		}
	}
	return;
}

int main(int argc, char *argv[])
{
    Readin(argv[1]);
	Initilization(argv[2]);
	Iteration(argv[3]);
	return 0;
}
