/*
Description: Solving the Traveling Salesman Problem (TSP) with
Ant Colony Optimization.
Author: chmwang
Date: 2015/04/25
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

const int max_city_nums = 300;
int city_nums;  // city numbers
LOCATION cities[max_city_nums];  // city's location

const int max_ant_nums = max_city_nums/2;
int ant_nums;  // ant numbers
// tabu table, whether ant i visited city j
bool tabu[max_ant_nums][max_city_nums];

// ants' location(cityId) of each iteration
int location[max_ant_nums];
// ants' location information
int route[max_ant_nums][max_city_nums];
double L[max_ant_nums];
bool tour_edge[max_ant_nums][max_city_nums][max_city_nums];

// alpha beta are the relative importance of \
// pheromones and heuristic information, respectively
const int alpha = 5;
const int beta = 2;
// Q: a constant related to the quantity of trail laid \
// by ants as trail evaporation
const int Q = 88;
const double rho = 0.941;  // rho: trail persistence
const double tau0 = 10.0;  // tau0: initial value of tau

// the relative importance of the trail
double tau[max_city_nums][max_city_nums];
// the relative importance of the local benefit
double eta[max_city_nums][max_city_nums];
double dist[max_city_nums][max_city_nums];

void readin()
{
	FILE *read = NULL;
	char file_path[] = "E:\\zju\\salon\\st70.txt";
	if ((read = fopen(file_path, "r")) == NULL) exit(-1);
	fscanf(read, "%d", &city_nums);  // city numbers
	memset(cities, 0, sizeof(cities));
	for (int i = 0; i < city_nums; i++)  // each city's location
	{
		int ignore; LOCATION city;
		fscanf(read, "%d %d %d", &ignore, &city.x, &city.y);
		cities[i] = city;
	}
	return;
}

double dis(LOCATION city1, LOCATION city2)
{
	return sqrt(1.0*(city1.x-city2.x)*(city1.x-city2.x) + \
		(city1.y-city2.y)*(city1.y-city2.y));
}

void dist_eta()
{
	// calculate distance between two cities
	for (int i = 0; i < city_nums; i++) {
		for (int j = 0; j < city_nums; j++) {
			if (i != j) {
				dist[i][j] = dis(cities[i], cities[j]);
				// definition: eta = 1 / dist
				eta[i][j] = 1 / dist[i][j];
			}
		}
	}
	return;
}

void init_location()
{
	bool visit[max_city_nums];
	memset(visit, 0, sizeof(visit));
	memset(location, 0, sizeof(location));
	for (int i = 0; i < ant_nums; )
	{   
		// ants must be in the different cities at the beginning
		int id = rand() % city_nums;
		if (!visit[id])
		{
			visit[id] = true;
			location[i++] = id;
		}
	}
	return;
}

void init_route()
{
	// initialize tabu, route, tour_edge
	memset(tabu, 0, sizeof(tabu));
	memset(route, 0, sizeof(route));
	memset(tour_edge, 0, sizeof(tour_edge));
	memset(L, 0, sizeof(L));
	init_location();
	return;
}

void init()
{
	srand((unsigned)time(NULL));
	ant_nums = 30;

	// initialize tau
	memset(tau, 0, sizeof(tau));
	for (int i = 0; i < city_nums; i++)
		for (int j = 0; j < city_nums; j++)
			tau[i][j] = tau0;

	memset(dist, 0, sizeof(dist));
	memset(eta, 0, sizeof(eta));
	dist_eta();
	return;
}

double pos(int ant, int loc, int city)
{
	if (tabu[ant][city]) return 0.0;  // city has been in tabu table
	double above = pow(tau[loc][city],alpha) * pow(eta[loc][city],beta);
	double below = 0.0;
	// for all cities that are not in tabu table
	for (int i = 0; i < city_nums; i++)
		if (!tabu[ant][i])
			below += pow(tau[loc][i],alpha) * pow(eta[loc][i],beta);
	return above / below; 
}

void select(int ant, int loc)
{
	double p[max_city_nums];
	memset(p, 0, sizeof(p));
	p[0] = pos(ant, loc, 0);
	// calculate probability of ant 'ant' at city 'loc' \
	// goes to city i
	for (int i = 1; i < city_nums; i++)
		p[i] = p[i-1] + pos(ant, loc, i);

	int interval[max_city_nums];
	memset(interval, 0, sizeof(interval));
	for (int i = 0; i < city_nums; i++)
		interval[i+1] = p[i] * RAND_MAX;
	
	// randomly select a city according the probability
	int r = rand() % RAND_MAX - 1;
	for (int i = 0; i < city_nums; i++)
	{
		if (r>=interval[i] && r<interval[i+1])
		{
			location[ant] = i;  // keep the next city
			break;
		}
	}
	return;
}

void update_info()
{
	double delta_tau[max_city_nums][max_city_nums];
	memset(delta_tau, 0, sizeof(delta_tau));
	double delta_sum = 0.0;
	for (int i = 0; i < city_nums; i++)
	{
		for (int j = 0; j < city_nums; j++)
		{
			// for all ants, whose tours cover city i and city j
			for (int k = 0; k < ant_nums; k++)
				if (tour_edge[k][i][j])
					delta_tau[i][j] += Q / L[k];
			// update pheromones
			tau[i][j] = rho*tau[i][j] + delta_tau[i][j];
		}
	}
	return;
}

void iteration()
{
	for (int iter = 0; iter < 1000; iter++)
	{
		init_route();
		for (int k = 0; k < ant_nums; k++)
		{
			for (int i = 0; i < city_nums-1; i++)
			{
				// update tabu table after select a city
				tabu[k][location[k]] = true;
				route[k][i] = location[k];
				// select next city
				select(k, location[k]);
				// update tour
				tour_edge[k][route[k][i]][location[k]] = true;
				// calculate tour length
				L[k] += dis(cities[route[k][i]], cities[location[k]]);
			}
			L[k] += dis(cities[location[k]], cities[route[k][0]]);
		}
		update_info();
	}
	return;
}

void print_route()
{
	int foo = 0x7fffffff;  // keep the minimum route
	for (int ant = 0; ant < ant_nums; ant++)
		if (L[ant] < foo) foo = L[ant];
	cout << foo << endl;
	return;
}

int main()
{
	readin();
	init();
	iteration();
	print_route();
	return 0;
}