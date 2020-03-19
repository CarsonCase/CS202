#include "Sensor.h"

int Sensor::gps_cnt=0;
int Sensor::camera_cnt=0;
int Sensor::lidar_cnt=0;
int Sensor::radar_cnt=0;
Sensor::Sensor() {
	myStringCopy(m_type,"none");
	float m_extracost = 0;
	gps_cnt++;
	camera_cnt++;
	lidar_cnt++;
	radar_cnt++;
}
Sensor::Sensor(char* type) {
	myStringCopy(m_type, type);
	gps_cnt++;
	camera_cnt++;
	lidar_cnt++;
	radar_cnt++;
}
Sensor::Sensor(Sensor &source) {
	//ONLY DOES TYPE FOR NOW
	myStringCopy(m_type, source.m_type);
	m_extraCost = source.m_extraCost;
	gps_cnt++;
	camera_cnt++;
	lidar_cnt++;
	radar_cnt++;
}

char* Sensor::getType() {
	return m_type;
}
float Sensor::getExtraCost() {
	return m_extraCost;
}
void Sensor::setExtraCost(float extraCost) {
	m_extraCost = extraCost;
}
void Sensor::setType(char* type) {
	myStringCopy(m_type, type);
}
void Sensor::myStringCopy(char destination[256], const char source[256]) {
	int count = 0;
	for (int i = 0; source[i] != '\0'; i++) {
		destination[i] = source[i];
		count = i;
	}
	destination[count + 1] = '\0';
}
int Sensor::getGps() {
	return gps_cnt;
}
int Sensor::getCamera() {
	return camera_cnt;
}
int Sensor::getLidar() {
	return lidar_cnt;
}
int Sensor::getRadar() {
	return radar_cnt;
}