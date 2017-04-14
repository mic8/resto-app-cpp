#include "role.model.h"

void RoleModel::bindRoles() {
	this->roles.push_back(RoleModel::ADMIN);
	this->roles.push_back(RoleModel::WAITER);
	this->roles.push_back(RoleModel::CUSTOMER);
}

void RoleModel::bindRoleLabels() {
	this->roleLabels.push_back("Admin");
	this->roleLabels.push_back("Waiter");
	this->roleLabels.push_back("Customer");
}

RoleModel::RoleModel() {
	this->bindRoles();
	this->bindRoleLabels();
}