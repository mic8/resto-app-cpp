#include "role.model.h"

void RoleModel::bindRoles() {
	this->roles.push_back(RoleModel::ADMIN);
	this->roles.push_back(RoleModel::WAITER);
}

void RoleModel::bindRoleLabels() {
	this->roleLabels.push_back("Admin");
	this->roleLabels.push_back("Waiter");
}

RoleModel::RoleModel() {
	this->bindRoles();
	this->bindRoleLabels();
}