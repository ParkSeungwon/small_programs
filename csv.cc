#include<vector>
#include<iostream>
#include<fstream>
#include<ctime>
#include<sstream>
using namespace std;

struct Taxi_data{
	struct tm pickup_tm, dropoff_tm;
	int passengers;
	int trip_time;
	float trip_distance;
	double pickup_lng, pickup_lat, dropoff_lng, dropoff_lat;
};

istream& operator>>(istream& i, struct tm& r) {
	char c;
	i >> r.tm_year; r.tm_year -= 1900; i >> c;
	i >> r.tm_mon; r.tm_mon--; i >> c;
	i >> r.tm_mday; r.tm_mday;
	i >> r.tm_hour; i >> c;
	i >> r.tm_min; i >> c;
	i >> r.tm_sec;
	return i;
}

int main()
{
	ifstream f("nyc_data.csv");
	Taxi_data d;
	vector<Taxi_data> v;
	string s;
	getline(f, s);
	int i = 0;
	while(getline(f, s, ',')) {
		if(i++ == 10) break;
		getline(f, s, ',');
		getline(f, s, ',');
		getline(f, s, ',');
		getline(f, s, ',');
		getline(f, s, ',');
		stringstream ss;
		cout << s;
		ss << s;
		ss >> d.pickup_tm;
		getline(f, s, ',');
		ss.clear();
		ss << s;
		ss >> d.dropoff_tm;
		getline(f, s, ',');
		d.passengers = stoi(s);
		
		getline(f, s, ',');
		d.trip_time = stoi(s);
		getline(f, s, ',');
		d.trip_distance = stof(s);
		getline(f, s, ',');
		try {
		d.pickup_lng = stod(s);
		getline(f, s, ',');
		d.pickup_lat = stod(s);
		getline(f, s, ',');
		d.dropoff_lng = stod(s);
		getline(f, s);
		d.dropoff_lat = stod(s);
		} catch(...) {}
		v.push_back(d);
	}

	for(auto& a : v) {
		cout << asctime(&a.pickup_tm) << '-' << asctime(&a.dropoff_tm);
		cout << ':' << a.passengers << "persons for " << a.trip_time;
		cout << "seconds" << endl;
	}
}
		


