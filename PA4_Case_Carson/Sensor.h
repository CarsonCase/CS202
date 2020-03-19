#pragma once
class Sensor
{
private:
	char m_type[256];
	float m_extraCost;
	static int gps_cnt;
	static int camera_cnt;
	static int lidar_cnt;
	static int radar_cnt;
	void myStringCopy(char destination[256], const char source[256]);
public:
	Sensor();
	Sensor(char* type);
	Sensor(Sensor &source);
	char* getType();
	float getExtraCost();
	void setType(char* type);
	void setExtraCost(float extraCost);
	int getGps();
	int getCamera();
	int getLidar();
	int getRadar();
	
};
bool operator==(Sensor a, Sensor b);

