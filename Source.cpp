#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
struct Drone {
	string name;
	int energy;
	int power;
	int hp;
};
void ShowDrone(const Drone& drone) {
	cout << drone.name;
	cout << " | Energy: ";
	cout << drone.energy;
	cout << "%";
	cout << drone.hp;
	cout << " | HP: ";
	cout << drone.power;
	cout << " | Power: " << endl;
}
void AttackDrone(Drone& attacker, Drone& target) {
	cout << attacker.name
		<< " Attacks "
		<< target.name
		<< endl;

	target.hp -= attacker.power;
	if (target.hp <= 0) {
		target.hp = 0;
	}
	else {
		cout << target.name
			<< " | HP: "
			<< target.hp
			<< endl;
	}
	int damage;
	int attackerIndex;
	int targetIndex;

	cout << "Enter damage to drone: ";
	cin >> damage;

	AttackDrone(drones[attackerIndex], drones[targetIndex]);
}
void DestroyedDrones(vector<Drone>& drones) {
	for (int i = 0; i < drones.size(); i++) {
		if (drones[i].hp <= 0) {
			cout << drones[i].name;
			cout << "Drone destroyed!" << endl;
			drones.erase(drones.begin() + i);
			i--;
		}
	}
}
void RechargeDrone(int& battery, int recharge) {
	battery = 100;
	recharge = 5;
	if (battery < recharge) {
		cout << "Not enough battery!" << endl;
	}
	else {
		cout << "Battery used!" << endl;
		cout << "Battery left: " << battery << endl;
		cout << "Recharge left: " << recharge << endl;
		battery += 25;
		recharge--;
	}
}
void RepairDrone(int& repair, int& hp) {
	hp = 100;
	repair = 5;
	if (repair <= 0) {
		cout << "You don't have any repair!" << endl;
	}
	else if (repair >= 0) {
		cout << "You used repair!" << endl;
		cout << "Repair left: " << repair << endl;
		hp += 25;
		repair--;
	}
}
void FindWeakDrone(const Drone &drone) {
	if (drone.hp < 30) {
		cout << drone.name;
		cout << "Drone is weak!" << endl;
	}
}
void SaveDrone(const vector<Drone>& drones) {
	ofstream file("drones.txt");
	if (file.is_open()) {
		for (int i = 0; i < drones.size(); i++) {
			file << drones[i].name << endl;
			file << drones[i].energy << endl;
			file << drones[i].hp << endl;
			file << drones[i].power << endl;
		}
		file.close();
		cout << "Drones saved!" << endl;
	}
	else {
		cout << "File don't found" << endl;
	}
}
void LoadDrone(vector<Drone>& drones) {
	ifstream file("drones.txt");
	if (file.is_open()) {
		Drone temp;
		while (file >> temp.name
			>> temp.energy
			>> temp.hp
			>> temp.power) {
			drones.push_back(temp);
		}
		file.close();
		cout << "Drones loaded!" << endl;
	}
	else {
		cout << "File don't found!" << endl;
	}
	
}
void ShowDrones(const vector<Drone>& drones) {
	for (int i = 0; i < drones.size(); i++) {
		cout << drones[i].name;
		cout << " | Energy: ";
		cout << drones[i].energy;
		cout << "%";
		cout << drones[i].hp;
		cout << " | HP: ";
		cout << drones[i].power;
		cout << " | Power: " << endl;
	}
}
int main() {
	vector<Drone> drones;
	drones.push_back({ "Scout", 75, 100, 35 }); // first: Energy, second: HP, Third: Power
	drones.push_back({ "Hunter", 100, 100, 55 }); // first: Energy, second: HP, Third: Power
	drones.push_back({ "Falcon", 55, 100, 25 }); // first: Energy, second: HP, Third: Power
	drones.push_back({ "Cargo", 65, 100, 30 }); // first: Energy, second: HP, Third: Power
	drones.push_back({ "Mini", 15, 125, 10 }); // first: Energy, second: HP, Third: Power
	for (int i = 0; i < drones.size(); i++) {
		ShowDrone(drones[i]);
	}
	for (int i = 0; i < drones.size(); i++) {
		FindWeakDrone(drones[i]);
	}
	int power = 0;
	int repair = 5;
	int hp = 100;
	int choice;
	int battery = 100;
	int recharge = 5;

	while (true) {

		cout << "\n==MENU==\n";
		cout << "1. Show Drones\n";
		cout << "2. Attack\n";
		cout << "3. Recharge drone\n";
		cout << "4. Repair drone\n";
		cout << "5. Save drone\n";
		cout << "6. Load drone\n";
		cout << "7. Exit\n";
		cout << "Choose: ";
		cin >> choice;

		if (choice == 1) {
			ShowDrones(drones);
		}
		if (choice == 2) {

			int attackerIndex;
			int targetIndex;

			ShowDrones(drones);

			cout << "Choose attacker: ";
			cin >> attackerIndex;

			cout << "Choose target: ";
			cin >> targetIndex;
			AttackDrone(drones[attackerIndex], drones[targetIndex]);
		}
		if (choice == 3) {
			RechargeDrone(battery, recharge);
		}
		if (choice == 4) {
			RepairDrone(repair, hp);
		}
		if (choice == 5) {
			cout << "You saved drones!" << endl;
			SaveDrone(drones);
		}
		if (choice == 6) {
			cout << "Drones loaded" << endl;
			LoadDrone(drones);
		}
		if (choice == 7) {
			cout << "Programm shut down" << endl;
			break;
		}
	}
	return 0;
}