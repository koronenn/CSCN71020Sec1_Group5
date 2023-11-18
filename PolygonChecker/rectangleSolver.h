#pragma once

int* GetRectangleIndexes(int*);
void ClassifyPoints(int*);
double dist(double x1, double y1, double x2, double y2);
void swap(int*, int*, int*, int*);

bool CalculateAnglesForPolygon(int*, double*);
double GetPerimeter(double*);
double GetArea(double*);

void PrintRectangle(bool, double, double);