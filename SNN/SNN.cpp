// SNN.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;
void PrintVector(vector<int> v);

int main()
{
	vector<int> y,x;
	const int bias = 2;
	const int m = 9;
	int length = 20;
	double w, b, loss=0, a, z, cost=0;
	double da, dz=0, dw=0, db=0, alpha = 0.01;
	int dummy;

	for (int i = 0; i < length; i++)
	{
		y.push_back(bias + i*m);
		x.push_back(i);
	}

	//PrintVector(y);

	length = y.size();

	w = -50;
	b = 50;//b is a random number


	for (int j = 0; j < 5000; j++)
	{
		dw = 0;
		db = 0;
		dz = 0;
		for (int i = 0; i < length; i++)
		{
			z = x[i] * w + b;
			loss = 0.5 * (z - y[i])*(z-y[i]);
			cost += loss;


			dz = (z - y[i]);
			dw += x[i] * dz;
			db += dz;

		}

		cost = cost / length;

		dw = dw / length;
		db = db / length;

		w = w - alpha * dw;
		b = b - alpha * db;
	}

	std::cout << "cost=" << cost << endl;
	std::cout << "w=" << w << "	b=" << b << endl << endl;

	cin >> dummy;

	return 0;
}

void PrintVector(vector<int> v)
{
	for (int e : v)
	{
		cout << e << endl;
	}
}

