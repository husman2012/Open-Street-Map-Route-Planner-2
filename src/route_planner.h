#ifndef ROUTE_PLANNER_H
#define ROUTE_PLANNER_H

#include <iostream>
#include <vector>
#include <string>
#include "route_model.h"


class RoutePlanner {
  public:
    RoutePlanner(RouteModel &model, float start_x, float start_y, float end_x, float end_y);
    float GetDistance() const {return distance;}
    // Add public variables or methods declarations here.
	void AStarSearch();
  
  private:
    // Add private variables or methods declarations here.
  	void AddNeighbors(RouteModel::Node *);
  	float CalculateHValue(RouteModel::Node *node);
  	std::vector<RouteModel::Node> ConstructFinalPath(RouteModel::Node *);
    RouteModel::Node *start_node;
  	RouteModel::Node *end_node;
    float distance;
    RouteModel &m_Model;
    std::vector<RouteModel::Node *> open_list;
    RouteModel::Node* NextNode();
};

#endif